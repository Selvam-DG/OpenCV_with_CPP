#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    string imgPath = "Images/img.jpg";
    Mat image = imread(imgPath);
    Mat matrix, imgWrap;
    float w= 250, h= 350;

    cout << "shape = " << image.size() <<endl;

    Point2f source[4] = { {50,30}, {600,30}, {60,500}, {640,500} };
    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f, h},{w,h}};

    matrix = getPerspectiveTransform(source,dst);
    warpPerspective(image, imgWrap, matrix, Point(w,h));

    for(int temp=0; temp<4; temp++)
    {
            circle(image, source[temp], 10, Scalar(0,0,255),FILLED);
    }

    imshow("Image", image);
    imshow("Wrap Image", imgWrap);
    waitKey(0);
}
