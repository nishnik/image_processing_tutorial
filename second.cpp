#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <typeinfo>
#include "opencv/cv.h" 
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    Mat grayscale = imread("image.jpg",0);//see this is grayscale
    imshow("original image",grayscale);
    for(int i=0;i<grayscale.rows;i++)
    {
        for(int j=0;j<grayscale.cols;j++)
        {
            cout<<(int)grayscale.at<uchar>(i,j)<<" ";//see this uchar is for the grayscale image..
                                                    // there is something different for color image
                                                    // do you know something called channels
                                                    //this is what your computer thinks about your image
                                                    //So! Geeky :p
                                                    //So much gibberish values on screen
        	grayscale.at<uchar>(i,j) = 10 + (int)grayscale.at<uchar>(i,j);
        											//What if it is more than 255
        }
        
    }
    imshow("modified image",grayscale);//something more brighter.Karma bitch!
    imwrite("new.jpg",grayscale);//hey this is for writing the image
    							//you can compress the image too.. Check the docs :)
    waitKey(0);

}
