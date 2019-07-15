#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("lol.jpg");
    if (!srcImage.data)
    {
        cout << "读取原始图失败！" << endl;
        return -1;
    }
    namedWindow("srcImage", WINDOW_NORMAL);// 注意这个宏，使用WINDOW_NORMAL可以允许用户自由伸缩窗口大小
    imshow("srcImage", srcImage);

    Mat logo = imread("dota2.jpg");
    Mat mask = imread("dota2.jpg",0); // 加载掩模（必须是灰度图）  
    if (!logo.data)
    {
        cout << "读取原始logo图失败！" << endl;
        return -1;
    }
    Mat imageROI = srcImage(Rect(28, 41, logo.cols, logo.rows)); //从原图中抠出矩形区域，Rect第一二参数表示矩形左上角定点的坐标，用于定位，后两个参数表示举行的宽和高
    imshow("ROI", imageROI);

    logo.copyTo(imageROI,mask);//注意两个参数，一个是ROI,一个是掩模
    namedWindow("原图加logo", WINDOW_NORMAL);
    imshow("原图加logo", srcImage);
    waitKey();

    return 0;

}