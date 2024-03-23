#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    string path = "Images/img.jpg";
    Mat image = imread(path);
    resize(image, image,Size(640,480));
    Mat grayImage, blurImage, cannyImage, dilatedImage, erodeImage;

    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    GaussianBlur(grayImage, blurImage,Size(7,7), 0.1);
    Canny(blurImage, cannyImage, 25,75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(cannyImage, dilatedImage, kernel);
    erode(dilatedImage, erodeImage, kernel);

    imshow("Original Image", image);
    imshow("Gray Image", grayImage);
    imshow("Gaussian Blurred Image", blurImage);
    imshow("Canny Edge detected Image", cannyImage);
    imshow("Dilated Image", dilatedImage);
    imshow("Eroded Image", erodeImage);

    waitKey(0);
}
