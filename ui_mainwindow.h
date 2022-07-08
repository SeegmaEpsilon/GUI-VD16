/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 3. Jun 17:10:11 2022
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QLabel *label_4;
    QSpinBox *delay_spin;
    QLineEdit *lineEdit_ip_tuts_test_1;
    QLabel *label_15;
    QLineEdit *lineEdit_RMSvalue;
    QLabel *label_3;
    QLineEdit *lineEdit_ip_tuts_test_2;
    QLineEdit *lineEdit_device_number2;
    QRadioButton *checkBoxSlowly;
    QLineEdit *lineEdit_ip_tuts_test_3;
    QLineEdit *lineEdit_device_number3;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label;
    QLabel *label_16;
    QLineEdit *lineEdit_ip_calibration;
    QLineEdit *lineEdit_ip_tuts_test_4;
    QLabel *label_14;
    QLineEdit *lineEdit_device_number4;
    QLabel *label_18;
    QSpinBox *spinBoxSec;
    QLineEdit *lineEdit_calibration_value;
    QRadioButton *checkBoxIgnore;
    QLineEdit *lineEdit_device_number5;
    QLabel *label_6;
    QLineEdit *lineEdit_device_number6;
    QPushButton *pushButton_poweroff;
    QTextEdit *testConsole;
    QPushButton *pushButton_console_clear;
    QPushButton *pushButton_enable_widgets;
    QLabel *label_13;
    QLineEdit *lineEdit_ip_tuts_test_7;
    QLineEdit *lineEdit_ip_tuts_test_5;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_ip_tuts_test_6;
    QLabel *label_10;
    QLabel *label_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_corr;
    QPushButton *pushButton_RMSvalue;
    QPushButton *pushButton_calibration;
    QPushButton *pushButton_write_corr;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *lineEdit_device_number7;
    QLineEdit *lineEdit_ip_tuts_test_8;
    QLineEdit *lineEdit_device_number8;
    QCheckBox *checkBox_nonstop;
    QPushButton *pushButton_save_settings;
    QPushButton *pushButton_reset_settings;
    QLineEdit *lineEdit_device_number1;
    QPushButton *pushButton_tracking;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(920, 600);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(880, 600));
        MainWindow->setMaximumSize(QSize(1681, 967));
        MainWindow->setBaseSize(QSize(880, 600));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setDocumentMode(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(10);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(10, 10, 10, 10);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 8, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 6, 0, 1, 1);

        delay_spin = new QSpinBox(tab);
        delay_spin->setObjectName(QString::fromUtf8("delay_spin"));
        delay_spin->setEnabled(true);
        delay_spin->setMinimum(5);
        delay_spin->setValue(30);

        gridLayout_6->addWidget(delay_spin, 8, 5, 1, 1);

        lineEdit_ip_tuts_test_1 = new QLineEdit(tab);
        lineEdit_ip_tuts_test_1->setObjectName(QString::fromUtf8("lineEdit_ip_tuts_test_1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_ip_tuts_test_1->sizePolicy().hasHeightForWidth());
        lineEdit_ip_tuts_test_1->setSizePolicy(sizePolicy2);
        lineEdit_ip_tuts_test_1->setMinimumSize(QSize(0, 0));
        lineEdit_ip_tuts_test_1->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_ip_tuts_test_1->setAutoFillBackground(false);

        gridLayout_6->addWidget(lineEdit_ip_tuts_test_1, 3, 2, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(label_15, 3, 4, 1, 1);

        lineEdit_RMSvalue = new QLineEdit(tab);
        lineEdit_RMSvalue->setObjectName(QString::fromUtf8("lineEdit_RMSvalue"));
        lineEdit_RMSvalue->setReadOnly(false);

        gridLayout_6->addWidget(lineEdit_RMSvalue, 3, 8, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_6->addWidget(label_3, 4, 0, 1, 1);

        lineEdit_ip_tuts_test_2 = new QLineEdit(tab);
        lineEdit_ip_tuts_test_2->setObjectName(QString::fromUtf8("lineEdit_ip_tuts_test_2"));
        lineEdit_ip_tuts_test_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(lineEdit_ip_tuts_test_2, 4, 2, 1, 1);

        lineEdit_device_number2 = new QLineEdit(tab);
        lineEdit_device_number2->setObjectName(QString::fromUtf8("lineEdit_device_number2"));
        lineEdit_device_number2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_device_number2, 4, 3, 1, 1);

        checkBoxSlowly = new QRadioButton(tab);
        checkBoxSlowly->setObjectName(QString::fromUtf8("checkBoxSlowly"));

        gridLayout_6->addWidget(checkBoxSlowly, 4, 4, 1, 1);

        lineEdit_ip_tuts_test_3 = new QLineEdit(tab);
        lineEdit_ip_tuts_test_3->setObjectName(QString::fromUtf8("lineEdit_ip_tuts_test_3"));
        lineEdit_ip_tuts_test_3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(lineEdit_ip_tuts_test_3, 6, 2, 1, 1);

        lineEdit_device_number3 = new QLineEdit(tab);
        lineEdit_device_number3->setObjectName(QString::fromUtf8("lineEdit_device_number3"));
        lineEdit_device_number3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_device_number3, 6, 3, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_12, 6, 7, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAutoFillBackground(false);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_11, 3, 7, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 3, 6, 1, 1);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 3, 0, 1, 1);

        lineEdit_ip_calibration = new QLineEdit(tab);
        lineEdit_ip_calibration->setObjectName(QString::fromUtf8("lineEdit_ip_calibration"));

        gridLayout_6->addWidget(lineEdit_ip_calibration, 6, 8, 1, 1);

        lineEdit_ip_tuts_test_4 = new QLineEdit(tab);
        lineEdit_ip_tuts_test_4->setObjectName(QString::fromUtf8("lineEdit_ip_tuts_test_4"));
        lineEdit_ip_tuts_test_4->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(lineEdit_ip_tuts_test_4, 8, 2, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_14, 4, 7, 1, 1);

        lineEdit_device_number4 = new QLineEdit(tab);
        lineEdit_device_number4->setObjectName(QString::fromUtf8("lineEdit_device_number4"));
        lineEdit_device_number4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_device_number4, 8, 3, 1, 1);

        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_18, 8, 4, 1, 1);

        spinBoxSec = new QSpinBox(tab);
        spinBoxSec->setObjectName(QString::fromUtf8("spinBoxSec"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(spinBoxSec->sizePolicy().hasHeightForWidth());
        spinBoxSec->setSizePolicy(sizePolicy4);
        spinBoxSec->setMinimum(1);
        spinBoxSec->setMaximum(21);
        spinBoxSec->setValue(20);

        gridLayout_6->addWidget(spinBoxSec, 3, 5, 1, 1);

        lineEdit_calibration_value = new QLineEdit(tab);
        lineEdit_calibration_value->setObjectName(QString::fromUtf8("lineEdit_calibration_value"));
        lineEdit_calibration_value->setReadOnly(false);

        gridLayout_6->addWidget(lineEdit_calibration_value, 4, 8, 1, 1);

        checkBoxIgnore = new QRadioButton(tab);
        checkBoxIgnore->setObjectName(QString::fromUtf8("checkBoxIgnore"));
        checkBoxIgnore->setChecked(true);

        gridLayout_6->addWidget(checkBoxIgnore, 6, 4, 1, 1);

        lineEdit_device_number5 = new QLineEdit(tab);
        lineEdit_device_number5->setObjectName(QString::fromUtf8("lineEdit_device_number5"));
        lineEdit_device_number5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_device_number5, 9, 3, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 9, 0, 1, 1);

        lineEdit_device_number6 = new QLineEdit(tab);
        lineEdit_device_number6->setObjectName(QString::fromUtf8("lineEdit_device_number6"));
        lineEdit_device_number6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_device_number6, 10, 3, 1, 1);

        pushButton_poweroff = new QPushButton(tab);
        pushButton_poweroff->setObjectName(QString::fromUtf8("pushButton_poweroff"));
        pushButton_poweroff->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_poweroff->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 181, 195);"));

        gridLayout_6->addWidget(pushButton_poweroff, 12, 8, 1, 1);

        testConsole = new QTextEdit(tab);
        testConsole->setObjectName(QString::fromUtf8("testConsole"));

        gridLayout_6->addWidget(testConsole, 14, 0, 1, 9);

        pushButton_console_clear = new QPushButton(tab);
        pushButton_console_clear->setObjectName(QString::fromUtf8("pushButton_console_clear"));

        gridLayout_6->addWidget(pushButton_console_clear, 15, 0, 1, 1);

        pushButton_enable_widgets = new QPushButton(tab);
        pushButton_enable_widgets->setObjectName(QString::fromUtf8("pushButton_enable_widgets"));

        gridLayout_6->addWidget(pushButton_enable_widgets, 15, 2, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setLayoutDirection(Qt::RightToLeft);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_13, 8, 7, 1, 1);

        lineEdit_ip_tuts_test_7 = new QLineEdit(tab);
        lineEdit_ip_tuts_test_7->setObjectName(QString::fromUtf8("lineEdit_ip_tuts_test_7"));
        lineEdit_ip_tuts_test_7->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(lineEdit_ip_tuts_test_7, 11, 2, 1, 1);

        lineEdit_ip_tuts_test_5 = new QLineEdit(tab);
        lineEdit_ip_tuts_test_5->setObjectName(QString::fromUtf8("lineEdit_ip_tuts_test_5"));
        lineEdit_ip_tuts_test_5->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(lineEdit_ip_tuts_test_5, 9, 2, 1, 1);

        lineEdit_password = new QLineEdit(tab);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setMaxLength(4);

        gridLayout_6->addWidget(lineEdit_password, 8, 8, 1, 1);

        lineEdit_ip_tuts_test_6 = new QLineEdit(tab);
        lineEdit_ip_tuts_test_6->setObjectName(QString::fromUtf8("lineEdit_ip_tuts_test_6"));
        lineEdit_ip_tuts_test_6->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(lineEdit_ip_tuts_test_6, 10, 2, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 8, 6, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_6->addWidget(label_8, 11, 0, 1, 1);

        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(pushButton_5, 11, 4, 2, 1);

        pushButton_corr = new QPushButton(tab);
        pushButton_corr->setObjectName(QString::fromUtf8("pushButton_corr"));

        gridLayout_6->addWidget(pushButton_corr, 9, 8, 1, 1);

        pushButton_RMSvalue = new QPushButton(tab);
        pushButton_RMSvalue->setObjectName(QString::fromUtf8("pushButton_RMSvalue"));

        gridLayout_6->addWidget(pushButton_RMSvalue, 10, 4, 1, 1);

        pushButton_calibration = new QPushButton(tab);
        pushButton_calibration->setObjectName(QString::fromUtf8("pushButton_calibration"));

        gridLayout_6->addWidget(pushButton_calibration, 11, 8, 1, 1);

        pushButton_write_corr = new QPushButton(tab);
        pushButton_write_corr->setObjectName(QString::fromUtf8("pushButton_write_corr"));

        gridLayout_6->addWidget(pushButton_write_corr, 10, 8, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_6->addWidget(label_7, 10, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 12, 0, 1, 1);

        lineEdit_device_number7 = new QLineEdit(tab);
        lineEdit_device_number7->setObjectName(QString::fromUtf8("lineEdit_device_number7"));
        lineEdit_device_number7->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_device_number7, 11, 3, 1, 1);

        lineEdit_ip_tuts_test_8 = new QLineEdit(tab);
        lineEdit_ip_tuts_test_8->setObjectName(QString::fromUtf8("lineEdit_ip_tuts_test_8"));
        lineEdit_ip_tuts_test_8->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(lineEdit_ip_tuts_test_8, 12, 2, 1, 1);

        lineEdit_device_number8 = new QLineEdit(tab);
        lineEdit_device_number8->setObjectName(QString::fromUtf8("lineEdit_device_number8"));
        lineEdit_device_number8->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_device_number8, 12, 3, 1, 1);

        checkBox_nonstop = new QCheckBox(tab);
        checkBox_nonstop->setObjectName(QString::fromUtf8("checkBox_nonstop"));

        gridLayout_6->addWidget(checkBox_nonstop, 9, 4, 1, 1);

        pushButton_save_settings = new QPushButton(tab);
        pushButton_save_settings->setObjectName(QString::fromUtf8("pushButton_save_settings"));

        gridLayout_6->addWidget(pushButton_save_settings, 15, 8, 1, 1);

        pushButton_reset_settings = new QPushButton(tab);
        pushButton_reset_settings->setObjectName(QString::fromUtf8("pushButton_reset_settings"));

        gridLayout_6->addWidget(pushButton_reset_settings, 15, 7, 1, 1);

        lineEdit_device_number1 = new QLineEdit(tab);
        lineEdit_device_number1->setObjectName(QString::fromUtf8("lineEdit_device_number1"));
        lineEdit_device_number1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_device_number1, 3, 3, 1, 1);

        pushButton_tracking = new QPushButton(tab);
        pushButton_tracking->setObjectName(QString::fromUtf8("pushButton_tracking"));
        QFont font;
        font.setPointSize(8);
        pushButton_tracking->setFont(font);

        gridLayout_6->addWidget(pushButton_tracking, 15, 4, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\222\320\22416-\320\241\320\265\321\200\320\262\320\270\321\201", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\222\320\22416 (4)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\222\320\22416 (3)", 0, QApplication::UnicodeUTF8));
        lineEdit_ip_tuts_test_1->setInputMask(QString());
        lineEdit_ip_tuts_test_1->setText(QApplication::translate("MainWindow", "192.168.1.21", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        lineEdit_RMSvalue->setText(QApplication::translate("MainWindow", "10.00", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\222\320\22416 (2)", 0, QApplication::UnicodeUTF8));
        lineEdit_ip_tuts_test_2->setText(QString());
        checkBoxSlowly->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\277\320\260\320\272\320\265\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        lineEdit_ip_tuts_test_3->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "IP \320\222\320\22416 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261-\320\272\320\270 \320\270\320\273\320\270 \320\276\321\202\320\272\320\273-\321\217", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\320\241\320\232\320\227 [\320\274/\321\201^2]", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272.", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\222\320\22416 (1)", 0, QApplication::UnicodeUTF8));
        lineEdit_ip_calibration->setText(QApplication::translate("MainWindow", "192.168.1.21", 0, QApplication::UnicodeUTF8));
        lineEdit_ip_tuts_test_4->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\200\321\200\320\265\320\272\321\202\320\270\321\200\321\203\321\216\321\211\320\270\320\271 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\274\320\265\320\266\320\264\321\203 \320\277\320\260\320\272\320\265\321\202\320\260\320\274\320\270", 0, QApplication::UnicodeUTF8));
        lineEdit_calibration_value->setText(QApplication::translate("MainWindow", "0.000800", 0, QApplication::UnicodeUTF8));
        checkBoxIgnore->setText(QApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270 \320\277\320\260\320\272\320\265\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\222\320\22416 (5)", 0, QApplication::UnicodeUTF8));
        pushButton_poweroff->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\222\320\22416", 0, QApplication::UnicodeUTF8));
        pushButton_console_clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\272\320\276\320\275\321\201\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_enable_widgets->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\321\203\321\201\320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\264\320\273\321\217 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270", 0, QApplication::UnicodeUTF8));
        lineEdit_ip_tuts_test_7->setText(QString());
        lineEdit_ip_tuts_test_5->setText(QString());
        lineEdit_password->setText(QString());
        lineEdit_ip_tuts_test_6->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\320\274\321\201\320\265\320\272", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\222\320\22416 (7)", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\262\321\213\320\261\320\276\321\200\320\272\321\203", 0, QApplication::UnicodeUTF8));
        pushButton_corr->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\272\320\276\321\200-\320\271 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_RMSvalue->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\241\320\232\320\227", 0, QApplication::UnicodeUTF8));
        pushButton_calibration->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \320\241\320\232\320\227", 0, QApplication::UnicodeUTF8));
        pushButton_write_corr->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\203", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\222\320\22416 (6)", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\222\320\22416 (8)", 0, QApplication::UnicodeUTF8));
        lineEdit_ip_tuts_test_8->setText(QString());
        checkBox_nonstop->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \320\277\320\276\321\201\321\202\320\276\321\217\320\275\320\275\320\276\320\263\320\276 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_save_settings->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_reset_settings->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272", 0, QApplication::UnicodeUTF8));
        lineEdit_device_number1->setText(QApplication::translate("MainWindow", "0001", 0, QApplication::UnicodeUTF8));
        pushButton_tracking->setText(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\266\320\265\320\275\320\270\320\265 \320\267\320\260 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\271 \321\201\321\202\321\200\320\276\320\272\320\276\320\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\222\320\267\320\260\320\270\320\274\320\276\320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265 \321\201 \320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\274", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
