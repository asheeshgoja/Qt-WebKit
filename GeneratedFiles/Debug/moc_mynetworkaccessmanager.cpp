/****************************************************************************
** Meta object code from reading C++ file 'mynetworkaccessmanager.h'
**
** Created: Tue Mar 8 09:41:15 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\mynetworkaccessmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mynetworkaccessmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyNetworkAccessManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x0a,
      83,   63,   23,   23, 0x0a,
     159,  146,   23,   23, 0x0a,
     212,  206,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyNetworkAccessManager[] = {
    "MyNetworkAccessManager\0\0"
    "slotError(QNetworkReply::NetworkError)\0"
    "proxy,authenticator\0"
    "slotProxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)\0"
    "reply,errors\0"
    "slotSslErrors(QNetworkReply*,QList<QSslError>)\0"
    "reply\0slotOnFinished(QNetworkReply*)\0"
};

const QMetaObject MyNetworkAccessManager::staticMetaObject = {
    { &QNetworkAccessManager::staticMetaObject, qt_meta_stringdata_MyNetworkAccessManager,
      qt_meta_data_MyNetworkAccessManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyNetworkAccessManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyNetworkAccessManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyNetworkAccessManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyNetworkAccessManager))
        return static_cast<void*>(const_cast< MyNetworkAccessManager*>(this));
    return QNetworkAccessManager::qt_metacast(_clname);
}

int MyNetworkAccessManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkAccessManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 1: slotProxyAuthenticationRequired((*reinterpret_cast< const QNetworkProxy(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 2: slotSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        case 3: slotOnFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
