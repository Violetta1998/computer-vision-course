#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

String path = "C:\\Users\\Виолетта\\Desktop\\МИСиС\\8 семестр\\Методы обработки изображений\\Практика\\firyaridi_v_ya\\";
String path_95 = "\\prj\\lab_02\\images\\cube_95.jpg";
String path_65 = "\\prj\\lab_02\\images\\cube_65.jpg";

Mat ROI(Mat img) {
	Mat full_img = Mat::zeros(img.cols * 2, img.rows * 4, CV_8UC3); //т.к. нужна мозаика 2 строки*4 столбца
	Mat rgbchannel[3];
	split(img, rgbchannel);
	Rect roi1 = Rect(0, 0, img.rows, img.cols);
	Rect roi2 = Rect(img.rows, 0, img.rows, img.cols);
	Rect roi3 = Rect(img.rows * 2, 0, img.rows, img.cols);
	Rect roi4 = Rect(img.rows * 3, 0, img.rows, img.cols);
	Rect roi5 = Rect(img.rows, img.cols, img.rows, img.cols);
	Rect roi6 = Rect(img.rows * 2, img.cols, img.rows, img.cols);
	Rect roi7 = Rect(img.rows * 3, img.cols, img.rows, img.cols);
	img.copyTo(full_img(roi1));

	Mat bchannel;
	Mat bchannel3[] = { rgbchannel[0] ,rgbchannel[0],rgbchannel[0] }; //т.к. картинка 3х канальная
	merge(bchannel3, 3, bchannel);
	bchannel.copyTo(full_img(roi2));
	
	Mat gchannel;
	Mat gchannel3[] = { rgbchannel[1] ,rgbchannel[1],rgbchannel[1] };
	merge(gchannel3, 3, gchannel);
	gchannel.copyTo(full_img(roi3));

	Mat rchannel;
	Mat rchannel3[] = { rgbchannel[2], rgbchannel[2], rgbchannel[2] }; 
	merge(rchannel3, 3, rchannel);
	rchannel.copyTo(full_img(roi4));

	Mat b;   //           b                                   g                                    r
	Mat b3[] = { rgbchannel[0], Mat::zeros(img.cols,img.rows, CV_8UC1),Mat::zeros(img.cols,img.rows, CV_8UC1) };
	merge(b3, 3, b);
	b.copyTo(full_img(roi5));
	
	Mat g;
	Mat g3[] = { Mat::zeros(img.cols,img.rows, CV_8UC1), rgbchannel[1], Mat::zeros(img.cols,img.rows, CV_8UC1) };
	merge(g3, 3, g);
	g.copyTo(full_img(roi6));

	Mat r;
	Mat r3[] = { Mat::zeros(img.cols,img.rows, CV_8UC1),Mat::zeros(img.cols,img.rows, CV_8UC1),rgbchannel[2] };
	merge(r3, 3, r);
	r.copyTo(full_img(roi7));
	

	return full_img;
}

int main() {
	Mat img = imread(path + "testdata\\cross.png");
	imwrite(path + path_65, img, { (int)IMWRITE_JPEG_QUALITY, 65 });
	imwrite(path + path_95, img, { (int)IMWRITE_JPEG_QUALITY, 95 });
	Mat img65 = imread(path + path_65);
	Mat img95 = imread(path + path_95);
	Mat full_65 = ROI(img65);
	Mat full_95 = ROI(img95);


	imshow("Result 95", full_95);
	imshow("Result 65", full_65);
	imshow("Result both", (full_95 - full_65) * 30); //разница

	waitKey(0);
	return 0;
}
