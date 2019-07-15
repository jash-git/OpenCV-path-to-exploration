﻿#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat srcImage = imread("test5.jpg");  
    Mat midImage, dstImage;//临时变量和目标图的定义  

    imshow("【原始图】", srcImage);

    //【3】转为灰度图，进行图像平滑  
    cvtColor(srcImage, midImage, CV_BGR2GRAY);//转化边缘检测后的图为灰度图  
    GaussianBlur(midImage, midImage, Size(9, 9), 2, 2);

    //【4】进行霍夫圆变换  
    vector<Vec3f> circles;
    HoughCircles(midImage, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 150, 0, 0); //注意第七的参数为阈值，可以自行调整，值越大，检测的圆更精准

    //【5】依次在图中绘制出圆  
    for (size_t i = 0; i < circles.size(); i++)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        //绘制圆心  
        circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
        //绘制圆轮廓  
        circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
    }

    //【6】显示效果图    
    imshow("【效果图】", srcImage);

    waitKey(0);

    return 0;
}