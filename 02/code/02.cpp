#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat image = imread("lol1.jpg", CV_LOAD_IMAGE_GRAYSCALE); //注意了，必须是载入灰度图
    if (image.empty())
    {
        cout << "read image failure" << endl;
        return -1;
    }

    // 全局二值化
    int th = 100;
    Mat global;
    threshold(image, global, th, 255, CV_THRESH_BINARY_INV);

    // 局部二值化
    int blockSize = 25;
    int constValue = 10;
    Mat local;
    adaptiveThreshold(image, local, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY_INV, blockSize, constValue);

    imshow("全局二值化", global);
    imshow("局部二值化", local);

    waitKey(0);
    return 0;
}