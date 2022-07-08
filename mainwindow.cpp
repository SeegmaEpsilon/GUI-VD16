#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QMessageBox>
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
  QRegExp ipRegex ("^" + ipRange
                       + "\\." + ipRange
                       + "\\." + ipRange
                       + "\\." + ipRange + "$");
  QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
  ui->lineEdit_ip_tuts_test_1->setValidator(ipValidator);
  ui->lineEdit_ip_tuts_test_2->setValidator(ipValidator);
  ui->lineEdit_ip_tuts_test_3->setValidator(ipValidator);
  ui->lineEdit_ip_tuts_test_4->setValidator(ipValidator);
  ui->lineEdit_ip_tuts_test_5->setValidator(ipValidator);
  ui->lineEdit_ip_tuts_test_6->setValidator(ipValidator);
  ui->lineEdit_ip_tuts_test_7->setValidator(ipValidator);
  ui->lineEdit_ip_tuts_test_8->setValidator(ipValidator);
  ui->lineEdit_ip_calibration->setValidator(ipValidator);

  ui->lineEdit_RMSvalue->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{8}"), this));
  ui->lineEdit_calibration_value->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{8}"), this));

  ui->lineEdit_device_number1->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
  ui->lineEdit_device_number2->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
  ui->lineEdit_device_number3->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
  ui->lineEdit_device_number4->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
  ui->lineEdit_device_number5->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
  ui->lineEdit_device_number6->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
  ui->lineEdit_device_number7->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
  ui->lineEdit_device_number8->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));

  QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

  settings.beginGroup("Device_numbers");
  ui->lineEdit_device_number1->setText(settings.value("Device_number_1", "0001").toString());
  ui->lineEdit_device_number2->setText(settings.value("Device_number_2", "").toString());
  ui->lineEdit_device_number3->setText(settings.value("Device_number_3", "").toString());
  ui->lineEdit_device_number4->setText(settings.value("Device_number_4", "").toString());
  ui->lineEdit_device_number5->setText(settings.value("Device_number_5", "").toString());
  ui->lineEdit_device_number6->setText(settings.value("Device_number_6", "").toString());
  ui->lineEdit_device_number7->setText(settings.value("Device_number_7", "").toString());
  ui->lineEdit_device_number8->setText(settings.value("Device_number_8", "").toString());
  settings.endGroup();

  settings.beginGroup("Device_IPs");
  ui->lineEdit_ip_tuts_test_1->setText(settings.value("Device_IP_1", "192.168.1.21").toString());
  ui->lineEdit_ip_tuts_test_2->setText(settings.value("Device_IP_2", "").toString());
  ui->lineEdit_ip_tuts_test_3->setText(settings.value("Device_IP_3", "").toString());
  ui->lineEdit_ip_tuts_test_4->setText(settings.value("Device_IP_4", "").toString());
  ui->lineEdit_ip_tuts_test_5->setText(settings.value("Device_IP_5", "").toString());
  ui->lineEdit_ip_tuts_test_6->setText(settings.value("Device_IP_6", "").toString());
  ui->lineEdit_ip_tuts_test_7->setText(settings.value("Device_IP_7", "").toString());
  ui->lineEdit_ip_tuts_test_8->setText(settings.value("Device_IP_8", "").toString());
  settings.endGroup();

  settings.beginGroup("Device_sending_data");
  ui->spinBoxSec->setValue(settings.value("measure_time", "20").toInt());
  ui->delay_spin->setValue(settings.value("packets_interval", "30").toInt());
  ui->checkBox_nonstop->setChecked(settings.value("nonstop_mode", false).toBool());
  if(settings.value("sending_mode", true).toBool())
  {
    ui->checkBoxIgnore->setChecked(true);
    ui->checkBoxSlowly->setChecked(false);
  } else
  {
    ui->checkBoxIgnore->setChecked(false);
    ui->checkBoxSlowly->setChecked(true);
    ui->delay_spin->setEnabled(false);
  }
  settings.endGroup();

  settings.beginGroup("Device_calibration");
  ui->lineEdit_RMSvalue->setText(settings.value("RMS_value", "10.00").toString());
  ui->lineEdit_calibration_value->setText(settings.value("corr_value", "0.000800").toString());
  ui->lineEdit_ip_calibration->setText(settings.value("Device_IP_calibration", "192.168.1.21").toString());
  settings.endGroup();

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::slotMsgIzLan(QByteArray datagram, QString IPClient, quint16 PortClient)
{
  testUdpFrameReceived(datagram, IPClient, PortClient);
  //PrintUDPDatagram(udp_console_index++, &datagram, true);
}

