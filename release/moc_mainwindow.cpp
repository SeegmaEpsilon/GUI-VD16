/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri 3. Jun 17:17:14 2022
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      59,   31,   11,   11, 0x08,
     100,   31,   11,   11, 0x08,
     149,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     211,   11,   11,   11, 0x08,
     244,   11,   11,   11, 0x08,
     273,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     341,   11,   11,   11, 0x08,
     379,   11,   11,   11, 0x08,
     412,   11,   11,   11, 0x08,
     451,   11,   11,   11, 0x08,
     472,   11,   11,   11, 0x08,
     494,   11,   11,   11, 0x08,
     522,   11,   11,   11, 0x08,
     550,   11,   11,   11, 0x08,
     588,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0slotTimerTimeout()\0"
    "datagram,IPClien,PortClient\0"
    "slotMsgIzLan(QByteArray,QString,quint16)\0"
    "testUdpFrameReceived(QByteArray,QString,quint16)\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_calibration_clicked()\0"
    "on_pushButton_poweroff_clicked()\0"
    "on_pushButton_corr_clicked()\0"
    "on_pushButton_RMSvalue_clicked()\0"
    "on_pushButton_write_corr_clicked()\0"
    "on_pushButton_console_clear_clicked()\0"
    "on_pushButton_tracking_clicked()\0"
    "on_pushButton_enable_widgets_clicked()\0"
    "enable_all_widgets()\0disable_all_widgets()\0"
    "on_checkBoxSlowly_clicked()\0"
    "on_checkBoxIgnore_clicked()\0"
    "on_pushButton_save_settings_clicked()\0"
    "on_pushButton_reset_settings_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->slotTimerTimeout(); break;
        case 1: _t->slotMsgIzLan((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 2: _t->testUdpFrameReceived((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 3: _t->on_pushButton_5_clicked(); break;
        case 4: _t->on_pushButton_calibration_clicked(); break;
        case 5: _t->on_pushButton_poweroff_clicked(); break;
        case 6: _t->on_pushButton_corr_clicked(); break;
        case 7: _t->on_pushButton_RMSvalue_clicked(); break;
        case 8: _t->on_pushButton_write_corr_clicked(); break;
        case 9: _t->on_pushButton_console_clear_clicked(); break;
        case 10: _t->on_pushButton_tracking_clicked(); break;
        case 11: _t->on_pushButton_enable_widgets_clicked(); break;
        case 12: _t->enable_all_widgets(); break;
        case 13: _t->disable_all_widgets(); break;
        case 14: _t->on_checkBoxSlowly_clicked(); break;
        case 15: _t->on_checkBoxIgnore_clicked(); break;
        case 16: _t->on_pushButton_save_settings_clicked(); break;
        case 17: _t->on_pushButton_reset_settings_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
