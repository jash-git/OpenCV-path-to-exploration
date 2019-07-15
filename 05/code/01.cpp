#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//图片的缩小与放大
int main()
{
    Mat img = imread("lol5.jpg");
    imshow("原始图", img);

    Mat dst = Mat::zeros(512, 512, CV_8UC3); //我要转化为512*512大小的
    resize(img, dst, dst.size());

    imshow("尺寸调整之后", dst);

    waitKey(0);

}
