#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T18:21:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = menu_editor
TEMPLATE = app

CONFIG += c++14

include(CafeMenuCore/CafeMenuCore.pri)

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    consoleprintmenuvisitor.cpp \
    menuiterator.cpp \
    texteditprintmenuvisitor.cpp \
    menucombobox.cpp \
    editordelegate.cpp \
    adddialog.cpp \
    lambdavisitor.cpp

HEADERS  += mainwindow.h \
    consoleprintmenuvisitor.h \
    menuiterator.h \
    texteditprintmenuvisitor.h \
    menucombobox.h \
    editordelegate.h \
    adddialog.h \
    lambdavisitor.h

FORMS    += mainwindow.ui \
    editordelegate.ui \
    adddialog.ui
