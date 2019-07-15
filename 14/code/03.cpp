#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("lol16.jpg");  
    Rect r(250, 250, 120, 200);
    rectangle(img, r, Scalar(0, 255, 255), 3);

    imshow("画矩形", img);

    waitKey();
    return 0;
}