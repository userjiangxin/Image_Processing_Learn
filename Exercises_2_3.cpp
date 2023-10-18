#include <opencv2/opencv.hpp>

int main() {
    // ��������Ƶ�ļ�
    cv::VideoCapture inputVideo("big_buck_bunny.mp4"); // �滻Ϊ���������Ƶ�ļ�·��

    if (!inputVideo.isOpened()) {
        std::cerr << "�޷���������Ƶ�ļ�" << std::endl;
        return -1;
    }

    // ��ȡ������Ƶ��֡��ȡ�֡�߶Ⱥ�֡����
    int frameWidth = inputVideo.get(cv::CAP_PROP_FRAME_WIDTH);
    int frameHeight = inputVideo.get(cv::CAP_PROP_FRAME_HEIGHT);
    double fps = inputVideo.get(cv::CAP_PROP_FPS);

    // ���������Ƶд����
    cv::VideoWriter outputVideo("pyr_big_buck_bunny.mp4", cv::VideoWriter::fourcc('X', 'V', 'I', 'D'), fps, cv::Size(frameWidth / 2, frameHeight / 2)); // �滻Ϊ��������Ƶ�ļ�·��

    if (!outputVideo.isOpened()) {
        std::cerr << "�޷����������Ƶ�ļ�" << std::endl;
        return -1;
    }

    cv::Mat frame;

    while (true) {
        inputVideo >> frame; // ��������Ƶ��ȡһ֡

        if (frame.empty()) {
            break; // ��Ƶ����
        }

        // ��֡���н����������ｫͼ���С��СΪԭ����һ��
        cv::Mat downsampledFrame;
        cv::pyrDown(frame, downsampledFrame, cv::Size(frameWidth / 2, frameHeight / 2));

        // �����������֡д�������Ƶ
        outputVideo.write(downsampledFrame);

        // �ڴ�������ʾԭʼ�ͽ��������֡
        cv::imshow("Original Frame", frame);
        cv::imshow("Downsampled Frame", downsampledFrame);

        // ����û��Ƿ�����ESC������������˳�ѭ��
        if (cv::waitKey(10) == 27) {
            break;
        }
    }

    // �ͷ���Դ
    inputVideo.release();
    outputVideo.release();
    cv::destroyAllWindows();

    return 0;
}
