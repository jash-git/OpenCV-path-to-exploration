#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;
using namespace std;

//基本重映射实验

int main()
{
    Mat srcImage = imread("2.jpg");

    if (!srcImage.data)
    {
        cout << "找不到这张图片！" << endl;
        return -1;
    }

    imshow("Src Pic", srcImage);

    Mat dstImage, map_x, map_y;
    dstImage.create(srcImage.size(), srcImage.type());//创建和原图一样的效果图
    map_x.create(srcImage.size(), CV_32FC1);
    map_y.create(srcImage.size(), CV_32FC1);

    //遍历每一个像素点，改变map_x & map_y的值,实现翻转180度
    for (int j = 0; j < srcImage.rows; j++)
    {
        for (int i = 0; i < srcImage.cols; i++)
        {
            map_x.at<float>(j, i) = static_cast<float>(i);
            map_y.at<float>(j, i) = static_cast<float>(srcImage.rows - j);
        }
    }

    //进行重映射操作
    remap(srcImage, dstImage, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
    imshow("重映射效果图", dstImage);  

    waitKey();
    return 0;
}