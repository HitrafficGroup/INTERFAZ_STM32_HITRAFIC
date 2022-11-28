#-------------------------------------------------
#
# Project created by QtCreator 2018-07-16T20:48:31
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += C++11
TARGET = TSC96
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    readOnlyDelegate.cpp \
    choose_dialog.cpp \
    pattern_dialog.cpp \
    split_dialog.cpp \
    peddet_dialog.cpp \
    main_dialog.cpp \
    phase_dialog.cpp \
    channel_dialog.cpp \
    sequence_dialog.cpp \
    schedule_dialog.cpp \
    action_dialog.cpp \
    plan_dialog.cpp \
    connect_dialog.cpp \
    overlap_dialog.cpp \
    itemdelegate.cpp \
    vehdet_dialog.cpp

HEADERS  += mainwindow.h \
    readonlydelegate.h \
    choose_dialog.h \
    pattern_dialog.h \
    split_dialog.h \
    peddet_dialog.h \
    main_dialog.h \
    phase_dialog.h \
    channel_dialog.h \
    tsc.h \
    sequence_dialog.h \
    schedule_dialog.h \
    action_dialog.h \
    plan_dialog.h \
    connect_dialog.h \
    overlap_dialog.h \
    itemdelegate.h \
    vehdet_dialog.h

FORMS    += mainwindow.ui \
    choose_dialog.ui \
    pattern_dialog.ui \
    split_dialog.ui \
    peddet_dialog.ui \
    main_dialog.ui \
    phase_dialog.ui \
    channel_dialog.ui \
    sequence_dialog.ui \
    schedule_dialog.ui \
    action_dialog.ui \
    plan_dialog.ui \
    connect_dialog.ui \
    overlap_dialog.ui \
    vehdet_dialog.ui

TRANSLATIONS += zh.ts
