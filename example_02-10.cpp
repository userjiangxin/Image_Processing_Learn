// Example 2-10. The same object can load videos from a camera or a file
// 
#include <opencv2/opencv.hpp>
#include <iostream>


int main() {

	std::string video_path = "big_buck_bunny.mp4";

	cv::namedWindow("Example 2-10", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;

	if (cap.open(0)) {
		// 摄像头可用，进行摄像头捕获
		std::cout << "摄像头已打开" << std::endl;
	}
	else {
		cap.open(video_path);
	}

	if (!cap.isOpened()) { // check if we succeeded
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

	cv::Mat frame;

	// 开始视频捕获循环
	while (true) {
		cap >> frame; // 从摄像头或视频文件中读取帧

		if (frame.empty()) {
			std::cout << "无法获取图像帧" << std::endl;
			break;
		}

		// 在这里进行你的图像处理操作

		// 显示图像
		cv::imshow("Example 2-10", frame);

		// 检查用户是否按下了ESC键，如果是则退出循环
		if (cv::waitKey(10) == 27) {
			break;
		}
	}
	// 释放摄像头或视频文件
	cap.release();

	// 关闭OpenCV窗口
	cv::destroyAllWindows();
	return 0;

}