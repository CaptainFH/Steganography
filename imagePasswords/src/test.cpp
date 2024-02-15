#include <stdlib.h>
#include<iostream>
#include "opencv2/opencv.hpp" //Try with just the #include"opencv2/opencv.hpp""

using namespace cv;

//A Few practice functions to remmenber how to manipulate Mat's from: https://cadubentzen.github.io/pdi-ufrn/print.html

void negative(Mat* image){
    int rows = image->rows;
    int colms = image->cols;
     std::cout << "image rows: " << rows << "\n" << "image colms: " << colms << std::endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colms; j++){
            image->at<Vec3b>(i,j)[0] = 255 - image->at<Vec3b>(i,j)[0];
            image->at<Vec3b>(i,j)[1] = 255 - image->at<Vec3b>(i,j)[1];
            image->at<Vec3b>(i,j)[2] = 255 - image->at<Vec3b>(i,j)[2];
        }
    }
}
//Reminder that rows and colmns are reverted in the image at lmfao
void negativeArea(Mat* image){
    int rows = image->rows;
    int colms = image->cols;
    int fromRow = 0;
    int toRow = 250;
    int fromColm = 0;
    int toColm = 250;
    std::cout << "image rows: " << rows << "\n" << "image colms: " << colms << "\n" 
    << "Altering from row: "  << fromRow << " To " << toRow << "\n" <<"Altering from colms: " << fromColm << " To " << toColm << std::endl;
    for(int i = fromRow; i < toRow; i++){
        for(int j = fromColm; j < toColm; j++){
            image->at<Vec3b>(i,j)[0] = 255 - image->at<Vec3b>(i,j)[0];
            image->at<Vec3b>(i,j)[1] = 255 - image->at<Vec3b>(i,j)[1];
            image->at<Vec3b>(i,j)[2] = 255 - image->at<Vec3b>(i,j)[2];
        }
    }
}

int main(int argc, char** argv){
    std::cout << "Remmenber?" << std::endl;
    std::cout << CV_VERSION << std::endl;


    cv::Mat image = cv::imread("C:/Users/Ferna_x2g7ic9/Pictures/pfp.jpg");
    cv::namedWindow("Test display", cv::WINDOW_AUTOSIZE);
    cv::imshow("Test display", image);
    cv::waitKey(0);
    negative(&image);
    cv::imshow("Test display", image);
    cv::waitKey(0);
    return 0;
}
