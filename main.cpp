#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);

    QApplication a(argc, argv);

    QTextCodec* tc = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(tc);
    QTextCodec::setCodecForCStrings(tc);
    QTextCodec::setCodecForLocale(tc);

    MainWindow w;
        w.Init();
		w.show();


    return a.exec();
}
