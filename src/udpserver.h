#ifndef UDPSERVER_H
#define UDPSERVER_H


#include <QUdpSocket>


class UdpServer : public QUdpSocket
{
    Q_OBJECT
public:
    explicit UdpServer(quint16 _port_link, QObject *parent = 0);
    ~UdpServer();


private:    
    quint16 port_link;       // порт соккета    
    QUdpSocket *sok_link;    // соккет, который слушаем    
    void doSendDatagram (QByteArray datagram, QString IPClient, quint16 portClient);    
    
signals:
    void sgMsgToGUI(QByteArray datagram, QString IPClient, quint16 portClient);
    
public slots:
    void slotMsgIzLanLink();    
    void slotMsgIzGUI(QByteArray datagram, QString IPClient, quint16 portClient);


};

#endif // UDPSERVER_H
