#include <opencv2/opencv.hpp>

int main() {
    // 打开输入视频文件
    cv::VideoCapture inputVideo("big_buck_bunny.mp4"); // 替换为你的输入视频文件路径

    if (!inputVideo.isOpened()) {
        std::cerr << "无法打开输入视频文件" << std::endl;
        return -1;
    }

    // 获取输入视频的帧宽度、帧高度和帧速率
    int frameWidth = inputVideo.get(cv::CAP_PROP_FRAME_WIDTH);
    int frameHeight = inputVideo.get(cv::CAP_PROP_FRAME_HEIGHT);
    double fps = inputVideo.get(cv::CAP_PROP_FPS);

    // 创建输出视频写入器
    cv::VideoWriter outputVideo("pyr_big_buck_bunny.mp4", cv::VideoWriter::fourcc('X', 'V', 'I', 'D'), fps, cv::Size(frameWidth / 2, frameHeight / 2)); // 替换为你的输出视频文件路径

    if (!outputVideo.isOpened()) {
        std::cerr << "无法创建输出视频文件" << std::endl;
        return -1;
    }

    cv::Mat frame;

    while (true) {
        inputVideo >> frame; // 从输入视频读取一帧

        if (frame.empty()) {
            break; // 视频结束
        }

        // 对帧进行降采样，这里将图像大小缩小为原来的一半
        cv::Mat downsampledFrame;
        cv::pyrDown(frame, downsampledFrame, cv::Size(frameWidth / 2, frameHeight / 2));

        // 将降采样后的帧写入输出视频
        outputVideo.write(downsampledFrame);

        // 在窗口中显示原始和降采样后的帧
        cv::imshow("Original Frame", frame);
        cv::imshow("Downsampled Frame", downsampledFrame);

        // 检查用户是否按下了ESC键，如果是则退出循环
        if (cv::waitKey(10) == 27) {
            break;
        }
    }

    // 释放资源
    inputVideo.release();
    outputVideo.release();
    cv::destroyAllWindows();

    return 0;
}
