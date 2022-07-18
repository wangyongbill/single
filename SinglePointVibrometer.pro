QT       += core gui
QT +=axcontainer
QT +=printsupport
QT+=network
 QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QT+= axcontainer
QT += serialport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog_caijika.cpp \
    dialog_dianji.cpp \
    dialog_filter.cpp \
    dialog_measure_set.cpp \
    ele_machinery.cpp \
    filter.cpp \
    get_measure_thread.cpp \
    log.cpp \
    main.cpp \
    mainwindow.cpp \
    AutoResize.cpp  \
    mathprocess.cpp \
    myplot.cpp \
    processthread.cpp \
    spectrumDisp.cpp \
    utils.cpp\
    qcustomplot.cpp \
    xdmapcie.cpp


HEADERS += \
    dialog_caijika.h \
    dialog_dianji.h \
    dialog_filter.h \
    dialog_measure_set.h \
    ele_machinery.h \
    fftw3.h \
    filter.h \
    get_measure_thread.h \
    log.h \
    mainwindow.h\
    AutoResize.h\
    mathprocess.h \
    myplot.h \
    processthread.h \
    spectrumDisp.h \
    utils.h \
    qcustomplot.h \
    xdma_public.h \
    xdmapcie.h
FORMS += \
    dialog_caijika.ui \
    dialog_dianji.ui \
    dialog_filter.ui \
    dialog_measure_set.ui \
    mainwindow.ui \
    myplot.ui

CONFIG(debug, debug|release): {

LIBS += -L$$PWD/lib \
-llibfftw3-3\
-lFTD3XX\
-lglu32 \
-lglut
} else:CONFIG(release, debug|release): {
LIBS += -L$$PWD/lib \
-llibfftw3-3\
-lFTD3XX\
-lglu32 \
-lglut
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc \
    qss.qrc

DISTFILES += \
    xdma.lib

win32: LIBS += -lsetupapi
