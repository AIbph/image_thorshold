#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;

// ����Mat������ʼ��ֵ�������ֵ����ʼ����ѡ��������
Mat src, gray_src, dst;
int threshold_value = 127;
int threshold_max = 255;
int type_value = 2;
int type_max = 4;

// ��������
void Threshold_Demo(int, void*);

int main(int argc, char** argv) {
	// ͼ����ֵ,��ֵ���ͣ�ȥ���룬������˺�С��ܴ�����ֵ��ͼ��㣬 �õ�һ�ŶԱȶȲ�ͬ�ĺڰ�ͼƬ��ʵ�������ǵõ���ͬЧ����ͼƬ��

	// ��ȡͼƬ
	src = imread("D:/gitProject/Project/test.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	// ���崰��չʾԭͼ
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	namedWindow("binary image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	// �����ֵ������������ѡ�����
	createTrackbar("Threshold Value:", "binary image", &threshold_value, threshold_max, Threshold_Demo);
	createTrackbar("Type Value:", "binary image", &type_value, type_max, Threshold_Demo);

	// ���÷���
	Threshold_Demo(0, 0);

	waitKey(0);
	return 0;
}

void Threshold_Demo(int, void*) {
	// ��ֵ����

	// ת��Ϊ�Ҷ�ͼ
	cvtColor(src, gray_src, CV_BGR2GRAY);

	//��ֵ����ͼ��
	/*
		retval, dst = cv.threshold( src, thresh, maxval, type[, dst] ) 
		src��ԭͼ��
		dst�����ͼ��
		thresh����ǰ��ֵ��
		maxVal�������ֵ��һ��Ϊ255.
		thresholdType:��ֵ���ͣ���Ҫ�����漸�֣�			
			enum ThresholdTypes {
				THRESH_BINARY     = 0,
				THRESH_BINARY_INV = 1,
				THRESH_TRUNC      = 2,
				THRESH_TOZERO     = 3,
				THRESH_TOZERO_INV = 4,
				THRESH_MASK       = 7,
				THRESH_OTSU       = 8,
				THRESH_TRIANGLE   = 16
			};
	*/
	threshold(src, dst, threshold_value, threshold_max, type_value);

	// չʾ������ͼƬ
	imshow("binary image", dst);
}