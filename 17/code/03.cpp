#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat img = imread("lena.jpg",1); 
    Mat img1 = img.clone();
    int div = 64;
    /* 方法3：用at访问 */

    /****************访问多通道元素*********************/
    int rows = img1.rows;
    int cols = img1.cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //在这里访问每个通道的元素,注意，成员函数at(int y,int x)的参数
            img1.at<Vec3b>(i,j)[0] = img1.at<Vec3b>(i, j)[0] / div*div + div / 2;
            img1.at<Vec3b>(i, j)[1] = img1.at<Vec3b>(i, j)[1] / div*div + div / 2;
            img1.at<Vec3b>(i, j)[2] = img1.at<Vec3b>(i, j)[2] / div*div + div / 2;

        }
    }

    imshow("lena", img1);

    /****************访问单通道元素*********************/
    Mat img2;
    cvtColor(img, img2, COLOR_RGB2GRAY);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //在这里访问每个通道的元素,注意，成员函数at(int y,int x)的参数
            img2.at<uchar>(i, j) = img2.at<uchar>(i, j) / div*div + div / 2;
        }
    }

    imshow("lena2", img2);

    waitKey(0);
    return 0;
}