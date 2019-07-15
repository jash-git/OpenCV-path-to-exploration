#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//图像金字塔
int main()
{
    Mat img = imread("lol8.jpg");
    imshow("原始图", img);

    Mat dst,dst2;
    pyrUp(img, dst, Size(img.cols*2, img.rows*2)); //放大一倍
    pyrDown(img, dst2, Size(img.cols * 0.5, img.rows * 0.5)); //缩小为原来的一半
    imshow("尺寸放大之后", dst);
    imshow("尺寸缩小之后", dst2);

    waitKey(0);

}