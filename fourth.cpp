#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <typeinfo>
#include "opencv/cv.h" 
using namespace cv;
using namespace std;
//Conversion to grayscale
//There are Three methods
int main(int argc, char* argv[])
{
    Mat image = imread("image.jpg",1);//see this is colored
    Mat converted_light(image.rows,image.cols,CV_8UC1);
    Mat converted_average(image.rows,image.cols,CV_8UC1);
    Mat converted_luminosity(image.rows,image.cols,CV_8UC1);
    imshow("original image",image);
    for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            converted_light.at<uchar>(i,j) = (max(image.at<Vec3b>(i,j)[0],
                                                  max(image.at<Vec3b>(i,j)[1],
                                                  image.at<Vec3b>(i,j)[2]))
                                                        +
                                             min(image.at<Vec3b>(i,j)[0],
                                                 min(image.at<Vec3b>(i,j)[1],
                                                 image.at<Vec3b>(i,j)[2]))
                                             )/2;

            converted_average.at<uchar>(i,j) = (image.at<Vec3b>(i,j)[0]+image.at<Vec3b>(i,j)[1]
                                                + image.at<Vec3b>(i,j)[2])/3;

            converted_luminosity.at<uchar>(i,j) = 0.56*image.at<Vec3b>(i,j)[1] + 0.11*image.at<Vec3b>(i,j)[2]
                                                + 0.33*image.at<Vec3b>(i,j)[0];
            //Human eyes are more sensitive to green than other colors, so green is weighted
            //most heavily in this approach.    
            // = .56 G + 0.33 R + 0.11 B 
        											        }
        
    }
    imshow("converted light",converted_light);
    imshow("converted average",converted_light);
    imshow("converted luminosity",converted_luminosity);
    waitKey(0);

}
