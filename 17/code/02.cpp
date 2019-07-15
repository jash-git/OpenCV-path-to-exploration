#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat img = imread("lena.jpg",1); //载入灰度图
    Mat img1 = img.clone();
    int div = 64;
    /* 方法2：用迭代器访问 */

    /******************多通道的可以这么写***************/
    Mat_<Vec3b>::iterator it = img1.begin<Vec3b>();  //获取起始迭代器
    Mat_<Vec3b>::iterator it_end = img1.end<Vec3b>();  //获取结束迭代器
    for (; it != it_end; it++)
    {
        //在这里分别访问每个通道的元素
        (*it)[0] = (*it)[0] / div*div + div / 2;
        (*it)[1] = (*it)[1] / div*div + div / 2;
        (*it)[1] = (*it)[1] / div*div + div / 2;
    }

    imshow("lean", img1);


    /******************单通道的可以这么写***************/
    Mat img2;
    cvtColor(img, img2, COLOR_RGB2GRAY); //转化为单通道灰度图

    Mat_<uchar>::iterator it2 = img2.begin<uchar>();  //获取起始迭代器
    Mat_<uchar>::iterator it_end2 = img2.end<uchar>();  //获取结束迭代器
    for (; it2 != it_end2; it2++)
    {
            //在这里分别访问每个通道的元素
            *it2 = *it2 / div*div + div / 2;
    }
    imshow("lena2", img2);

    waitKey(0);
    return 0;
}
}