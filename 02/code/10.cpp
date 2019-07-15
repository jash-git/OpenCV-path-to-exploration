#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//直方图均衡化
int main()
{
    Mat img = imread("lol3.jpg");
    imshow("原始图", img);
    Mat dst;
    cvtColor(img, img, CV_RGB2GRAY);
    imshow("灰度图", img);
    equalizeHist(img, dst);

    imshow("直方图均衡化", dst);

    waitKey(0);

}