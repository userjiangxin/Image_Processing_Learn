#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
int main()
{
	string videopath = "tree.avi";
	cv::namedWindow("Example 2-3", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap;

	cap.open(videopath);
	
	//cout << "Opened file: " << videopath << endl;

	cv::Mat frame;
	
	for (;;)
	{
		cap >> frame;
		if (frame.empty()) break;// Ran out of film

		cv::imshow("Example 2-3", frame);
		if ((char)cv::waitKey(33) >= 0) break;
		
	}
	return 0;
}