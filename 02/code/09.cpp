#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//访问每个像素,我喜欢使用指针的方式
int main()
{
    Mat img = imread("lol1.jpg");
    for (int i = 0; i < img.rows; i++)
    {
        uchar* data = img.ptr<uchar>(i);  //获取第i行地址
        for (int j = 0; j < img.cols; j++)
        {
             printf("%d\n",data[j]);
        }
    }

    waitKey(0);

}