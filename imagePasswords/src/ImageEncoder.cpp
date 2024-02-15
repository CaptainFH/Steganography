#include <stdlib.h>
#include<iostream>
#include "opencv2/opencv.hpp" 

using namespace cv;

//In fact - it let's just change the values we know from the top left of the image- to see if the idea works.
void encoder(std::string password, Mat* image){
    for(int i = 0; i < password.length(); i++){
        image->at<Vec3b>(0,i)[0] = password[i];
    }
    image->at<Vec3b>(image->cols-1, image->cols-1)[0] = password.length();
}

std::string decode(Mat* image){
    int passwordSize = image->at<Vec3b>(image->cols-1, image->cols-1)[0];
    std::string result = "";
    for(int i = 0; i < passwordSize; i++){
        std::cout<< result << std::endl;
        result = result +  (char) image->at<Vec3b>(0,i)[0]; 
    }
    return result;
}


int main(int argc, char** argv){
    Mat testImage = imread("C:/Users/Ferna_x2g7ic9/Pictures/password.png");
    std::string password = "pass";
    cv::namedWindow("Test display", cv::WINDOW_AUTOSIZE);
    cv::imshow("Test display", testImage);
     std::cout << decode(&testImage) << std::endl;
    cv::waitKey(0);
    encoder(password, &testImage);
    cv::imshow("Test display", testImage);
    std::cout << decode(&testImage) << std::endl;
    cv::waitKey(0);

    imwrite("C:/Users/Ferna_x2g7ic9/Pictures/password.png", testImage);
    testImage = imread("C:/Users/Ferna_x2g7ic9/Pictures/password.png");
    std::cout << decode(&testImage) << std::endl;
    return 0;
}