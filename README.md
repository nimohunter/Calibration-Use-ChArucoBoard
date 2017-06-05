# Calibration-Use-ChArucoBoard
Base on Opencv3 and Aruco, Use in Qt.

With 3 Cpps

* `main.cpp` is Calibration main Cpp
* `drawcharucoboard.cpp`  as the name, generate the ChArucoBoard
* `testvideocapture.cpp` test the video file is Recognized by Opencv3

you can modify the `Calibration.pro` to Build and Run.

References:
> [Calibration with ArUco and ChArUco](http://docs.opencv.org/3.1.0/da/d13/tutorial_aruco_calibration.html)

### 1. Generate ChArucoBoard
From the reference, can get Source code from [here](https://github.com/opencv/opencv_contrib/blob/master/modules/aruco/samples/create_board_charuco.cpp)

Because with Qt, the Qt Pro file is:

```
QT += core
QT -= gui

CONFIG += c++11

TARGET = new_camera_Calibration
CONFIG += console
CONFIG -= app_bundle
INCLUDEPATH += .
INCLUDEPATH += /usr/local/include/

LIBS += -L/usr/local/lib/ -I/usr/local/include -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_aruco -lopencv_imgcodecs -lopencv_calib3d -lopencv_videoio

TEMPLATE = app

SOURCES += \
    drawcharucoboard.cpp

DEFINES += QT_DEPRECATED_WARNINGS

```

and with Qt Creator 4.2, in the left side, choose Project->Run Setting-> Command line arguments, input this:

```
-w=7 -h=5 -sl=80 -ml=70 -d=11 -bb=1 -si=true /home/nimo/NewCamera/Temp/0601.png
```

Then, run the source code, you can get a Board.


### 2. Calibrate
And then, you can use your camera to take a video, the content is the ChArucoBoard what is generate in first part.

Use Python Code to Get avi, I dont know the reason why the Opencv3 could not recognize the video which I get from AMCap. And then, use the Source Code [here](https://github.com/opencv/opencv_contrib/blob/master/modules/aruco/samples/calibrate_camera_charuco.cpp)

and here is the Args:

```
-w=7 -h=5 -sl=80 -ml=70 -d=11 -sc=true -v=/home/nimo/Videos/NewCamera/calibration.avi /home/nimo/NewCamera/Calibration.txt
```
