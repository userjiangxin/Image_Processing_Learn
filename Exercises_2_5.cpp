//控制降采样等级2-8

#include <opencv2/opencv.hpp>

cv::Mat inputImage;
cv::Mat downsampledImage;
int scale_factor = 2; // 初始降采样因子

void onScaleChange(int scale, void* userdata) {
    scale_factor = scale;
    cv::resize(inputImage, downsampledImage, cv::Size(), 1.0 / scale_factor, 1.0 / scale_factor);
    
    cv::imshow("Downsampled Image", downsampledImage);
}

int main() {
    std::string imgpath = "fruits.jpg";
    // 读取输入图像
    inputImage = cv::imread(imgpath); // 替换为你的输入图像路径

    if (inputImage.empty()) {
        std::cerr << "无法打开输入图像" << std::endl;
        return -1;
    }

    // 创建一个窗口
    cv::namedWindow("Downsampled Image");

    // 创建Trackbar来调整降采样因子
    cv::createTrackbar("Scale Factor (2-8)", "Downsampled Image", &scale_factor, 8, onScaleChange);
    //onScaleChange(scale_factor, nullptr); // 初始化显示降采样后的图像

    cv::waitKey(0);

    return 0;
}
