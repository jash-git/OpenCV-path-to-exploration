#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    /*访问多通道元素*/
    IplImage* img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
    uchar* data = (uchar *)img->imageData;
    int step = img->widthStep / sizeof(uchar);
    int channels = img->nChannels;
    uchar b, g, r;
    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            //获得元素的值
            b = data[i*step + j*channels + 0];
            g = data[i*step + j*channels + 1];
            r = data[i*step + j*channels + 2];

            //修改元素的值
            data[i*step + j*channels + 0] = 255;
        }
    }

    cvShowImage("img", img);


    /*访问单通道元素*/
    IplImage* img2 = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
    uchar* data2 = (uchar *)img2->imageData;
    int step2 = img2->widthStep / sizeof(uchar);
    uchar v;
    for (int i = 0; i < img2->height; i++)
    {
        for (int j = 0; j < img2->width; j++)
        {
            //获得元素的值
            v = data2[i*step2 + j];

            //修改元素的值
            data2[i*step2 + j] = 255;
        }
    }

    cvShowImage("img2", img2);



    waitKey(0);
    return 0;
}