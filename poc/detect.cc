#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/calib3d/calib3d_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core/core_c.h>

using namespace cv;
using namespace std;
 
void detectHuman ( ) {

    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_alt.xml");
    namedWindow("Human Detection", CV_WINDOW_AUTOSIZE);
    VideoCapture capture;
    capture.open(0);
    Mat frame;

    while (true) {
        capture.read(frame);
        vector<Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
        for (int i = 0; i < faces.size(); i++) {
            Rect face_i = faces[i];
            rectangle(frame, face_i, CV_RGB(255, 0, 0), 2);
        }
        imshow("Human Detection", frame);
        char c = (char)waitKey(10);
        if (c == 'q') {
            break;
        }
    }
    capture.release();
    destroyWindow("Human Detection");
}

void savePictureOfDetectedHuman ( ) {
    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_alt.xml");
    namedWindow("Human Detection", CV_WINDOW_AUTOSIZE);
    VideoCapture capture;
    capture.open(0);
    Mat frame;

    while (true) {
        capture.read(frame);
        vector<Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
        for (int i = 0; i < faces.size(); i++) {
            Rect face_i = faces[i];
            rectangle(frame, face_i, CV_RGB(255, 0, 0), 2);
        }
        imshow("Human Detection", frame);
        char c = (char)waitKey(10);
        if (c == 'q') {
            break;
        }
        if (c == 's') {
            imwrite("detected_human.jpg", frame);
            break;
        }
    }
    capture.release();
    destroyWindow("Human Detection");
}

void main ( ) {
    detectHuman();
    savePictureOfDetectedHuman();
}

main ( );
