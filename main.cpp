#include <opencv2/opencv.hpp>
int main(){
    cv::Mat image = cv::imread("../test.jpg");
    cv::imshow("Display window", image);
    cv::waitKey(0);
    return 0;
}