﻿#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
       //这些方式都是自己拥有独立的内存空间
    Mat img1(2, 2, CV_8UC3, Scalar(0, 0, 255));
    cout << img1 << endl;

    int sz[3] = { 2,2,2 };
    Mat img2(3, sz, CV_8UC1, Scalar(0, 0, 0));
    //cout << img2 << endl;

    Mat img5;
    img5.create(4, 4, CV_8UC3);
    cout << img5 << endl;

    Mat img6 = Mat::zeros(4, 4, CV_8UC3);
    cout << img6 << endl;

    Mat img7 = img6.clone();
    cout << img7 << endl;

    Mat img8;
    img6.copyTo(img8);
    cout << img8 << endl;
    
    //下面都是浅拷贝，指针指向同一个实例
    Mat img9 = img8;
    Mat img10(img8);

    waitKey(0);
    return 0;
}