#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;


int main()
{
    Mat img = imread("lol4.jpg");
    imshow("原始图", img);
    Mat out;
    GaussianBlur(img, out, Size(3, 3), 0, 0);
    imshow("高斯滤波", out);
    waitKey(0);

}