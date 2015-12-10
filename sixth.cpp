#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <typeinfo>
#include "opencv/cv.h" 
using namespace cv;
using namespace std;
//Edge Detection -> Basic Approach
int main(int argc, char* argv[])
{
    Mat image = imread("image.jpg",0);//see this is grayscale
    imshow("grayscale image",image);
    Mat edges(image.rows,image.cols,CV_8UC1);//Oh! I did something here
    int threshold = 110;//is it a good way?
    for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            if(i==0 || j==0 || i==image.rows-1 || j==image.cols-1)
            {
                edges.at<uchar>(i,j)=0;
            }
            else // here we find the maximum pixel intensity
                 // and the minimum pixel intensity
                 // compare it to a threshold value and Bammmm!!!
            {
                int m = max(image.at<uchar>(i-1,j-1),
                        max(image.at<uchar>(i-1,j),
                        max(image.at<uchar>(i-1,j+1),
                        max(image.at<uchar>(i,j-1),
                        max(image.at<uchar>(i,j),
                        max(image.at<uchar>(i,j+1),
                        max(image.at<uchar>(i+1,j-1),
                        max(image.at<uchar>(i+1,j),
                        image.at<uchar>(i+1,j+1)))))))));
                int n = min(image.at<uchar>(i-1,j-1),
                        min(image.at<uchar>(i-1,j),
                        min(image.at<uchar>(i-1,j+1),
                        min(image.at<uchar>(i,j-1),
                        min(image.at<uchar>(i,j),
                        min(image.at<uchar>(i,j+1),
                        min(image.at<uchar>(i+1,j-1),
                        min(image.at<uchar>(i+1,j),
                        image.at<uchar>(i+1,j+1)))))))));
            if(m-n > threshold)
                edges.at<uchar>(i,j) = 255;
            else
                edges.at<uchar>(i,j) = 0;
            }
        }
    }
    imshow("Edges",edges);
    //Can we also do it with color images ? 
    waitKey(0);

}
