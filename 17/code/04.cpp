#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    /*访问单通道元素*/
    IplImage* img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1); //单通道图像
    CvScalar s;
    double tmp;
    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            //可以在这里访问元素
            tmp = cvGet2D(img, i, j).val[0];
            cvSet2D(img, i, j, 255);  //第三个参数是要设置的值
        }
    }
    cvShowImage("img", img);


    /*访问多通道元素*/
    IplImage* img2 = cvCreateImage(cvSize(640, 480), IPL_DEPTH_32F, 3);
    double tmpb, tmpg, tmpr;
    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            tmpb = cvGet2D(img, i, j).val[0];
            tmpg = cvGet2D(img, i, j).val[1];
            tmpr = cvGet2D(img, i, j).val[2];

            cvSet2D(img2, i, j, CvScalar(255,255,255));  //第三个参数是要设置的值,三个通道一起设置
        }
    }
    cvShowImage("img2", img2);

    waitKey(0);
    return 0;
}