//���ƽ������ȼ�2-8

#include <opencv2/opencv.hpp>

cv::Mat inputImage;
cv::Mat downsampledImage;
int scale_factor = 2; // ��ʼ����������

void onScaleChange(int scale, void* userdata) {
    scale_factor = scale;
    cv::resize(inputImage, downsampledImage, cv::Size(), 1.0 / scale_factor, 1.0 / scale_factor);
    
    cv::imshow("Downsampled Image", downsampledImage);
}

int main() {
    std::string imgpath = "fruits.jpg";
    // ��ȡ����ͼ��
    inputImage = cv::imread(imgpath); // �滻Ϊ�������ͼ��·��

    if (inputImage.empty()) {
        std::cerr << "�޷�������ͼ��" << std::endl;
        return -1;
    }

    // ����һ������
    cv::namedWindow("Downsampled Image");

    // ����Trackbar����������������
    cv::createTrackbar("Scale Factor (2-8)", "Downsampled Image", &scale_factor, 8, onScaleChange);
    //onScaleChange(scale_factor, nullptr); // ��ʼ����ʾ���������ͼ��

    cv::waitKey(0);

    return 0;
}
