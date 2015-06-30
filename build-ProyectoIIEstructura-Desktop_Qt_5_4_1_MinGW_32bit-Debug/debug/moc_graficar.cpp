/****************************************************************************
** Meta object code from reading C++ file 'graficar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ProyectoIIEstructura/graficar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graficar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Graficar_t {
    QByteArrayData data[15];
    char stringdata[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graficar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graficar_t qt_meta_stringdata_Graficar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Graficar"
QT_MOC_LITERAL(1, 9, 25), // "on_BtnCalcularMat_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 24), // "on_BtnAgregarVer_clicked"
QT_MOC_LITERAL(4, 61, 24), // "on_BtnAgregarAri_clicked"
QT_MOC_LITERAL(5, 86, 25), // "on_BtnBorrarAri_2_clicked"
QT_MOC_LITERAL(6, 112, 23), // "on_BtnBorrarAri_clicked"
QT_MOC_LITERAL(7, 136, 23), // "on_BtnBorrarVer_clicked"
QT_MOC_LITERAL(8, 160, 19), // "on_BtnAbrir_clicked"
QT_MOC_LITERAL(9, 180, 31), // "on_CmbTipos_currentIndexChanged"
QT_MOC_LITERAL(10, 212, 5), // "index"
QT_MOC_LITERAL(11, 218, 24), // "on_BtnBorrarVert_clicked"
QT_MOC_LITERAL(12, 243, 27), // "on_BtnBorrarVertice_clicked"
QT_MOC_LITERAL(13, 271, 26), // "on_BtnBorrarArista_clicked"
QT_MOC_LITERAL(14, 298, 27) // "on_BtnAgregarArista_clicked"

    },
    "Graficar\0on_BtnCalcularMat_clicked\0\0"
    "on_BtnAgregarVer_clicked\0"
    "on_BtnAgregarAri_clicked\0"
    "on_BtnBorrarAri_2_clicked\0"
    "on_BtnBorrarAri_clicked\0on_BtnBorrarVer_clicked\0"
    "on_BtnAbrir_clicked\0on_CmbTipos_currentIndexChanged\0"
    "index\0on_BtnBorrarVert_clicked\0"
    "on_BtnBorrarVertice_clicked\0"
    "on_BtnBorrarArista_clicked\0"
    "on_BtnAgregarArista_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graficar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    1,   81,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Graficar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graficar *_t = static_cast<Graficar *>(_o);
        switch (_id) {
        case 0: _t->on_BtnCalcularMat_clicked(); break;
        case 1: _t->on_BtnAgregarVer_clicked(); break;
        case 2: _t->on_BtnAgregarAri_clicked(); break;
        case 3: _t->on_BtnBorrarAri_2_clicked(); break;
        case 4: _t->on_BtnBorrarAri_clicked(); break;
        case 5: _t->on_BtnBorrarVer_clicked(); break;
        case 6: _t->on_BtnAbrir_clicked(); break;
        case 7: _t->on_CmbTipos_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_BtnBorrarVert_clicked(); break;
        case 9: _t->on_BtnBorrarVertice_clicked(); break;
        case 10: _t->on_BtnBorrarArista_clicked(); break;
        case 11: _t->on_BtnAgregarArista_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Graficar::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Graficar.data,
      qt_meta_data_Graficar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Graficar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graficar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Graficar.stringdata))
        return static_cast<void*>(const_cast< Graficar*>(this));
    return QDialog::qt_metacast(_clname);
}

int Graficar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
