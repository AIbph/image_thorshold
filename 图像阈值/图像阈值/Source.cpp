#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;

// 定义Mat对象，起始阈值，最大阈值，起始类型选项，最大类型
Mat src, gray_src, dst;
int threshold_value = 127;
int threshold_max = 255;
int type_value = 2;
int type_max = 4;

// 方法声明
void Threshold_Demo(int, void*);

int main(int argc, char** argv) {
	// 图像阈值,阈值类型（去掉噪，例如过滤很小或很大像素值的图像点， 得到一张对比度不同的黑白图片，实质最后就是得到不同效果的图片）

	// 读取图片
	src = imread("D:/gitProject/Project/test.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	// 定义窗口展示原图
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	namedWindow("binary image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	// 添加阈值滑动条和类型选项滑动条
	createTrackbar("Threshold Value:", "binary image", &threshold_value, threshold_max, Threshold_Demo);
	createTrackbar("Type Value:", "binary image", &type_value, type_max, Threshold_Demo);

	// 调用方法
	Threshold_Demo(0, 0);

	waitKey(0);
	return 0;
}

void Threshold_Demo(int, void*) {
	// 阈值处理

	// 转化为灰度图
	cvtColor(src, gray_src, CV_BGR2GRAY);

	//阈值处理图像
	/*
		retval, dst = cv.threshold( src, thresh, maxval, type[, dst] ) 
		src：原图像。
		dst：结果图像。
		thresh：当前阈值。
		maxVal：最大阈值，一般为255.
		thresholdType:阈值类型，主要有下面几种：			
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

	// 展示处理后的图片
	imshow("binary image", dst);
}