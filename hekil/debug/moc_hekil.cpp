/****************************************************************************
** Meta object code from reading C++ file 'hekil.h'
**
** Created: Fri May 18 10:13:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hekil.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hekil.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_hekil[] = {

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
       7,    6,    6,    6, 0x08,
      19,    6,    6,    6, 0x08,
      33,    6,    6,    6, 0x08,
      47,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_hekil[] = {
    "hekil\0\0saveMovie()\0selectMovie()\0"
    "deleteMovie()\0updateMovie()\0"
};

const QMetaObject hekil::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hekil,
      qt_meta_data_hekil, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &hekil::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *hekil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *hekil::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_hekil))
        return static_cast<void*>(const_cast< hekil*>(this));
    return QWidget::qt_metacast(_clname);
}

int hekil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: saveMovie(); break;
        case 1: selectMovie(); break;
        case 2: deleteMovie(); break;
        case 3: updateMovie(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
