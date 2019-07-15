#include <iostream>
#include <sstream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;

#define  DATA_DIR ".\\cut256\\"

#define  IM_ROWS  5106
#define  IM_COLS  15106
#define  ROI_SIZE 256
struct UserData
{
    cv::Mat src;
    vector<cv::Point> pts;
};

FILE* fpts_set;

void on_mouse(int event, int x, int y, int flags, void *dp)
{
    UserData *d = (UserData *)dp;
    if (event == CV_EVENT_LBUTTONDOWN)
    {
        d->pts.push_back(cv::Point(x, y));
    }
    if (event == CV_EVENT_RBUTTONDOWN)
    {
        if (d->pts.size()>0)
            d->pts.pop_back();
    }
    cv::Mat temp = d->src.clone();
    if (d->pts.size()>2)
    {
        const cv::Point* ppt[1] = { &d->pts[0] };
        int npt[] = { static_cast<int>(d->pts.size()) };
        cv::fillPoly(temp, ppt, npt, 1, cv::Scalar(0, 0, 255), 16);

    }
    for (int i = 0; i<d->pts.size(); i++)
    {
        cv::circle(temp, d->pts[i], 1, cv::Scalar(0, 0, 255), 1, 16);
    }
    cv::circle(temp, cv::Point(x, y), 1, cv::Scalar(0, 255, 0), 1, 16);
    cv::imshow("2017", temp);

}

void WriteTxT(vector<cv::Point>& pst)
{
    for (int i = 0; i < pst.size(); i++)
    {
        fprintf(fpts_set, "%d %d", pst[i].x, pst[i].y);
        if (i == pst.size() - 1)
        {
            fprintf(fpts_set, "\n");
        }
        else
        {
            fprintf(fpts_set, " ");
        }
    }
}

int label_img(cv::Mat &src, cv::Mat &mask, string& name)
{
    char c = 'x';

    vector<vector<cv::Point> > poly_point_set;

    while (c != 'n')
    {
        UserData d;
        d.src = src.clone();

        cv::namedWindow("2017", 1);
        cv::setMouseCallback("2017", on_mouse, &d);
        cv::imshow("2017", src);
        c = cv::waitKey(0);
        if (c == 'a')
        {
            if (d.pts.size()>0)
            {
                const cv::Point* ppt[1] = { &d.pts[0] };
                int npt[] = { static_cast<int>(d.pts.size()) };
                cv::fillPoly(src, ppt, npt, 1, cv::Scalar(0, 0, 255), 16);
                cv::fillPoly(mask, ppt, npt, 1, cv::Scalar(255), 16);
                poly_point_set.push_back(d.pts);
            }


        }
    }

    fprintf(stdout, "%s %d\n", name.c_str(), poly_point_set.size());
    fprintf(fpts_set, "%s %d\n", name.c_str(), poly_point_set.size());

    //将点集写入文件
    for (int i = 0; i < poly_point_set.size(); i++)
    {
        WriteTxT(poly_point_set[i]);
    }

    return 0;
}
int main()
{
    FILE* fp;
    fp = fopen("start.txt", "r");
    int start_i = 0;
    int start_j = 0;
    fscanf(fp, "%d %d", &start_i, &start_j);
    fclose(fp);

    fpts_set = fopen("semantic_label.txt", "a+");

    printf("start_i: %d, start_j: %d\n", start_i, start_j);

    for (int i = start_i; i<IM_ROWS / ROI_SIZE + 1; i++)
    {
        for (int j = start_j; j<IM_COLS / ROI_SIZE; j++)
        {
            stringstream ss1,ss2,ss3;
            cv::Mat mask(256, 256, CV_8UC1);
            mask.setTo(0);

            ss1 << DATA_DIR << "2017\\" << i << "_" << j << "_" << ROI_SIZE << "_.jpg";
            ss2 << DATA_DIR << "label\\" << i << "_" << j << "_" << ROI_SIZE << "_.jpg";
            ss3 << i << "_" << j << "_" << ROI_SIZE << "_.jpg";
            cout << ss1.str() << endl;

            cv::Mat src = cv::imread(ss1.str());

            label_img(src, mask, string(ss3.str()));// label based on tiny
            cv::imwrite(ss2.str(), mask);
        }

    }

    fclose(fpts_set);
    return 0;
}