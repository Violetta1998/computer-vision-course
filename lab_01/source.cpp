#include <opencv2/opencv.hpp>

using namespace cv;

int part_1() {
	Mat full_image(120, 768, CV_8UC1, Scalar(255));
	int w = 768, h = 60;
	Mat roi_1 = full_image(Rect(0, 0, w, h)); //x, y, w, h

	Mat& img(roi_1);
	int j = 0;
	for (int step = 0; step < img.cols; step++) {
		if (step % 3 == 0) {
			j++;
		}
		img.col(step).setTo(j);
	}

	Mat img_2;
	img.convertTo(img_2, CV_32FC1, 1.0 / 255);
	pow(img_2, 2.2, img_2);//2.2 - гамма коррекция

	Mat roi_2 = full_image(Rect(0, h, w, h));
	img_2.convertTo(roi_2, CV_8UC1, 255.0);

	imshow("Gradient_1", full_image);

	waitKey(0);
	return 0;
}

int part_2() {
	int h = 60;
	int w = 768;

	Mat img(Mat::zeros(h, w, CV_8UC1));
	Mat full_image(Size(w, 2 * h), CV_8UC1);

	for (int col = 0; col < w; ++col) {
		for (int row = 0; row < h; ++row) {
			img.at<uchar>(Point(col, row)) = 5 + col / 30 * 10;
		}
	}

	img.copyTo(full_image(Rect(0, 0, w, h)));
	img.convertTo(img, CV_32FC1, 1.0 / 255);
	cv::pow(img, 2.3, img);
	img.convertTo(img, CV_8UC1, 255);
	img.copyTo(full_image(Rect(0, h, w, h)));

	imshow("Gradient_2", full_image);
	waitKey(0);
	return 0;
}

int main()
{
	part_1();
	part_2();
}



