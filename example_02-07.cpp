// Example 2-7. The Canny edge detector writes its output to a single-channel (grayscale) image
// 2
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
int main()
{
	string imgpath = "fruits.jpg";
	cv::Mat img_rgb, img_gry,img_cny;

	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread(imgpath);
	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Example Gray", img_gry);

	cv::Canny(img_gry, img_cny, 10, 100, 3, true);
	cv::imshow("Example Canny", img_cny);

	cv::waitKey(0);

	return 0;
}