// Example 2-10. The same object can load videos from a camera or a file
// 
#include <opencv2/opencv.hpp>
#include <iostream>


int main() {

	std::string video_path = "big_buck_bunny.mp4";

	cv::namedWindow("Example 2-10", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;

	if (cap.open(0)) {
		// ����ͷ���ã���������ͷ����
		std::cout << "����ͷ�Ѵ�" << std::endl;
	}
	else {
		cap.open(video_path);
	}

	if (!cap.isOpened()) { // check if we succeeded
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

	cv::Mat frame;

	// ��ʼ��Ƶ����ѭ��
	while (true) {
		cap >> frame; // ������ͷ����Ƶ�ļ��ж�ȡ֡

		if (frame.empty()) {
			std::cout << "�޷���ȡͼ��֡" << std::endl;
			break;
		}

		// ������������ͼ�������

		// ��ʾͼ��
		cv::imshow("Example 2-10", frame);

		// ����û��Ƿ�����ESC������������˳�ѭ��
		if (cv::waitKey(10) == 27) {
			break;
		}
	}
	// �ͷ�����ͷ����Ƶ�ļ�
	cap.release();

	// �ر�OpenCV����
	cv::destroyAllWindows();
	return 0;

}