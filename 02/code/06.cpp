#include<opencv2\opencv.hpp>   
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

#define PIC_MAX_NUM 5

int pic_num = 0;

void on_track(int,void*)
{
    char file[10];
    sprintf(file, "lol%d.jpg", pic_num);
    Mat img = imread(file);
    if (!img.data)
    {
        cout << "读取图片失败" << endl;
        return;
    }
    imshow("展示多幅图片", img);
}

int main()
{
    namedWindow("展示多幅图片");
    createTrackbar("图片编号", "展示多幅图片", &pic_num, PIC_MAX_NUM, on_track);
    on_track(pic_num, NULL);
    waitKey(0);

}