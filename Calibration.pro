QT += core
QT -= gui

CONFIG += c++11

TARGET = new_camera_Calibration
CONFIG += console
CONFIG -= app_bundle
INCLUDEPATH += .
INCLUDEPATH += /usr/local/include/

#LIBS += -L/usr/local/lib/ -I/usr/local/include -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_aruco -lopencv_imgcodecs -lopencv_calib3d -lopencv_videoio
LIBS += -L/usr/local/lib/ -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_aruco\
-lopencv_highgui -lopencv_videoio -lopencv_calib3d -lopencv_video -lopencv_features2d \
-lopencv_flann -lopencv_objdetect

TEMPLATE = app

SOURCES += \
    main.cpp \
#    drawcharucoboard.cpp
#    testvideocapture.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
