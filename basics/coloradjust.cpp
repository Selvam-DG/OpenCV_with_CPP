#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    string img_path = "Images/dog.jpg";
//    string img_path = "Images/Ronaldo.jpg";
    Mat image = imread(img_path);
    resize(image, image, Size(640,480));
    Mat HSVimage, mask;
    int hmin = 0, smin = 110, vmin = 150;
    int hmax = 150, smax = 250, vmax = 255;

    cvtColor(image, HSVimage, COLOR_BGR2HSV);

    namedWindow("ColorAdjustment Trackbars", (640,250));
    createTrackbar("Hue Min", "ColorAdjustment Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "ColorAdjustment Trackbars", &hmax, 179);
    createTrackbar("sat Min", "ColorAdjustment Trackbars", &smin, 255);
    createTrackbar("sat Max", "ColorAdjustment Trackbars", &smax, 255);
    createTrackbar("Val Min", "ColorAdjustment Trackbars", &vmin, 255);
    createTrackbar("Val Max", "ColorAdjustment Trackbars", &vmax, 255);

    while(true){
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        inRange(HSVimage, lower, upper, mask);

        imshow("Image", image);
        imshow("HSV_Image", HSVimage);
        imshow("Mask Image", mask);
        int k = waitKey(1);
        if (k==27){
            break;
        }
    }

    return 0;

}
