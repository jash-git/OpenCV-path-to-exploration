#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("lol0.jpg");
    if (!srcImage.data)
    {
        cout << "读取原始图失败！" << endl;
        return -1;
    }

    rectangle(srcImage, Rect(0, 0, 600, 200), Scalar(0, 255, 0),2); //将感兴趣区域框出来
    imshow("ROI", srcImage);
    waitKey();

    return 0;

}