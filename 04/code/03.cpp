#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

//高级形态学处理
int main()
{
    Mat img = imread("lol1.jpg");
    namedWindow("原始图", WINDOW_NORMAL);
    imshow("原始图", img);
    Mat out;
    //获取自定义核
    Mat element = getStructuringElement(MORPH_RECT, Size(15, 15)); //第一个参数MORPH_RECT表示矩形的卷积核，当然还可以选择椭圆形的、交叉型的
        
    //高级形态学处理，调用这个函数就可以了，具体要选择哪种操作，就修改第三个参数就可以了。这里演示的是形态学梯度处理
    morphologyEx(img, out, MORPH_GRADIENT, element);
    namedWindow("形态学处理操作", WINDOW_NORMAL);
    imshow("形态学处理操作", out);
    waitKey(0);

}