#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
    Mat SrcPic = imread("lena.jpg");
    imshow("Src Pic", SrcPic);
    Mat DstPic, edge, grayImage;

    //创建与src同类型和同大小的矩阵
    DstPic.create(SrcPic.size(), SrcPic.type());
    
    //将原始图转化为灰度图
    cvtColor(SrcPic, grayImage, COLOR_BGR2GRAY);

    //先使用3*3内核来降噪
    blur(grayImage, edge, Size(3, 3));

    //运行canny算子
    Canny(edge, edge, 3, 9, 3);

    imshow("边缘提取效果", edge);

    waitKey();
    return 0;
}