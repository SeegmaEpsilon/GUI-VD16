#include "tu_test.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTime>

#define ADC_COUNT_SAMPLE_MAX 1344000
#define ADC_COUNT_SAMPLE_UDP (ADC_COUNT_SAMPLE_MAX/2100) //640 sample
#define ADC_COUNT_UDP_PACKETS (2100)

QTime time;

uint16_t buffer[ADC_COUNT_UDP_PACKETS][ADC_COUNT_SAMPLE_UDP];
uint16_t timeout = 0;
uint8_t device_number = 0;              // ТЕКУЩИЙ ДАТЧИК В СЕТИ
uint8_t count_measures = 0;             // ТЕКУЩЕЕ ИЗМЕРЕНИЕ
uint8_t count_devices = 0;              // ОБЩЕЕ КОЛИЧЕСТВО ДАТЧИКОВ В СЕТИ
int counter = 0;                        // СЧЕТЧИК ДЛЯ ПРОВЕРКИ ПАКЕТОВ

void delay(int msdelay)                 // ЗАДЕРЖКА В РАБОТЕ ПРОГРАММЫ НА msdelay МИЛЛИСЕКУНД
{
    QTime dieTime = QTime::currentTime().addMSecs(msdelay);
    while (QTime::currentTime() < dieTime) QCoreApplication::processEvents();
}
void MainWindow::enable_all_widgets()   // ВКЛЮЧАЕТ ВСЕ ВИДЖЕТЫ ИНТЕРФЕЙСА
{
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_calibration->setEnabled(true);
    ui->pushButton_corr->setEnabled(true);
    ui->pushButton_poweroff->setEnabled(true);
    ui->pushButton_RMSvalue->setEnabled(true);
    ui->pushButton_write_corr->setEnabled(true);
    ui->checkBoxSlowly->setEnabled(true);
    ui->checkBoxIgnore->setEnabled(true);
    ui->spinBoxSec->setEnabled(true);
    //ui->delay_spin->setEnabled(true);
}
void MainWindow::disable_all_widgets()  // ВЫКЛЮЧАЕТ ВСЕ ВИДЖЕТЫ ИНТЕРФЕЙСА
{
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_calibration->setEnabled(false);
    ui->pushButton_corr->setEnabled(false);
    ui->pushButton_poweroff->setEnabled(false);
    ui->pushButton_RMSvalue->setEnabled(false);
    ui->pushButton_write_corr->setEnabled(false);
    ui->checkBoxSlowly->setEnabled(false);
    ui->checkBoxIgnore->setEnabled(false);
    ui->spinBoxSec->setEnabled(false);
    //ui->delay_spin->setEnabled(false);
}
bool doMakeFileDirect(char *file_name, int count_udp_pk) // ФУНКЦИЯ СОЗДАНИЯ ТЕКСТОВОГО ФАЙЛА
{
  QFile file;
  file.setFileName(QCoreApplication::applicationDirPath () +"/"+ file_name + ".txt");
  if (file.exists())
  {
    file.remove();
  }
  if (!file.open(QIODevice::Append))
  {
    qDebug() << "Error opening input file.";
    return false;
  }

  QString line;

  for (int i = 0; i < count_udp_pk; i++)
  {
    for (int j = 0; j < ADC_COUNT_SAMPLE_UDP; j+=10)
    {
      line.clear();
      for(int k = 0; k < 10; k++)
      {
        line.append(QString(" %1\n").arg(buffer[i][j+k], 5, 10, QChar('0')).toUpper());
      }
      // line.append("\n");
      file.write(line.toLatin1());
    }
  }
  file.close();

  return true;
}

