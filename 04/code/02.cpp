﻿include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//腐蚀
int main()
{
    Mat img = imread("lol1.jpg");
    namedWindow("原始图", WINDOW_NORMAL);
    imshow("原始图", img);
    Mat out;
    //获取自定义核
    Mat element = getStructuringElement(MORPH_RECT, Size(15, 15)); //第一个参数MORPH_RECT表示矩形的卷积核，当然还可以选择椭圆形的、交叉型的
    //腐蚀操作
    erode(img, out, element);
    namedWindow("腐蚀操作", WINDOW_NORMAL);
    imshow("腐蚀操作", out);
    waitKey(0);

}