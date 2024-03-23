#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//////////// Read Imags //////////

//int main()
//{
//    string img_path = "Images/dog.jpg";
//    Mat image = imread(img_path,1);
//    imshow("Image",image);
//    waitKey(0);
//}


/////// Read Videos /////////
//int main()
//{
//    string vid_path = "Images/test_video.mp4";
//    VideoCapture cap(vid_path);
//    Mat image;
//
//    while(true){
//        cap.read(image);
//        imshow("Video_Playing", image);
//        waitKey(20);
//
//    }
//
//}


///////// webcame //////////////

int main(){
    VideoCapture capture(0);
    Mat image;

    while (true){

        capture.read(image);
        imshow("Webcam", image);
        int k = waitKey(1);
        if(k==27){   // press escape key to exit the webcam
            break;
            }
    }
}
