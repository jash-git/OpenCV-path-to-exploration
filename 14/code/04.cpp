#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("lol16.jpg");  
    Point p1(100, 100);
    Point p2(758, 50);
    line(img, p1, p2, Scalar(33, 33, 133), 2);

    //画第二条线
    line(img, Point(300, 300), Point(758, 300), Scalar(89, 90, 90), 3);

    imshow("画矩形", img);

    waitKey();
    return 0;
}