void MainWindow::testUdpFrameReceived(QByteArray datagram, QString IPClien, quint16 PortClient)
{
  QByteArray qb_buffer;
  qb_buffer.resize(5);

  QLineEdit* entries[] = {ui->lineEdit_ip_tuts_test_1, ui->lineEdit_ip_tuts_test_2,ui->lineEdit_ip_tuts_test_3, ui->lineEdit_ip_tuts_test_4,
                         ui->lineEdit_ip_tuts_test_5, ui->lineEdit_ip_tuts_test_6, ui->lineEdit_ip_tuts_test_7, ui->lineEdit_ip_tuts_test_8};


  if (datagram.size() == 2 && datagram.data()[0] == 1)      // ОТВЕТ -> ПРОИЗОШЕЛ СТАРТ ИЗМЕРЕНИЙ
  {
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> измерения начаты ") + QString(" %1 c").arg((uint8_t)datagram.data()[1]));
    timeout = 1000*21;
  }
  else if (datagram.size() == 2 && datagram.data()[0] == 2) // ОТВЕТ -> ИЗМЕРЕНИЯ ОКОНЧЕНЫ
  {
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> измерения закончены"));
    timeout = 1000;

    counter = 1;
    qb_buffer.resize(5);
    qb_buffer.data()[0] = 3;
    if (ui->checkBoxSlowly->isChecked() == true) // РЕЖИМ РАБОТЫ С ПРОВЕРКОЙ ПАКЕТОВ
    {
      qb_buffer.data()[1] = counter & 0xFF;
      qb_buffer.data()[2] = (counter & 0xFF00) >> 8;
    }
    else                                         // РЕЖИМ РАБОТЫ БЕЗ ПРОВЕРКИ ПАКЕТОВ
    {
      uint8_t delay = ui->delay_spin->text().toInt(); // Задержка между принятием пакетов в миллисекундах (изначально было 50 ms)
      qb_buffer.data()[1] = 0;
      qb_buffer.data()[2] = 0;
      qb_buffer.data()[3] = delay & 0xFF;
      qb_buffer.data()[4] = (delay & 0xFF00) >> 8;
    }

    count_measures++;   // УВЕЛИЧИВАЕМ СЧЕТЧИК ИЗМЕРЕНИЙ НА ОДИН
    if(count_measures == count_devices) {   // В СЛУЧАЕ, ЕСЛИ ВСЕ ИЗМЕРЕНИЯ ЗАКОНЧЕНЫ, ДАЕМ КОМАНДУ ПЕРВОМУ (!!!) ДАТЧИКУ НА ОТПРАВКУ ДАННЫХ
    delay(300);
    PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + entries[device_number]->text() + ": " + tr("Запрос -> получение результатов"));
    servUdp->doSendDatagram(qb_buffer, entries[0]->text(), 10000);
    }
  }
  else if (datagram.size() == (ADC_COUNT_SAMPLE_UDP*2 + 4) && counter <= ADC_COUNT_UDP_PACKETS) // ПРИЕМ ИЗМЕРЕНИЙ
  {
    timeout = 1000;

    uint16_t cur_pk = ((uint8_t)datagram.data()[1] << 8) | (uint8_t)datagram.data()[0];
    uint16_t max_pk = ((uint8_t)datagram.data()[3] << 8) | (uint8_t)datagram.data()[2];    

    if (counter != cur_pk && ui->checkBoxIgnore->isChecked() == false) // ПРОВЕРКА СЧЕТЧИКА ПАКЕТОВ
    {
      PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ошибка счетчика пакетов!!!"));
      if (ui->checkBoxSlowly->isChecked() == false)
      {
        enable_all_widgets();
        timeout = 0;
        counter = 0;
        return;
      }
      else
      {
        qb_buffer.data()[0] = 3;
        qb_buffer.data()[1] = counter & 0xFF;
        qb_buffer.data()[2] = (counter & 0xFF00) >> 8;
        servUdp->doSendDatagram(qb_buffer, entries[device_number]->text(), 10000);
        return;
      }
    }
    memcpy(buffer[cur_pk-1], datagram.data()+4, datagram.size()-4);

    if (cur_pk > 1)
    {
      QTextCursor cursor = ui->testConsole->textCursor();
      cursor.movePosition(QTextCursor::End);
      cursor.select(QTextCursor::LineUnderCursor);
      cursor.removeSelectedText();
      cursor.deletePreviousChar();
      ui->testConsole->setTextCursor(cursor);
    }

    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> получен пакет ") + QString(" %1/%2").arg(cur_pk).arg(max_pk));

    if (cur_pk == max_pk)
    {
      PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> буфер пуст"));
      PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Данные записаны в файл ") + IPClien + ".txt");
      timeout = 0;
      counter = 0;
      doMakeFileDirect(IPClien.toLatin1().data(), max_pk); // Запись данных в текстовый файл

      if(ui->checkBox_nonstop->isChecked() == true)        // Бесконечный запрос данных
      {
          delay(200);
          QByteArray qb_buffer;
          qb_buffer.resize(3);

          qb_buffer.data()[0] = 0x01;
          qb_buffer.data()[1] = ui->spinBoxSec->text().toInt() & 0xFF;
          qb_buffer.data()[2] = 0;

          servUdp->doSendDatagram(qb_buffer, entries[0]->text(), 10000);
      }

      qb_buffer.resize(5);
      qb_buffer.data()[0] = 3;
      if (ui->checkBoxSlowly->isChecked() == true) // РЕЖИМ РАБОТЫ С ПРОВЕРКОЙ ПАКЕТОВ
      {
        qb_buffer.data()[1] = counter & 0xFF;
        qb_buffer.data()[2] = (counter & 0xFF00) >> 8;
      }
      else                                         // РЕЖИМ РАБОТЫ БЕЗ ПРОВЕРКИ ПАКЕТОВ
      {
        uint8_t delay = ui->delay_spin->text().toInt(); // Задержка между принятием пакетов в миллисекундах (изначально было 50 ms)
        qb_buffer.data()[1] = 0;
        qb_buffer.data()[2] = 0;
        qb_buffer.data()[3] = delay & 0xFF;
        qb_buffer.data()[4] = (delay & 0xFF00) >> 8;
      }

      delay(1000);
      device_number++;  // УВЕЛИЧИВАЕМ НОМЕР ТЕКУЩЕГО ДАТЧИКА НА ОДИН


      if(device_number == count_devices)
      {
          enable_all_widgets();
          device_number = 0;
          count_devices = 0;
          count_measures = 0;
          counter = 0;
          timeout = 0;
          return;
      }

      PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + entries[device_number]->text() + ": " + tr("Запрос -> получение результатов"));
      servUdp->doSendDatagram(qb_buffer, entries[device_number]->text(), 10000);

      return;
    }

    counter ++;
    if (ui->checkBoxSlowly->isChecked() == true)
    {
      qb_buffer.data()[0] = 3;      
      qb_buffer.data()[1] = counter & 0xFF;
      qb_buffer.data()[2] = (counter & 0xFF00) >> 8;
      servUdp->doSendDatagram(qb_buffer, entries[device_number]->text(), 10000);
    }
  }

  else if (datagram.size() == 2 && (uint8_t)datagram.data()[0] == 4)    // ЗАПУСК КАЛИБРОВКИ
  {
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> калибровка начата"));
    counter = 0;
    timeout = 0;
  }
  else if (datagram.size() == 5 && (uint8_t)datagram.data()[0] == 5)    // КАЛИБРОВКА ПРОШЛА УСПЕШНО
  {
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> калибровка закончена"));
    float coef = 0.0;
    char buf_coef[4];
    buf_coef[0]=datagram.data()[1];
    buf_coef[1]=datagram.data()[2];
    buf_coef[2]=datagram.data()[3];
    buf_coef[3]=datagram.data()[4];
    memcpy(&coef, buf_coef, 4);
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> корректирующий коэффициент: ") + QString(" %1").arg(QString::number(coef, 'f', 8)));
    ui->lineEdit_calibration_value->setText(QString::number(coef, 'f', 8));
    enable_all_widgets();
    counter = 0;
    timeout = 0;
  }
  else if (datagram.size() == 5 && (uint8_t)datagram.data()[0] == 8)    // ПРИШЕЛ КОРРЕКТИРУЮЩИЙ КОЭФФИЦИЕНТ
  {
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> коэффициент получен"));
    float coef = 0.0;
    char buf_coef[4];
    buf_coef[0]=datagram.data()[1];
    buf_coef[1]=datagram.data()[2];
    buf_coef[2]=datagram.data()[3];
    buf_coef[3]=datagram.data()[4];
    memcpy(&coef, buf_coef, 4);
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> корректирующий коэффициент: ") + QString(" %1").arg(QString::number(coef, 'f', 8)));
    ui->lineEdit_calibration_value->setText(QString::number(coef, 'f', 8));
    enable_all_widgets();
    counter = 0;
    timeout = 0;
  }
  else if (datagram.size() == 5 && (uint8_t)datagram.data()[0] == 14)   // КОРРЕКТИРУЮЩИЙ КОЭФФИЦИЕНТ ЗАПИСАН В ДАТЧИК
  {
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> коэффициент записан в датчик"));
    float coef = 0.0;
    char buf_coef[4];
    buf_coef[0]=datagram.data()[1];
    buf_coef[1]=datagram.data()[2];
    buf_coef[2]=datagram.data()[3];
    buf_coef[3]=datagram.data()[4];
    memcpy(&coef, buf_coef, 4);
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> текущий корректирующий коэффициент: ") + QString(" %1").arg(QString::number(coef, 'f', 8)));
    ui->lineEdit_calibration_value->setText(QString::number(coef, 'f', 8));
    enable_all_widgets();
    counter = 0;
    timeout = 0;
  }
  else if (datagram.size() == 5 && (uint8_t)datagram.data()[0] == 10)   // ПРИШЛО СКЗ
  {
    QLineEdit* entries[] = { ui->lineEdit_ip_tuts_test_1, ui->lineEdit_ip_tuts_test_2,ui->lineEdit_ip_tuts_test_3, ui->lineEdit_ip_tuts_test_4,
                             ui->lineEdit_ip_tuts_test_5, ui->lineEdit_ip_tuts_test_6, ui->lineEdit_ip_tuts_test_7, ui->lineEdit_ip_tuts_test_8};
    float RMSvalue = 0.0;
    char buf_RMSvalue[4];
    buf_RMSvalue[0]=datagram.data()[1];
    buf_RMSvalue[1]=datagram.data()[2];
    buf_RMSvalue[2]=datagram.data()[3];
    buf_RMSvalue[3]=datagram.data()[4];
    memcpy(&RMSvalue, buf_RMSvalue, 4);
    PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> СКЗ: ") + QString(" %1").arg(QString::number(RMSvalue, 'f', 8)) + tr("   м/с^2"));
    ui->lineEdit_RMSvalue->setText(QString::number(RMSvalue, 'f', 8));
    enable_all_widgets();
    counter = 0;
    timeout = 0;

    if (ui->checkBox_nonstop->isChecked() == true)
    {
        delay(200);
        QByteArray qb_buffer;
        qb_buffer.resize(2);

        qb_buffer.data()[0] = 0x09;
        qb_buffer.data()[1] = ui->spinBoxSec->text().toInt() & 0xFF;

        for(int i = 0; i < 8; i++)
        {
            if(!entries[i]->text().isEmpty())
            {
                delay(100);
                servUdp->doSendDatagram(qb_buffer, entries[i]->text(), 10000);
            }
        }
    }
  }
  else if (datagram.size() == 1 && (uint8_t)datagram.data()[0] == 12)   // УСТРОЙСТВО ВОШЛО В РЕЖИМ ГИБЕРНАЦИИ
  {
    PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> устройство отключено"));
    enable_all_widgets();
    counter = 0;
    timeout = 0;
  }
  else if (datagram.size() == 2 && (uint8_t)datagram.data()[0] == 251)  // ФОРМАТИРОВАНИЕ SPIFFS (НЕ ТРОГАТЬ!)
  {
    if (datagram.data()[1] == 1)
      PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> форматирование начато"));
    else if (datagram.data()[1] == 2)
      PrintText(ui->testConsole, Qt::darkGreen, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> форматирование закончено"));
    enable_all_widgets();
    counter = 0;
    timeout = 0;
  }
  else if (datagram.size() == 2 && (uint8_t)datagram.data()[0] == 6)    // НЕВЕРНЫЙ ПАРОЛЬ
  {
    PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> неверный пароль"));
    enable_all_widgets();
    counter = 0;
    timeout = 0;
  }
  else if (datagram.size() == 2 && (uint8_t)datagram.data()[0] == 0)    // ПРИНЯТА НЕВЕРНАЯ КОМАНДА
  {
    PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + IPClien + ": " + tr("Ответ -> не верная команда"));
    enable_all_widgets();
    counter = 0;
    timeout = 0;
  }
}

