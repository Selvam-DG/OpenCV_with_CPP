#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void getContours(Mat dilImg, Mat img){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(dilImg, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(img, contours, -1, Scalar(0,0,255));

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    for(int i=0; i<contours.size(); i++)
    {
        int area = contourArea(contours[i]);
        cout << "Area = " << area << endl;
        string objectType;

        if (area > 1000)
        {
            float perim = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02* perim, true);
            cout << "conPoly_size" << conPoly[i].size() << endl;
            boundRect[i] = boundingRect(conPoly[i]);

            int objCor = (int)conPoly[i].size();

            if (objCor == 3)
            {
                objectType = "Tri";
            }
            else if (objCor == 4)
            {
                float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
                cout << "Aspect Ratio = " << aspRatio << endl;
                if (aspRatio > 0.95 && aspRatio < 1.05)
                {
                    objectType = "square";
                }
                else
                {
                    objectType = "Rectangle";
                }

            }
             else if (objCor > 4)
            {
                objectType = "Rectangle";
            }
            drawContours(img, conPoly, i, Scalar(255,0,0),2);

            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0,255,0), 5);
            putText(img, objectType, { boundRect[i].x, boundRect[i].y-5}, FONT_HERSHEY_PLAIN, 1, Scalar(0,69,255),2);

        }
    }



}

int main(){
    string img_path = "Images/Messi.jpg";
    Mat image = imread(img_path);
    resize(image, image, Size(640,480));

    Mat grayImg, blurImg, cannyImg, dilateImg, erodeImg;
    cvtColor(image, grayImg, COLOR_BGR2GRAY);
    GaussianBlur(grayImg, blurImg, Size(5,5),0,0);
    Canny(blurImg, cannyImg,25,120);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(cannyImg, dilateImg, kernel);
    erode(dilateImg, erodeImg, kernel);
    getContours(dilateImg, image);

    imshow("Image", image);
//
//    imshow("Gray_Image", grayImg);
//    imshow("Blur_Image", blurImg);
//    imshow("CannyEdge", cannyImg);
//    imshow("Dilated Image", dilateImg);
//    imshow("Eroded Image", erodeImg);
    waitKey(0);

}

