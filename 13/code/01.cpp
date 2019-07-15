#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    Mat image, mask;
    Rect r1(100, 100, 250, 300);
    Mat img1, img2, img3, img4;
    image = imread("lol17.jpg");
    mask = Mat::zeros(image.size(), CV_8UC1);
    mask(r1).setTo(255);
    img1 = image(r1);
    image.copyTo(img2, mask);

    image.copyTo(img3);
    img3.setTo(0, mask);


    imshow("Image sequence", image);
    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("mask", mask);

    waitKey();
    return 0;
}