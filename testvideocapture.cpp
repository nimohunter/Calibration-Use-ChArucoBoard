#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/imgproc.hpp>
#include <ctime>
#include <iostream>
#include <vector>
#include <mutex>
using namespace cv;
using namespace std;

// Some basic colors
Scalar red(0, 0, 255);
Scalar green(0,255,0);
Scalar blue(255,0,0);
Scalar yellow(0,255,255);

// Converts a given integer to a string
std::string IntToString ( int Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
// For text
int fontFace = cv::FONT_ITALIC;
double fontScale = 0.75;
int thickness_font = 2;

void drawFPS(cv::Mat image, double fps, cv::Scalar color)
{
    std::string fps_str = IntToString((int)fps);
    std::string text = fps_str + " FPS";
    cv::putText(image, text, cv::Point(500,50), fontFace, fontScale, color, thickness_font, 8);
}

int main()
{
    String video_read_path = "/home/nimo/NewCamera/RealTimePoseEstimation_WithAurcoDetect_Data/box_with_60FPS.avi";
    VideoCapture cap;
    cap.open(video_read_path);

    if(!cap.isOpened())   // check if we succeeded
    {
        cout << "Could not open the camera device" << endl;
        return -1;
    }

    double fps, sec;
    time_t start, end;
    int counter = 0;
    time(&start);

    Mat frame, frame_vis;
    while(cap.read(frame) && (char)waitKey(30) != 27) // capture frame until ESC is pressed
    {
        frame_vis = frame.clone();    // refresh visualisation frame

        time(&end);
        ++ counter;
        sec = difftime(end, start);
        fps = counter / sec;
        drawFPS(frame_vis, fps, blue); // frame ratio
        imshow("REAL TIME DEMO", frame_vis);
    }
    destroyWindow("REAL TIME DEMO");
    cout << "GOODBYE ..." << endl;
    return 0;
}
