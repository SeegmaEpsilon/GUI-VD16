#include "udpserverthread.h"
#include "udpserver.h"


UdpServerThread::UdpServerThread(quint16 _port_link, QObject *parent) :
  QThread(parent), port_link(_port_link)
{
}

UdpServerThread::~UdpServerThread()
{
  if (!isRunning())
    return;
  quit();
  wait();
}

void UdpServerThread::run()
{
  UdpServer server(port_link);//    server = new UdpServer(port); // так то же работает
  // транзит от соккета до главного MainWindow
  connect(&server, SIGNAL(sgMsgToGUI(QByteArray,QString,quint16)),
          this, SIGNAL(sgMsgToGUI(QByteArray,QString,quint16)));
  connect(this, SIGNAL(sgMsgToLan(QByteArray,QString,quint16)),
          &server, SLOT(slotMsgIzGUI(QByteArray,QString,quint16)));
  exec();
}

void UdpServerThread::doSendDatagram (QByteArray datagram, QString IPClient, quint16 portClient)
{
  emit sgMsgToLan(datagram, IPClient, portClient);
}