void MainWindow::on_pushButton_5_clicked()              // ФУНКЦИЯ ЗАПРОСА ДАННЫХ
{
  trying_again:
  QByteArray qb_buffer;
  qb_buffer.resize(3);

  disable_all_widgets();
  //ui->testConsole->clear();

  qb_buffer.data()[0] = 0x01;
  qb_buffer.data()[1] = ui->spinBoxSec->text().toInt() & 0xFF;
  qb_buffer.data()[2] = 0;

  QLineEdit* entries[] = { ui->lineEdit_ip_tuts_test_1, ui->lineEdit_ip_tuts_test_2,ui->lineEdit_ip_tuts_test_3, ui->lineEdit_ip_tuts_test_4,
                         ui->lineEdit_ip_tuts_test_5, ui->lineEdit_ip_tuts_test_6, ui->lineEdit_ip_tuts_test_7, ui->lineEdit_ip_tuts_test_8};

  for(int i = 0; i < 8; i++)
  {
      if(!entries[i]->text().isEmpty())
      {
          delay(100);
          count_devices++;
          PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + entries[i]->text() + ": " + tr("Запрос -> старт измерений") );
          servUdp->doSendDatagram(qb_buffer, entries[i]->text(), 10000);
      }
  }

  PrintText(ui->testConsole, Qt::darkCyan, time.currentTime().toString("HH:mm:ss.zzz    |    ") + tr("Число опрашиваемых датчиков: ") + QString("%1").arg(count_devices));
  timeout = 1500; // 1500

  while(1)
  {
    Sleep(1);
    QApplication::processEvents();

    if (timeout)
    {
      timeout --;

      if (!timeout)
      {
        PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + ui->lineEdit_ip_tuts_test_1->text() + ": " + tr("ОШИБКА - нет ответа от ВД16!"));
        enable_all_widgets();
        device_number = 0;
        count_devices = 0;
        count_measures = 0;
        counter = 0;
        timeout = 0;
        if(ui->checkBox_nonstop->isChecked() == true) goto trying_again;
        return;
      }
    }
  }
}
void MainWindow::on_pushButton_calibration_clicked()    // ФУНКЦИЯ КАЛИБРОВКИ ДАТЧИКА ПО СКЗ
{

  QByteArray qb_buffer;
  qb_buffer.resize(7);

  int RMS_value_float_to_int = ui->lineEdit_RMSvalue->text().toDouble() * 1000000;

  disable_all_widgets();
  //ui->testConsole->clear();

  qb_buffer.data()[0] = 0x04;
  qb_buffer.data()[1] = ui->lineEdit_password->text().toInt() & 0xFF;
  qb_buffer.data()[2] = (ui->lineEdit_password->text().toInt() & 0xFF00) >> 8;
  qb_buffer.data()[3] = ui->spinBoxSec->text().toInt() & 0xFF;
  qb_buffer.data()[4] = (RMS_value_float_to_int & 0xFF);
  qb_buffer.data()[5] = (RMS_value_float_to_int & 0xFF00) >> 8;
  qb_buffer.data()[6] = (RMS_value_float_to_int & 0xFF0000) >> 16;
  qb_buffer.data()[7] = (RMS_value_float_to_int & 0xFF000000) >> 24;

  servUdp->doSendDatagram(qb_buffer, ui->lineEdit_ip_calibration->text(), 10000);
  timeout = 1500;

  PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + ui->lineEdit_ip_calibration->text() + ": " + tr("Запрос -> калибровка ВД16"));

  while(1)
  {
    Sleep(1);
    QApplication::processEvents();

    if (timeout)
    {
      timeout --;
      if (!timeout)
      {
        PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + tr("ОШИБКА - нет ответа от ВД16!"));
        enable_all_widgets();
        counter = 0;
        timeout = 0;
        return;
      }
    }
  }
}
void MainWindow::on_pushButton_corr_clicked()           // ФУНКЦИЯ ПОЛУЧЕНИЯ КОРРЕКТИРУЮЩЕГО КОЭФФИЦИЕНТА
{
    QByteArray qb_buffer;
    qb_buffer.resize(1);

    qb_buffer.data()[0] = 0x07;
    servUdp->doSendDatagram(qb_buffer, ui->lineEdit_ip_calibration->text(), 10000);
    timeout = 1500;
    PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + ui->lineEdit_ip_calibration->text() + ": " + tr("Запрос -> получение корректирующего коэффициента ВД16"));

    while(1)
    {
      Sleep(1);
      QApplication::processEvents();

      if (timeout)
      {
        timeout --;
        if (!timeout)
        {
          PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + tr("ОШИБКА - нет ответа от ВД16!"));
          enable_all_widgets();
          counter = 0;
          timeout = 0;
          return;
        }
      }
    }
}
void MainWindow::on_pushButton_write_corr_clicked()     // ФУНКЦИЯ ЗАПИСИ КОРРЕКТИРУЮЩЕГО КОЭФФИЦИЕНТА
{
  QByteArray qb_buffer;
  qb_buffer.resize(6);

  int corr_coef_float_to_int = ui->lineEdit_calibration_value->text().toDouble() * 1000000000;

  qb_buffer.data()[0] = 13;
  qb_buffer.data()[1] = ui->lineEdit_password->text().toInt() & 0xFF;
  qb_buffer.data()[2] = (ui->lineEdit_password->text().toInt() & 0xFF00) >> 8;
  qb_buffer.data()[3] = (corr_coef_float_to_int & 0xFF);
  qb_buffer.data()[4] = (corr_coef_float_to_int & 0xFF00) >> 8;
  qb_buffer.data()[5] = (corr_coef_float_to_int & 0xFF0000) >> 16;
  qb_buffer.data()[6] = (corr_coef_float_to_int & 0xFF000000) >> 24;

  servUdp->doSendDatagram(qb_buffer, ui->lineEdit_ip_calibration->text(), 10000);
  timeout = 1500;

  PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + ui->lineEdit_ip_calibration->text() + ": " + tr("Запрос -> запись корректирующего коэффициента в ВД16"));

  while(1)
  {
    Sleep(1);
    QApplication::processEvents();

    if (timeout)
    {
      timeout --;
      if (!timeout)
      {
        PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + tr("ОШИБКА - нет ответа от ВД16!"));
        enable_all_widgets();
        counter = 0;
        timeout = 0;
        return;
      }
    }
  }
}
void MainWindow::on_pushButton_RMSvalue_clicked()       // ФУНКЦИЯ ПОЛУЧЕНИЯ СКЗ
{
    trying_again:
    QByteArray qb_buffer;
    qb_buffer.resize(2);

    qb_buffer.data()[0] = 0x09;
    qb_buffer.data()[1] = ui->spinBoxSec->text().toInt() & 0xFF;
    timeout = 1500*21;
    disable_all_widgets();

    QLineEdit* entries[] = { ui->lineEdit_ip_tuts_test_1, ui->lineEdit_ip_tuts_test_2,ui->lineEdit_ip_tuts_test_3, ui->lineEdit_ip_tuts_test_4,
                           ui->lineEdit_ip_tuts_test_5, ui->lineEdit_ip_tuts_test_6, ui->lineEdit_ip_tuts_test_7, ui->lineEdit_ip_tuts_test_8};

    for(int i = 0; i < 8; i++)
    {
        if(!entries[i]->text().isEmpty())
        {
            delay(100);
            PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + entries[i]->text() + ": " + tr("Запрос -> получение СКЗ ВД16"));
            servUdp->doSendDatagram(qb_buffer, entries[i]->text(), 10000);
        }
    }

    while(1)
    {
      Sleep(1);
      QApplication::processEvents();

      if (timeout)
      {
        timeout --;
        if (!timeout)
        {
          PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + tr("ОШИБКА - нет ответа от ВД16!"));
          enable_all_widgets();
          counter = 0;
          timeout = 0;
          if(ui->checkBox_nonstop->isChecked() == true) goto trying_again;
          return;
        }
      }
    }
}
void MainWindow::on_pushButton_poweroff_clicked()       // ФУНКЦИЯ ОТКЛЮЧЕНИЯ ДАТЧИКА
{
    QByteArray qb_buffer;
    qb_buffer.resize(1);

    qb_buffer.data()[0] = 11;
    servUdp->doSendDatagram(qb_buffer, ui->lineEdit_ip_calibration->text(), 10000);
    timeout = 1500;
    PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + ui->lineEdit_ip_calibration->text() + ": " + tr("Запрос -> отключение ВД16"));

    while(1)
    {
      Sleep(1);
      QApplication::processEvents();

      if (timeout)
      {
        timeout --;
        if (!timeout)
        {
          PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + tr("ОШИБКА - нет ответа от ВД16!"));
          enable_all_widgets();
          counter = 0;
          timeout = 0;
          return;
        }
      }
    }
}

