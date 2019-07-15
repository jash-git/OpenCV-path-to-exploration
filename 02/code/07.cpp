#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;


int main()
{
    Mat img = imread("lol1.jpg");
    Mat dstImg;
    cvtColor(img, dstImg,COLOR_BGR2GRAY);//从宏名字就可以知道，是彩色图转换到灰度图
    imshow("灰度图", dstImg);

    waitKey(0);

}