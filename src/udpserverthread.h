#ifndef MYTHREAD_H
#define MYTHREAD_H

#include "udpserver.h"
#include <QThread>

class UdpServerThread : public QThread
{
    Q_OBJECT
public:
    explicit UdpServerThread(quint16 _port_link, QObject *parent = 0);
    ~UdpServerThread();
    void run();
    void doSendDatagram (QByteArray datagram, QString IPClient, quint16 portClient);
private:    
    quint16 port_link;  // порт соккета

signals:
    void sgMsgToGUI(QByteArray datagram, QString IPClient, quint16 portClient);
    void sgMsgToLan (QByteArray datagram, QString IPClient, quint16 portClient);        
};

#endif // MYTHREAD_H
