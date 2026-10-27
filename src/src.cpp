#include "../include/src.h"
#include <opencv2/opencv.hpp>
int recognize(cv::Mat& image){
    // cv::Mat image = cv::imread(path);
    cv::Mat vis = image.clone();
    cv::cvtColor(vis, vis, cv::COLOR_BGR2GRAY);
    cv::threshold(vis, vis, 127/*还要再改*/, 255, cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(vis, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::drawContours(vis, contours, 1, 127, 2); 
    std::vector<cv::Point> contours_all;
    for(int j = 0; j < contours.size(); j++){
        for(int i = 0; i < contours[j].size(); i++){
            contours_all.push_back(contours[j][i]);
        }
    }
    cv::RotatedRect rect = cv::minAreaRect(contours_all);
    cv::Point2f vertices[4];
    rect.points(vertices);
    for (int i = 0; i < 4; i++){
        cv::line(image, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
    }
    cv::imshow("Display window", image);
    cv::waitKey(0);
    return 0;
}
