// Example 2-2. Same as Example 2-1 but employing the ¡°using namespace¡± directive
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
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
