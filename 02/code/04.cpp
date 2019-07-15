#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
    Mat SrcPic = imread("lena.jpg");
    imshow("Src Pic", SrcPic);
    Mat DstPic;
    blur(SrcPic, DstPic, Size(7, 7));
    imshow("均值模糊效果图", DstPic);
    waitKey();
    return 0;
}
