#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main()
{
	string videopath = "big_buck_bunny.mp4";
	string outvideo = "out.mp4";
	cv::namedWindow("Example 2-11", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

	// ( Note: could capture from a camera by giving a camera id as an int.)
	//
	cv::VideoCapture capture(videopath);
	double fps = capture.get(cv::CAP_PROP_FPS);

	cv::Size size((int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)capture.get(cv::CAP_PROP_FRAME_HEIGHT));

	cv::VideoWriter writer;
	writer.open(outvideo, cv::VideoWriter::fourcc('X', 'V', 'I', 'D'), fps, size);

	cv::Mat logpolar_frame, bgr_frame;

	for (;;) 
	{
		capture >> bgr_frame;
		if (bgr_frame.empty()) break;

		cv::imshow("Example 2-11", bgr_frame);

		cv::logPolar(
			bgr_frame, // Input color frame
			logpolar_frame, // Output log-polar frame
			cv::Point2f( // Centerpoint for log-polar transformation
				bgr_frame.cols / 2, // x
				bgr_frame.rows / 2 // y
			),
			150, // Magnitude (scale parameter)
			cv::WARP_FILL_OUTLIERS // Fill outliers with 'zero'
		);
		cv::imshow("Log_Polar", logpolar_frame);
		writer << logpolar_frame;
		char c = cv::waitKey(10);

		if (c == 27) break; // allow the user to break out

	
	}
	writer.release();
	capture.release();
	return 0;
}
