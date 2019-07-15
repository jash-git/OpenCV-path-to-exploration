#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define PIC_BEGIN_NUM 100  //这里定义你的起始图片编号
#define ANGLE_START -45  //旋转角度的开始
#define ANGLE_END  0  //旋转角度的结束 
#define ANGLE_STEP 2 //旋转角度步长

int main(int argc, char **argv)
{
    //Read a single-channel image
    const char* filename = "lol9.jpg";
    Mat srcImg = imread(filename, 1);
    imshow("source", srcImg);
    Point center(srcImg.cols / 2, srcImg.rows / 2); //图片中心为旋转点
    char file[20];
    int count = PIC_BEGIN_NUM; 
    Mat tmpimg; 
    for (int tmp = ANGLE_START; tmp < ANGLE_END; tmp += ANGLE_STEP)
    {
        Mat rotMatS = getRotationMatrix2D(center, tmp, 0.5); //图片缩小到原来的0.5倍
        warpAffine(srcImg, tmpimg, rotMatS, srcImg.size(), 1, 0, Scalar(0, 0, 0));//填充黑色背景                                                                           
        sprintf(file, "%d.jpg", count++);  //旋转图片以1.jpg  2.jpg 的名字格式保存
        imwrite(file, tmpimg);
    }

    waitKey(0);

    return 0;
}