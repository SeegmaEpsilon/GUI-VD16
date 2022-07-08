#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QTimer>
#include <QtGui/QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsView>
#include <qmath.h>

#include <windows.h>
#include <./src/udpserverthread.h>

#ifdef USE_LINE_OUT
#include <QtMultimedia>
#endif

#define ORGANIZATION_NAME "MICRONIX"
#define ORGANIZATION_DOMAIN "www.mx-omsk.ru"
#define APPLICATION_NAME "VD16_Service"

#define SETTINGS_TRAY "settings/tray"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();
  void Init();
  void PrintText(QTextEdit* textedit, QColor text_color, QString text);

private slots:

  void slotTimerTimeout(void);
  void slotMsgIzLan (QByteArray datagram, QString IPClien, quint16 PortClient);

  void testUdpFrameReceived(QByteArray datagram, QString IPClien, quint16 PortClient);

  void on_pushButton_5_clicked();

  void on_pushButton_calibration_clicked();

  void on_pushButton_poweroff_clicked();

  void on_pushButton_corr_clicked();

  void on_pushButton_RMSvalue_clicked();

  void on_pushButton_write_corr_clicked();

  void on_pushButton_console_clear_clicked();

  void on_pushButton_tracking_clicked();

  void on_pushButton_enable_widgets_clicked();

  void enable_all_widgets();

  void disable_all_widgets();

  void on_checkBoxSlowly_clicked();

  void on_checkBoxIgnore_clicked();

  void on_pushButton_save_settings_clicked();

  void on_pushButton_reset_settings_clicked();

private:
  QTimer timer;

  Ui::MainWindow* ui;
  UdpServerThread *servUdp;

  unsigned udp_console_index;
  unsigned udp_bridge_console_index;
};

#endif // MAINWINDOW_H
