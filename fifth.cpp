#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <typeinfo>
#include "opencv/cv.h" 
using namespace cv;
using namespace std;
//Conversion to binary
//There are Three methods
int main(int argc, char* argv[])
{
    Mat image = imread("image.jpg",0);//see this is grayscale
    Mat modified(image.rows,image.cols,CV_8UC1);//see it has only one Channel
    int thres;
    namedWindow("Control");
    createTrackbar("Threshold", "Control", &thres, 255);
    imshow("original image",image);
    

    while(1)
    {
        for(int i=0;i<image.rows;i++)
        {
            for(int j=0;j<image.cols;j++)
            {
                if(image.at<uchar>(i,j)<=thres)
                    modified.at<uchar>(i,j) = 0;
                else
                    modified.at<uchar>(i,j) = 255;
            }
        }
        imshow("modified image",modified);
        char c = waitKey(33);//waits for 33 ms then proceeds.
                            //do you know how much time between two frames
                            //our eyes differenciate
        if(c=='q')//if you press q it will exit
            break;
    }

}
