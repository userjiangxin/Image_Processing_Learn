//Example 2-1. A simple OpenCV program that loads an image from disk and displays it
//on the screen
#include <opencv2/opencv.hpp>

int main()
{
	std::string imgpath = "fruits.jpg";
	cv::Mat img = cv::imread(imgpath, -1);

	if (img.empty())return -1;
	
	cv::namedWindow("Example 2-1", cv::WINDOW_AUTOSIZE);
	cv::imshow("Example 2-1", img);
	cv::waitKey(0);
	cv::destroyWindow("Example 2-1");

	return 0;
}
