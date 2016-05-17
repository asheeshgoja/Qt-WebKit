/****************************************************************************
** Meta object code from reading C++ file 'networkaccessviewer.h'
**
** Created: Tue Mar 8 09:41:15 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\networkaccessviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkaccessviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NetworkAccessViewer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      46,   20,   20,   20, 0x08,
      66,   54,   20,   20, 0x08,
      97,   92,   20,   20, 0x08,
     131,   54,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NetworkAccessViewer[] = {
    "NetworkAccessViewer\0\0on_clearButton_clicked()\0"
    "clear()\0replyObject\0requestFinished(QObject*)\0"
    "item\0showItemDetails(QTreeWidgetItem*)\0"
    "readyRead(QObject*)\0"
};

const QMetaObject NetworkAccessViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NetworkAccessViewer,
      qt_meta_data_NetworkAccessViewer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NetworkAccessViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NetworkAccessViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NetworkAccessViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkAccessViewer))
        return static_cast<void*>(const_cast< NetworkAccessViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int NetworkAccessViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_clearButton_clicked(); break;
        case 1: clear(); break;
        case 2: requestFinished((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 3: showItemDetails((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 4: readyRead((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
