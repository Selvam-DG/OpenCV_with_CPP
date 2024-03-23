#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(){
    string img_path = "Images/img.jpg";
    Mat image = imread(img_path);
    resize(image, image, Size(640,480));
    CascadeClassifier faceCascade;
    faceCascade.load("Images/haarcascade_frontalface_default.xml");

    if(faceCascade.empty())
    {
        cout << "XML file not loaded" << endl;
    }
    vector <Rect > faces;
    faceCascade.detectMultiScale(image, faces, 1.1, 10);

    for( int temp = 0; temp< faces.size(); temp++)
    {
        rectangle(image, faces[temp].tl(), faces[temp].br(), Scalar(255,0,0),5);
    }
    putText(image, "Arnald", faces[0].tl(), 0, 1, Scalar(0,255,0), 3);
    imshow("Image", image);
    waitKey(0);

}
