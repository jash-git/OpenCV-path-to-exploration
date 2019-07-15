#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat img = imread("lena.jpg", 1); 
    if (img.empty())
    {
        cout << "fail to read image" << endl;
        return -1;
    }
    Mat img1 = img.clone();
    int div = 64;

    /* 方法1：用指针访问 */
    //多通道访问法1
    int rows = img1.rows;
    int cols = img1.cols; 
    for (int i = 0; i < rows; i++)
    {
        //uchar* p = img1.ptr<uchar>(i);  //获取第i行的首地址
        for (int j = 0; j < cols; j++)
        {
            //在这里操作具体元素
            uchar *p = img1.ptr<uchar>(i, j);
            p[0] = p[0] / div*div + div / 2;
            p[1] = p[1] / div*div + div / 2;
            p[2] = p[2] / div*div + div / 2;
        }
    }

    imshow("lean", img1);


    //多通道访问法2
    Mat img3 = img.clone();
    int channels = img3.channels(); //获取通道数
    int rows3 = img3.rows;
    int cols3 = img3.cols* channels; //注意，是列数*通道数
    for (int i = 0; i < rows3; i++)
    {
        uchar* p = img3.ptr<uchar>(i);  //获取第i行的首地址
        for (int j = 0; j < cols3; j++)
        {
            //在这里操作具体元素
            p[j] = p[j] / div*div + div / 2;
            p[j+1] = p[j+1] / div*div + div / 2;
            p[j+2] = p[j+2] / div*div + div / 2;
        }
    }

    imshow("lean3", img3);

    //单通道图像
    Mat img2 = img.clone();
    cvtColor(img2, img2, COLOR_BGR2GRAY);
    for (int i = 0; i < img2.rows; i++)
    {
        uchar* p = img2.ptr<uchar>(i);  //获取第i行的首地址
        for (int j = 0; j < img2.cols; j++)
        {
            //在这里操作具体元素
            p[j] = p[j] / div*div + div / 2;
        }
    }

    imshow("lean2", img2);
    waitKey(0);
    return 0;
}