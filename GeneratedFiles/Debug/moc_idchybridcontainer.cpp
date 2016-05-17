/****************************************************************************
** Meta object code from reading C++ file 'idchybridcontainer.h'
**
** Created: Tue Mar 8 09:41:14 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\idchybridcontainer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'idchybridcontainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IdcHybridContainer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      53,   19,   19,   19, 0x0a,
      64,   19,   19,   19, 0x0a,
      76,   19,   19,   19, 0x0a,
      96,   87,   19,   19, 0x0a,
     112,   19,   19,   19, 0x0a,
     130,   19,   19,   19, 0x0a,
     152,  147,   19,   19, 0x0a,
     179,  171,   19,   19, 0x0a,
     203,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IdcHybridContainer[] = {
    "IdcHybridContainer\0\0"
    "populateJavaScriptWindowObject()\0"
    "openFile()\0printFile()\0printPdf()\0"
    "scanData\0onScan(QString)\0activateScanner()\0"
    "releaseScanner()\0data\0onCapture(QString)\0"
    "checked\0offlineBoxToggled(bool)\0"
    "changeLocation()\0"
};

const QMetaObject IdcHybridContainer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_IdcHybridContainer,
      qt_meta_data_IdcHybridContainer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IdcHybridContainer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IdcHybridContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IdcHybridContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IdcHybridContainer))
        return static_cast<void*>(const_cast< IdcHybridContainer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int IdcHybridContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: populateJavaScriptWindowObject(); break;
        case 1: openFile(); break;
        case 2: printFile(); break;
        case 3: printPdf(); break;
        case 4: onScan((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: activateScanner(); break;
        case 6: releaseScanner(); break;
        case 7: onCapture((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: offlineBoxToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: changeLocation(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