void MainWindow::slotTimerTimeout(void)
{
  //QByteArray z;
  //this->doSendKssTone(0, z);
}

// выводим текстовую строку указанного цвета в textedit
void MainWindow::PrintText(QTextEdit *textedit, QColor text_color, QString text)
{
  textedit->setTextColor(text_color);
  textedit->append(text);  
}

// начальная инициализация
void MainWindow::Init()
{
  //
  ui->tabWidget->setCurrentIndex(0); 

  udp_console_index = 0;
  udp_bridge_console_index = 0;

  // UDP
  servUdp = new UdpServerThread(1024, this);
  servUdp->start();

  connect(servUdp, SIGNAL(sgMsgToGUI(QByteArray,QString,quint16)),
          this, SLOT(slotMsgIzLan(QByteArray,QString,quint16)));

  // Timer

  //timer.start(25);
  //connect(&timer, SIGNAL(timeout()), this,SLOT(slotTimerTimeout()));
}


void MainWindow::on_checkBoxSlowly_clicked()
{
    ui->delay_spin->setEnabled(false);
    ui->delay_spin->setValue(30);
}

void MainWindow::on_checkBoxIgnore_clicked()
{
    ui->delay_spin->setEnabled(true);
}

void MainWindow::on_pushButton_console_clear_clicked()
{
    ui->testConsole->clear();
}

void MainWindow::on_pushButton_tracking_clicked()
{
    QTextCursor cursor = ui->testConsole->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->testConsole->setTextCursor(cursor);
}



void MainWindow::on_pushButton_save_settings_clicked()
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

    settings.beginGroup("Device_numbers");
    settings.setValue("Device_number_1", ui->lineEdit_device_number1->text());
    settings.setValue("Device_number_2", ui->lineEdit_device_number2->text());
    settings.setValue("Device_number_3", ui->lineEdit_device_number3->text());
    settings.setValue("Device_number_4", ui->lineEdit_device_number4->text());
    settings.setValue("Device_number_5", ui->lineEdit_device_number5->text());
    settings.setValue("Device_number_6", ui->lineEdit_device_number6->text());
    settings.setValue("Device_number_7", ui->lineEdit_device_number7->text());
    settings.setValue("Device_number_8", ui->lineEdit_device_number8->text());
    settings.endGroup();

    settings.beginGroup("Device_IPs");
    settings.setValue("Device_IP_1", ui->lineEdit_ip_tuts_test_1->text());
    settings.setValue("Device_IP_2", ui->lineEdit_ip_tuts_test_2->text());
    settings.setValue("Device_IP_3", ui->lineEdit_ip_tuts_test_3->text());
    settings.setValue("Device_IP_4", ui->lineEdit_ip_tuts_test_4->text());
    settings.setValue("Device_IP_5", ui->lineEdit_ip_tuts_test_5->text());
    settings.setValue("Device_IP_6", ui->lineEdit_ip_tuts_test_6->text());
    settings.setValue("Device_IP_7", ui->lineEdit_ip_tuts_test_7->text());
    settings.setValue("Device_IP_8", ui->lineEdit_ip_tuts_test_8->text());
    settings.endGroup();

    settings.beginGroup("Device_sending_data");
    settings.setValue("measure_time", ui->spinBoxSec->text());
    settings.setValue("packets_interval", ui->delay_spin->text());
    settings.setValue("sending_mode", ui->checkBoxIgnore->isChecked());
    settings.setValue("nonstop_mode", ui->checkBox_nonstop->isChecked());
    settings.endGroup();

    settings.beginGroup("Device_calibration");
    settings.setValue("RMS_value", ui->lineEdit_RMSvalue->text());
    settings.setValue("corr_value", ui->lineEdit_calibration_value->text());
    settings.setValue("Device_IP_calibration", ui->lineEdit_ip_calibration->text());
    settings.endGroup();

    settings.sync();

    QMessageBox::information(this,
                             trUtf8("Сохранение настроек"),
                             trUtf8("Настройки успешно сохранены"));
}

