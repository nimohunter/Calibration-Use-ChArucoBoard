//test opencv in threaded way
//capture images in a thread
//process in another thread

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay();

/** Global variables */
String video_read_path = "/home/nimo/NewCamera/RealTimePoseEstimation_WithAurcoDetect_Data/box_with_60FPS.avi";
string window_name = "Video";

Mat frm;
mutex mtx;
int c=0;
bool is_frame_prepare;
bool isMainRunning;

void run_capture()
{
    VideoCapture capture;
    capture.open(video_read_path);
    int count = 0;

    if( capture.isOpened() )
    {
        while (isMainRunning)
        {
            mtx.lock();
            if (is_frame_prepare) {
                // Nothing to do
            } else {
                cout <<"frame: "<< count++ <<" \n";
                capture.read(frm);
                if (frm.empty()) {
                    isMainRunning = false;
                }
                is_frame_prepare = true;
            }
            mtx.unlock();
        }
    }

}


/**
 * @function detectAndDisplay
 */
void detect_and_display()
{
    bool isExist;
    Mat frame;

    while (isMainRunning)
    {
        isExist = false;

        mtx.lock();
        if (is_frame_prepare) {
            cout <<"get frame\n";
            isExist = true;
            frm.copyTo(frame);
            is_frame_prepare = false;
        }
        mtx.unlock();

        if (isExist)
        {
            //-- Show what you got
            imshow(window_name, frame);
            c = waitKey(1);
            if( (char)c == 'c' ) {
                break;
            }
        } else {
            cout <<"sleep\n";
            std::this_thread::sleep_for (std::chrono::milliseconds(1));
        }
    }
}

int main()
{
    is_frame_prepare = false;
    isMainRunning = true;
    thread cap(run_capture);
    thread dis(detect_and_display);
    cap.join();
    dis.join();
    return 0;
}
