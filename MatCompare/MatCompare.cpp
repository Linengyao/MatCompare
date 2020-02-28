// MatCompare.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv.hpp>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("E:/桌面壁纸/1.jpg");
	cv::Mat deepMat;
	cv::Mat shallowMat;

	//浅复制
	shallowMat = srcMat;
	//深复制
	srcMat.copyTo(deepMat);
	//改变原图
	int height = srcMat.rows; //行数
	int width = srcMat.cols;//每行元素数量
	uchar threshold = 100;

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			//------开始处理每个像素---------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] +
							 srcMat.at<Vec3b>(j, i)[1] +
							 srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold)
			{
				average = 255;
			}
			else
			{
				average = 0;
			}
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;

		}//单行处理结束
	}
	imshow("deepMat", deepMat);
	waitKey(0);
	imshow("shallowMat", shallowMat);
	waitKey(0);
	return 0;

    /*std::cout << "Hello World!\n";*/
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
