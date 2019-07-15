#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//中值滤波
int main()
{
    Mat img = imread("lol4.jpg");
    imshow("原始图", img);
    Mat out;
    medianBlur(img, out, 7);//第三个参数表示孔径的线性尺寸，它的值必须是大于1的奇数
    imshow("中值滤波", out);
    waitKey(0);

}