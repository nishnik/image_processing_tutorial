#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <typeinfo>
#include "opencv/cv.h" 
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    
    Mat grayscale = imread("image.jpg",CV_LOAD_IMAGE_GRAYSCALE );
    //you can also write 0 instead of this CV_LOAD_IMAGE_GRAYSCALE
    //this loads the image in grayscale [no colors, only different shades of gray]
    Mat color = imread("image.jpg",CV_LOAD_IMAGE_COLOR);
    //you can also write 1 instead of this CV_LOAD_IMAGE_COLOR
    //this loads the image in BGR colorspace [note the BGR.. it can be confusing]
    //there is also one thing, -1 which is there for CV_LOAD_IMAGE_UNCHANGED
    //well try to know about this on your own :)
    
    namedWindow( "grayscale_image", WINDOW_AUTOSIZE );
    namedWindow( "color_image", WINDOW_AUTOSIZE );
    //Oh you can infer from the name what it does
    
    imshow("grayscale_image", grayscale);
    imshow("color_image", color);
    //This one is the prestige ;)
    //loads the image in the specified window
    
    waitKey(0); 
    //now this is really important
    //this 0 stands for infinite amount of time your image will be shown
    //the way to end the image window is to press any key
    //apart from it you can enter different values instad of 0 and the image window
    //will be there until you press the key or the [value]milliseconds have elapsed.
    //try a negative value :p Are you seriously trying to do time travel ?
    
    return 0;
    //What is this return 0 by the way ?
    

}
