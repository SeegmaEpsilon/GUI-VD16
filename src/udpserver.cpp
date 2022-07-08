#include "udpserver.h"

UdpServer::UdpServer(quint16 _port_link, QObject *parent) :
  QUdpSocket(parent), port_link(_port_link)
  ,sok_link(new QUdpSocket)
{
  //    sok = new QUdpSocket(this);

  sok_link->bind(QHostAddress::Any, port_link); // принимаем  на port и любой IP этой ЭВМ
  connect (sok_link, SIGNAL(readyRead()), this, SLOT(slotMsgIzLanLink()) );
}
UdpServer::~UdpServer()
{
  delete sok_link;
}

void UdpServer::doSendDatagram(QByteArray datagram, QString IPClient, quint16 portClient )
{
  // будем делать еще 2 попытки в случае неудачной отправки
  qint32 result;
  for (quint8 i = 0; i < 3; i++)
  {
    result = sok_link->writeDatagram(datagram.data(), datagram.size(), QHostAddress(IPClient) , portClient);
    if (result == datagram.size())
      break;
  }
}

void UdpServer::slotMsgIzLanLink()
{
  QByteArray datagram;
  QHostAddress IPClient;
  quint16 portClient;
  while(sok_link->hasPendingDatagrams())
  {
    datagram.resize(sok_link->pendingDatagramSize());
    sok_link->readDatagram(datagram.data(), datagram.size(), &IPClient, &portClient);
  }
  emit sgMsgToGUI(datagram, IPClient.toString(), portClient);
}

void UdpServer::slotMsgIzGUI(QByteArray datagram, QString IPClient, quint16 portClient)
{
  doSendDatagram(datagram,  IPClient,  portClient);
}
