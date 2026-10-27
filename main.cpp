#include "include/src.h"
#include <opencv2/opencv.hpp>
int main(){
    char *path = "../image/test01.jpg";
    cv::VideoCapture cap("../image/test.avi");
    cv::Mat frame ;//= cv::imread(path);
     while (cap.read(frame))          // 等价于 cap >> frame
    {
        if (frame.empty())
            break;
        recognize(frame);
    }
    return 0;
}