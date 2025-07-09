QT += core gui
QT += widgets charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filtroativo.cpp \
    filtropassaalta_ativo.cpp \
    filtropassaalta_passivo.cpp \
    filtropassabaixa_ativo.cpp \
    filtropassabaixa_passivo.cpp \
    filtropassafaixa_ativo.cpp \
    filtropassafaixa_passivo.cpp \
    filtropassivo.cpp \
    filtrorejeitafaixa_ativo.cpp \
    filtrorejeitafaixa_passivo.cpp \
    graficofiltroativo.cpp \
    graficofiltropassivo.cpp \
    main.cpp \
    filtros.cpp

HEADERS += \
    filtroativo.h \
    filtropassaalta_ativo.h \
    filtropassaalta_passivo.h \
    filtropassabaixa_ativo.h \
    filtropassabaixa_passivo.h \
    filtropassafaixa_ativo.h \
    filtropassafaixa_passivo.h \
    filtropassivo.h \
    filtrorejeitafaixa_ativo.h \
    filtrorejeitafaixa_passivo.h \
    filtros.h \
    graficofiltroativo.h \
    graficofiltropassivo.h

FORMS += \
    filtros.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
