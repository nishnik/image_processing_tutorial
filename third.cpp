#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <typeinfo>
#include "opencv/cv.h" 
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    Mat image = imread("image.jpg",1);//see this is colored
    imshow("original image",image);
    for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            image.at<Vec3b>(i,j)[0] = 50 + (int)image.at<Vec3b>(i,j)[0];
        											//What if it is more than 255
        }
        
    }
    imshow("modified image",image);//something blues.Karma bitch!
    imwrite("new.jpg",image);//hey this is for writing the image
    							//you can compress the image too.. Check the docs :)
    waitKey(0);

}
