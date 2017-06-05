#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/imgproc.hpp>
#include <ctime>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

int main()
{
//    String video_read_path = "/home/nimo/Videos/2017-06-01_140137_665.mp4";
    String video_read_path = "/home/nimo/Videos/NewCamera/screencast0605.avi";
    VideoCapture cap;
    cap.open(video_read_path);

    if(!cap.isOpened())   // check if we succeeded
    {
        cout << "Could not open the camera device" << endl;
        return -1;
    }
    Mat frame, frame_vis;
    while(cap.read(frame) && (char)waitKey(30) != 27) // capture frame until ESC is pressed
    {
        frame_vis = frame.clone();    // refresh visualisation frame
        imshow("REAL TIME DEMO", frame_vis);
    }
    destroyWindow("REAL TIME DEMO");
    cout << "GOODBYE ..." << endl;
    return 0;
}
