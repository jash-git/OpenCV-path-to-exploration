#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//双边滤波
int main()
{
    Mat img = imread("lol4.jpg");
    imshow("原始图", img);
    Mat out;
    bilateralFilter(img, out, 25, 25 * 2, 25 / 2);
    imshow("双边滤波", out);
    waitKey(0);

}