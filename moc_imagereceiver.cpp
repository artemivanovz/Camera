/****************************************************************************
** Meta object code from reading C++ file 'imagereceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "imagereceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagereceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageReceiver_t {
    QByteArrayData data[9];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageReceiver_t qt_meta_stringdata_ImageReceiver = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ImageReceiver"
QT_MOC_LITERAL(1, 14, 13), // "imageReceived"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "image"
QT_MOC_LITERAL(4, 35, 18), // "startCameraCommand"
QT_MOC_LITERAL(5, 54, 17), // "stopCameraCommand"
QT_MOC_LITERAL(6, 72, 19), // "startDisplayCommand"
QT_MOC_LITERAL(7, 92, 18), // "stopDisplayCommand"
QT_MOC_LITERAL(8, 111, 11) // "onReadyRead"

    },
    "ImageReceiver\0imageReceived\0\0image\0"
    "startCameraCommand\0stopCameraCommand\0"
    "startDisplayCommand\0stopDisplayCommand\0"
    "onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageReceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,
       6,    0,   49,    2, 0x06 /* Public */,
       7,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ImageReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageReceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imageReceived((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->startCameraCommand(); break;
        case 2: _t->stopCameraCommand(); break;
        case 3: _t->startDisplayCommand(); break;
        case 4: _t->stopDisplayCommand(); break;
        case 5: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageReceiver::*)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageReceiver::imageReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImageReceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageReceiver::startCameraCommand)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ImageReceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageReceiver::stopCameraCommand)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ImageReceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageReceiver::startDisplayCommand)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ImageReceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageReceiver::stopDisplayCommand)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImageReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ImageReceiver.data,
    qt_meta_data_ImageReceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImageReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageReceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ImageReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ImageReceiver::imageReceived(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageReceiver::startCameraCommand()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ImageReceiver::stopCameraCommand()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ImageReceiver::startDisplayCommand()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ImageReceiver::stopDisplayCommand()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
