#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	VideoCapture cap(0);
	Mat frame;
	Mat edges;

	while (1){
		cap >> frame;
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		GaussianBlur(edges,edges, Size(7,7), 1.5,1.5);
		Canny(edges,edges,0,30,3);
		imshow("edges", edges);
		imshow("frame", frame);
		waitKey(1);
	}
	return 0;
}