/****************************************************************************
** Meta object code from reading C++ file 'Qt_Project2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Qt_Project2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Qt_Project2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qt_Project2_t {
    QByteArrayData data[11];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qt_Project2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qt_Project2_t qt_meta_stringdata_Qt_Project2 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Qt_Project2"
QT_MOC_LITERAL(1, 12, 19), // "onComboBoxActivated"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 1), // "i"
QT_MOC_LITERAL(4, 35, 17), // "SaveAndExitButton"
QT_MOC_LITERAL(5, 53, 15), // "inputAddPatient"
QT_MOC_LITERAL(6, 69, 18), // "inputRemovePatient"
QT_MOC_LITERAL(7, 88, 8), // "UndoSlot"
QT_MOC_LITERAL(8, 97, 8), // "RedoSlot"
QT_MOC_LITERAL(9, 106, 11), // "Filter1Slot"
QT_MOC_LITERAL(10, 118, 11) // "Filter2Slot"

    },
    "Qt_Project2\0onComboBoxActivated\0\0i\0"
    "SaveAndExitButton\0inputAddPatient\0"
    "inputRemovePatient\0UndoSlot\0RedoSlot\0"
    "Filter1Slot\0Filter2Slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qt_Project2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Qt_Project2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Qt_Project2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onComboBoxActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SaveAndExitButton(); break;
        case 2: _t->inputAddPatient(); break;
        case 3: _t->inputRemovePatient(); break;
        case 4: _t->UndoSlot(); break;
        case 5: _t->RedoSlot(); break;
        case 6: _t->Filter1Slot(); break;
        case 7: _t->Filter2Slot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Qt_Project2::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Qt_Project2.data,
    qt_meta_data_Qt_Project2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Qt_Project2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qt_Project2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qt_Project2.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Qt_Project2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