void MainWindow::on_pushButton_reset_settings_clicked()
{
    ui->lineEdit_ip_tuts_test_1->setText("192.168.1.21");
    ui->lineEdit_ip_tuts_test_2->setText("");
    ui->lineEdit_ip_tuts_test_3->setText("");
    ui->lineEdit_ip_tuts_test_4->setText("");
    ui->lineEdit_ip_tuts_test_5->setText("");
    ui->lineEdit_ip_tuts_test_6->setText("");
    ui->lineEdit_ip_tuts_test_7->setText("");
    ui->lineEdit_ip_tuts_test_8->setText("");

    ui->lineEdit_device_number1->setText("0001");
    ui->lineEdit_device_number2->setText("");
    ui->lineEdit_device_number3->setText("");
    ui->lineEdit_device_number4->setText("");
    ui->lineEdit_device_number5->setText("");
    ui->lineEdit_device_number6->setText("");
    ui->lineEdit_device_number7->setText("");
    ui->lineEdit_device_number8->setText("");

    ui->spinBoxSec->setValue(20);
    ui->checkBoxSlowly->setChecked(false);
    ui->checkBoxIgnore->setChecked(true);
    ui->delay_spin->setEnabled(true);
    ui->delay_spin->setValue(30);
    ui->checkBox_nonstop->setChecked(false);

    ui->lineEdit_RMSvalue->setText("10.00");
    ui->lineEdit_calibration_value->setText("0.000800");
    ui->lineEdit_ip_calibration->setText("192.168.1.21");
    ui->lineEdit_password->setText("");

    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

    settings.beginGroup("Device_numbers");
    settings.setValue("Device_number_1", ui->lineEdit_device_number1->text());
    settings.setValue("Device_number_2", ui->lineEdit_device_number2->text());
    settings.setValue("Device_number_3", ui->lineEdit_device_number3->text());
    settings.setValue("Device_number_4", ui->lineEdit_device_number4->text());
    settings.setValue("Device_number_5", ui->lineEdit_device_number5->text());
    settings.setValue("Device_number_6", ui->lineEdit_device_number6->text());
    settings.setValue("Device_number_7", ui->lineEdit_device_number7->text());
    settings.setValue("Device_number_8", ui->lineEdit_device_number8->text());
    settings.endGroup();

    settings.beginGroup("Device_IPs");
    settings.setValue("Device_IP_1", ui->lineEdit_ip_tuts_test_1->text());
    settings.setValue("Device_IP_2", ui->lineEdit_ip_tuts_test_2->text());
    settings.setValue("Device_IP_3", ui->lineEdit_ip_tuts_test_3->text());
    settings.setValue("Device_IP_4", ui->lineEdit_ip_tuts_test_4->text());
    settings.setValue("Device_IP_5", ui->lineEdit_ip_tuts_test_5->text());
    settings.setValue("Device_IP_6", ui->lineEdit_ip_tuts_test_6->text());
    settings.setValue("Device_IP_7", ui->lineEdit_ip_tuts_test_7->text());
    settings.setValue("Device_IP_8", ui->lineEdit_ip_tuts_test_8->text());
    settings.endGroup();

    settings.beginGroup("Device_sending_data");
    settings.setValue("measure_time", ui->spinBoxSec->text());
    settings.setValue("packets_interval", ui->delay_spin->text());
    settings.setValue("sending_mode", ui->checkBoxIgnore->isChecked());
    settings.setValue("nonstop_mode", ui->checkBox_nonstop->isChecked());
    settings.endGroup();

    settings.beginGroup("Device_calibration");
    settings.setValue("RMS_value", ui->lineEdit_RMSvalue->text());
    settings.setValue("corr_value", ui->lineEdit_calibration_value->text());
    settings.setValue("Device_IP_calibration", ui->lineEdit_ip_calibration->text());
    settings.endGroup();

    settings.sync();

    QMessageBox::information(this,
                             trUtf8("Сброс настроек"),
                             trUtf8("Настройки успешно сброшены"));

}
