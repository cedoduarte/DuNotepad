#-------------------------------------------------
#
# Project created by DuarteCorporation
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuNotepad
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    finddialog.cpp \
    findform.cpp \
    findreplacedialog.cpp \
    findreplaceform.cpp

HEADERS  += mainwindow.h \
    finddialog.h \
    findform.h \
    findreplacedialog.h \
    findreplaceform.h

FORMS    += mainwindow.ui \
    findreplacedialog.ui \
    findreplaceform.ui

RESOURCES += \
    mis_iconos.qrc

OTHER_FILES += \
    icono_principal_rc.rc

RC_FILE += icono_principal_rc.rc

QMAKE_CXXFLAGS += -std=gnu++14
