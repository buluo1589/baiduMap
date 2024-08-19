QT += core gui
QT += webenginewidgets   #只有用msvc编译器才能使用qwebengineview
QT += webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GPS.cpp \
    Serial.c \
    main.cpp \
    mainwindow.cpp \
    mybridge.cpp

HEADERS += \
    Serial.h \
    GPS.h \
    mainwindow.h \
    mybridge.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    web.qrc
