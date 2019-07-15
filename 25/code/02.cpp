#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>


#define  DATA_DIR ".\\cut256\\"
#define  IM_ROWS  5106
#define  IM_COLS  15106
#define  ROI_SIZE 256

using namespace cv;
using namespace std;

Point ptL, ptR; //鼠标画出矩形框的起点和终点,矩形的左下角和右下角
Mat imageSource, imageSourceCopy;
FILE* fp_result;


struct UserData
{
    Mat src;
    vector<Rect> rect;
};


void OnMouse(int event, int x, int y, int flag, void *dp)
{
    UserData *d = (UserData *)dp;
    imageSourceCopy = imageSource.clone();

    if (event == CV_EVENT_LBUTTONDOWN)  //按下鼠标右键，即拖动开始
    {
        ptL = Point(x, y);
        ptR = Point(x, y);
    }
    if (flag == CV_EVENT_FLAG_LBUTTON)   //拖拽鼠标右键，即拖动进行
    {
        ptR = Point(x, y);
        imageSourceCopy = imageSource.clone();
        rectangle(imageSourceCopy, ptL, ptR, Scalar(0, 255, 0));
        imshow("标注", imageSourceCopy);
        
    }
    if (event == CV_EVENT_LBUTTONUP)  //拖动结束
    {
        if (ptL != ptR)
        {
            rectangle(imageSourceCopy, ptL, ptR, Scalar(0, 255, 0));
            imshow("标注", imageSourceCopy);

            int h = ptR.y - ptL.y;
            int w = ptR.x - ptL.x;


            printf("选择的信息区域是:x:%d  y:%d  w:%d  h:%d\n", ptL.x, ptL.y, w, h);

            d->rect.push_back(Rect(ptL.x, ptL.y, w, h));
            //d->src(imageSourceCopy);
        }
    }

    //点击右键删除一个矩形
    if (event == CV_EVENT_RBUTTONDOWN)
    {
        if (d->rect.size() > 0)
        {
            Rect temp = d->rect.back();

            printf("删除的信息区域是:x:%d  y:%d  w:%d  h:%d\n", temp.x, temp.y, temp.width, temp.height);
            d->rect.pop_back();

            for (int i = 0; i < d->rect.size(); i++)
            {
                rectangle(imageSourceCopy, d->rect[i], Scalar(0, 255, 0), 1);
            }
                      
        }
    }

}


void DrawArea(Mat& src, string img_name, string path_name)
{
    Mat img = src.clone();
    char c = 'x';
    UserData d;
    d.src = img.clone();
    while (c != 'n')
    {
        Mat backup = src.clone();
        imageSource = img.clone();
        
        namedWindow("标注", 1);
        imshow("标注", imageSource);
        setMouseCallback("标注", OnMouse, &d);

        c = waitKey(0);

        if (c == 'a')
        {
            printf("rect size: %d\n", d.rect.size());
            for (int i = 0; i < d.rect.size(); i++)
            {
                rectangle(backup, d.rect[i], Scalar(0, 255, 0), 1);
            }

            img = backup.clone();
            
        }
    }

    fprintf(fp_result, "%s\n", img_name.c_str());
    fprintf(fp_result, "%d\n", d.rect.size());
    for (int i = 0; i < d.rect.size(); i++)
    {
        Rect t = d.rect[i];

        fprintf(fp_result, "%d %d %d %d\n", t.x, t.y, t.width, t.height);
    }

    imwrite(path_name, img);
    

}
int main()
{
    FILE* fp;
    fp = fopen("start.txt", "r");
    int start_i = 0;
    int start_j = 0;
    fscanf(fp, "%d %d", &start_i, &start_j);
    fclose(fp);

    fp_result = fopen("record.txt", "a+");

    printf("start_i: %d, start_j: %d\n", start_i, start_j);


    /*循环读取图片来标注*/
    for (int i = start_i; i< IM_ROWS / ROI_SIZE + 1; i++)
    {
        for (int j = start_j; j<IM_COLS / ROI_SIZE; j++)
        {
            stringstream ss1, ss2;

            ss1 << DATA_DIR << "2017\\" << i << "_" << j << "_" << ROI_SIZE << "_.jpg";
            ss2 << DATA_DIR << "label_img\\" << i << "_" << j << "_" << ROI_SIZE << "_.jpg";
            cout << ss1.str() << endl;
            string str(ss1.str());
            string str2(ss2.str());
            cv::Mat src = cv::imread(ss1.str());

            DrawArea(src, str,str2);

       
        }

    }
    fclose(fp_result);
    return 0;
}