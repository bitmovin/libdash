/****************************************************************************
** Meta object code from reading C++ file 'qtsampleplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtsampleplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtsampleplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtSamplePlayer_t {
    QByteArrayData data[8];
    char stringdata[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QtSamplePlayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QtSamplePlayer_t qt_meta_stringdata_QtSamplePlayer = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 40),
QT_MOC_LITERAL(2, 56, 0),
QT_MOC_LITERAL(3, 57, 4),
QT_MOC_LITERAL(4, 62, 46),
QT_MOC_LITERAL(5, 109, 40),
QT_MOC_LITERAL(6, 150, 46),
QT_MOC_LITERAL(7, 197, 25)
    },
    "QtSamplePlayer\0on_cb_video_adaption_currentIndexChanged\0"
    "\0arg1\0on_cb_video_representation_currentIndexChanged\0"
    "on_cb_audio_adaption_currentIndexChanged\0"
    "on_cb_audio_representation_currentIndexChanged\0"
    "on_lineEdit_returnPressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtSamplePlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       4,    1,   42,    2, 0x08,
       5,    1,   45,    2, 0x08,
       6,    1,   48,    2, 0x08,
       7,    0,   51,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void QtSamplePlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtSamplePlayer *_t = static_cast<QtSamplePlayer *>(_o);
        switch (_id) {
        case 0: _t->on_cb_video_adaption_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_cb_video_representation_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_cb_audio_adaption_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_cb_audio_representation_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_lineEdit_returnPressed(); break;
        default: ;
        }
    }
}

const QMetaObject QtSamplePlayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtSamplePlayer.data,
      qt_meta_data_QtSamplePlayer,  qt_static_metacall, 0, 0}
};


const QMetaObject *QtSamplePlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtSamplePlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtSamplePlayer.stringdata))
        return static_cast<void*>(const_cast< QtSamplePlayer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtSamplePlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
