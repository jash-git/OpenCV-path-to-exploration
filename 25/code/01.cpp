#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

#define  DATA_DIR ".\\dataset\\"
#define  IMG_MAX_NUM  20


using namespace cv;
using namespace std;

int main()
{
    FILE* fp;
    FILE* fp_result;
    fp = fopen("start.txt", "r");  //读取开始的图片名字，方便从某一图片开始标注
    int start_i = 0;
    fscanf(fp, "%d", &start_i);
    fclose(fp);

    fp_result = fopen("classify_record.txt", "a+");   //用于记录每张图每个框的标注信息

    printf("start_i: %d\n", start_i);

    /*循环读取图片来标注*/
    for (int i = start_i; i < IMG_MAX_NUM; i++)
    {
        stringstream ss1,ss2,ss3;

        ss1 << DATA_DIR <<"data\\"<< i << ".jpg";
        ss3 << i << ".jpg";
        Mat src = imread(ss1.str());
        if (src.empty())
        {
            continue;
        }
        printf("正在操作的图像: %s\n", string(ss1.str()).c_str());
        
        imshow("标注", src);

        char c = 0;
        c = waitKey(0);
        while ( c != '1' && c != '2' && c != '3')  
        {
            c = waitKey(0);
            printf("invaid input!\n");
        }

        ss2 << DATA_DIR << c << "\\" << i << ".jpg";

        char type = c - '0';
        printf("分类为: %d\n", c - '0');  
        imwrite(ss2.str(), src);   //copy一份到对应类别的文件夹
        fprintf(fp_result, "%s %d\n", string(ss3.str()).c_str(), type);
    }
    

    fclose(fp_result);
    return 0;
}