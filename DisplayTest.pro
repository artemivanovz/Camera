QT       += core gui
QT       += widgets multimedia multimediawidgets
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    configmanager.cpp \
    imagereceiver.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    configmanager.h \
    imagereceiver.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_Qt_5_15_2_MSVC2015_64bit-Release/config.ini \
    build/Desktop_Qt_5_15_2_MinGW_64_bit-Release/config.ini \
    config.ini
