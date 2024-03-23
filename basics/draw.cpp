#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

////////////////// Draw shapes and text ////////////////////

int main(){

    //// create black image
//    Mat blackImage(640,480,CV_8UC3, Scalar(0,0,0));
    //// create white image
    Mat image(640,480,CV_8UC3, Scalar(255,255,255));

//    Mat greenimage(640,480,CV_8UC3, Scalar(0,255,0));
    line(image,Point(0,0), Point(480,640), Scalar(0,0,255), 5);
    line(image, Point(480,0), Point(0,640),Scalar(0,0,255),5);
    circle(image, Point(240,320), 50,Scalar(0,255,0),FILLED);
    rectangle(image, Point(160,240), Point(320,400),Scalar(255,0,0),5);

    putText(image, "OpenCV_CPP Selvam", Point(100,75), FONT_HERSHEY_DUPLEX, 0.75, Scalar(75,150,255),3);
    ellipse(image, Point(200,175), Size(70,120),25,0,300,Scalar(0,0,255),10);
    imshow("Image",image);

    waitKey(0);

    return 0;


}
