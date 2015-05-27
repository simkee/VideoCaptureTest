#include "opencv2/opencv.hpp"
	
#include <stdio.h>
	

#include <iostream>

using namespace cv;
using namespace std;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

	cout << "fps" << cap.get(CV_CAP_PROP_FPS) << endl;

	VideoWriter vidOut;
	Mat vidOutFrame;
    
    	vidOutFrame.create(480, 640, CV_8UC3);

	vidOut.open("starter_video_out.avi", CV_FOURCC('X', 'V', 'I', 'D'), 25, 
				vidOutFrame.size(), true);

cout << "create file	" << endl;
	    
    Mat edges;
    namedWindow("edges",1);
    int n=0;
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        //~ cvtColor(frame, edges, CV_BGR2GRAY);
        //~ GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        //~ Canny(edges, edges, 0, 30, 3);
        imshow("edges", frame);

	frame.copyTo(vidOutFrame);
	vidOut << vidOutFrame;
	//~ vidOut << frame;
	    	cout << "fps" << cap.get(CV_CAP_PROP_FPS) << endl;
	    	cout << "fp counts" << cap.get(CV_CAP_PROP_FRAME_COUNT) << endl;

	if(waitKey(30) >= 0) break;

	//~ char filename[200];
	//~ sprintf(filename,"filename%.3d.jpg",n++);
	//~ imwrite(filename,frame)
	//~ imwrite(filename,frame)
	//~ cout << "Saved " << filename << endl;
	    
	    
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}	