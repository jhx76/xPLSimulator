/****************************************************************************
** Meta object code from reading C++ file 'MessageListWidget.h'
**
** Created: Fri Mar 15 23:32:48 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MessageListWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MessageListWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   19,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MessageListWidget[] = {
    "MessageListWidget\0\0message\0add(xPLMessage)\0"
};

void MessageListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MessageListWidget *_t = static_cast<MessageListWidget *>(_o);
        switch (_id) {
        case 0: _t->add((*reinterpret_cast< xPLMessage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MessageListWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MessageListWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MessageListWidget,
      qt_meta_data_MessageListWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MessageListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MessageListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MessageListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessageListWidget))
        return static_cast<void*>(const_cast< MessageListWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MessageListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
