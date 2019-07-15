#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("lol16.jpg");  
    int thickness = 3;
    int lineType = 8;
    double angle = 30;  //椭圆旋转角度
    //第三个参数Size中的两个参数分别是横轴长、纵轴长。
    //同理，thickness若是小于0，表示实心
    ellipse(img,Point(100, 100),Size(90, 60),angle,0,360,Scalar(255, 255, 0),thickness,lineType);

    imshow("画椭圆", img);

    waitKey();
    return 0;
}
