#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat srcImage = imread("2.jpg");
    imshow("Src Pic", srcImage);

    Mat midImage, dstImage;

    Canny(srcImage, midImage, 50, 200, 3);
    cvtColor(midImage, dstImage, CV_GRAY2BGR);

    vector<Vec4i> lines;
    //与HoughLines不同的是，HoughLinesP得到lines的是含有直线上点的坐标的，所以下面进行划线时就不再需要自己求出两个点来确定唯一的直线了
    HoughLinesP(midImage, lines, 1, CV_PI / 180, 80, 50, 10);//注意第五个参数，为阈值

    //依次画出每条线段
    for (size_t i = 0; i < lines.size(); i++)
    {
        Vec4i l = lines[i];

        line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, LINE_AA); //Scalar函数用于调节线段颜色

        imshow("边缘检测后的图", midImage);
        imshow("最终效果图", dstImage);
    }
    waitKey();
    return 0;
}
