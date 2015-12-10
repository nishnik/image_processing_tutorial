#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <typeinfo>
#include "opencv/cv.h" 
using namespace cv;
using namespace std;
//Gaussian Filter
//Oh there is one formula for it 
//For 2D it is:
// exp{-(x^2+y^2)/constant} / (constant *PI)
//here the constant is standard deviation squared

//Hey here is Magic
//You subtract original image from smoothed image
//And damn! What you get?
//Some Mathematics.. you must have read in lower classes :p
int main(int argc, char* argv[])
{
    Mat image = imread("image.jpg",0);//see this is grayscale
    imshow("Original Image",image);
    Mat filtered(image.rows,image.cols,CV_8UC1);//Oh! I did something here
    for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            if(i==0 || j==0 || i==image.rows-1 || j==image.cols-1)
            {
                filtered.at<uchar>(i,j)=image.at<uchar>(i,j);
            }
            else 
            {
                filtered.at<uchar>(i,j) = 0.0625*image.at<uchar>(i-1,j-1)+//Oh man from where these values come from
                        0.125*image.at<uchar>(i-1,j)+
                        0.0625*image.at<uchar>(i-1,j+1)+
                        0.125*image.at<uchar>(i,j-1)+
                        0.25*image.at<uchar>(i,j)+
                        0.125*image.at<uchar>(i,j+1)+
                        0.0625*image.at<uchar>(i+1,j-1)+
                        0.125*image.at<uchar>(i+1,j)+
                        0.0625*image.at<uchar>(i+1,j+1);
            }//These are precomputed just to make it all fast
            //Can we have a bigger kernel
        }
    }
    imshow("Filtered",filtered);
    Mat edges = filtered - image;
    imshow("Edges",edges);
    

    waitKey(0);

}