/*
void MainWindow::on_pushButton_clicked()                // ФУНКЦИЯ SPIFFS
{
  QByteArray qb_buffer;
  qb_buffer.resize(3);

  disable_all_widgets();
  qb_buffer.data()[0] = char(251);
  for (int i = 1; i < 3; i++)
  {
    qb_buffer.data()[i] = 27;
  }
  servUdp->doSendDatagram(qb_buffer, ui->lineEdit_ip_tuts_test_1->text(), 10000);
  timeout = 300000;

  PrintText(ui->testConsole, Qt::darkBlue, time.currentTime().toString("HH:mm:ss.zzz    |    ") + ui->lineEdit_ip_tuts_test_1->text() + ": " + tr("Запрос -> отформатировать SPIFFS"));

  while(1)
  {
    Sleep(1);
    QApplication::processEvents();

    if (timeout)
    {
      timeout --;
      if (!timeout)
      {
        PrintText(ui->testConsole, Qt::darkRed, time.currentTime().toString("HH:mm:ss.zzz    |    ") + tr("ОШИБКА - нет ответа от ВД16!"));
        enable_all_widgets();
        counter = 0;
        timeout = 0;
        return;
      }
    }
  }
}
*/

void MainWindow::on_pushButton_enable_widgets_clicked()
{
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_calibration->setEnabled(true);
    ui->pushButton_corr->setEnabled(true);
    ui->pushButton_poweroff->setEnabled(true);
    ui->pushButton_RMSvalue->setEnabled(true);
    ui->pushButton_write_corr->setEnabled(true);
    ui->checkBoxSlowly->setEnabled(true);
    ui->checkBoxIgnore->setEnabled(true);
    ui->spinBoxSec->setEnabled(true);
    //ui->delay_spin->setEnabled(true);
    device_number = 0;
    count_devices = 0;
    count_measures = 0;
    counter = 0;
    timeout = 0;
}
