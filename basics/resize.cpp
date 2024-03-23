#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//////////Resize and Crop ////////////
 int main(){
    string img_path = "Images/dog.jpg";
    Mat image = imread(img_path);

    Mat imageResize, imageCrop;

    cout << image.size() << endl;
    resize(image, imageResize, Size(640,480));

    Rect roi(650,300,700,900);
    imageCrop = image(roi);

    imshow("resize_image", imageResize);
    imshow("Crop Image", imageCrop);
    waitKey(0);


 }
