/****************************************************************************
** Meta object code from reading C++ file 'PortListener.h'
**
** Created: Tue Mar 8 09:41:15 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\SerialPort\PortListener.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PortListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PortListener[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   13,   13,   13, 0x0a,
      57,   51,   13,   13, 0x0a,
      79,   13,   13,   13, 0x0a,
     100,   93,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PortListener[] = {
    "PortListener\0\0data\0dataCaptured(QString)\0"
    "receive()\0bytes\0reportWritten(qint64)\0"
    "reportClose()\0status\0reportDsr(bool)\0"
};

const QMetaObject PortListener::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PortListener,
      qt_meta_data_PortListener, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PortListener::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PortListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PortListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PortListener))
        return static_cast<void*>(const_cast< PortListener*>(this));
    return QObject::qt_metacast(_clname);
}

int PortListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dataCaptured((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: receive(); break;
        case 2: reportWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: reportClose(); break;
        case 4: reportDsr((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PortListener::dataCaptured(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
