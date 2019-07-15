#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//图片的缩小与放大
int main()
{
    Mat img = imread("lol5.jpg");
    imshow("原始图", img);

    Mat dst;
    resize(img, dst, Size(),0.5,0.5);//我长宽都变为原来的0.5倍

    imshow("尺寸调整之后", dst);

    waitKey(0);

}
