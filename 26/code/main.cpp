#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"


using namespace cv;


int main()
{

    Mat src = imread("100.bmp");
    //resize(src, src, Size(700, 500));
    Mat gray;
    cvtColor(src, gray, CV_RGB2GRAY);
    if (src.empty())
    {
        printf("fail to open image!\n");
        return -1;
    }

    // 全局二值化
    int th = 180; //阈值要根据实际情况调整
    Mat binary;
    threshold(gray, binary, th, 255, CV_THRESH_BINARY);


    vector<Mat> channels;
    split(src, channels);
    Mat red = channels[2];
    Mat blue = channels[0];
    Mat green = channels[1];

    Mat red_binary;
    threshold(red, red_binary, th, 255, CV_THRESH_BINARY);

    imshow("src", src);
    imshow("gray", gray);
    imshow("binary", binary);
    imshow("red channel", red);
    imshow("blue channel", blue);
    imshow("green channel", green);
    imshow("red+binary", red_binary);

    waitKey();


    return 0;
}