#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;


int main()
{
    Mat img = imread("lol4.jpg");
    imshow("原始图", img);
    Mat out;
    boxFilter(img, out, -1, Size(5, 5));//-1指原图深度
    imshow("方框滤波", out);
    waitKey(0);

}