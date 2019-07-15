#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    //导入图像
    Mat img1 = imread("lol0.jpg", 1);
    Mat img2(img1.rows, img1.cols, CV_8UC3);

    //设置感兴趣区域,拷贝
    img1(Rect(500, 31, 200, 250)).copyTo(img2);

    //当然也可以这样
    //Mat roi = img1(Rect(0,0,100,100));
    //imshow("roi",roi);

    //显示
    imshow("img1", img1);
    imshow("img2", img2);
    waitKey(0);

}