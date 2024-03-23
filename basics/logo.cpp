#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

    Mat image(640,480,CV_8UC3, Scalar(0,0,0));

    ///////// OpenCV Logo //////////////////
    ellipse(image, Point(240,220), Size(50,50),20,-250, 30,Scalar(0,0,255),25);
    ellipse(image, Point(170,330), Size(50,50),20,0, 280,Scalar(0,255,0),25);
    ellipse(image, Point(300,330), Size(50,50),20,-75, 205,Scalar(255,0,0),25);
    putText(image, "OpenCV Logo", Point(120,100), FONT_HERSHEY_PLAIN, 3,Scalar(255,255,255),2);

    imshow("Logo", image);
    waitKey(0);



}
