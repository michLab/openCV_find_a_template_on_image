#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

int main()
{

    Mat image = imread("WaldoBeach.jpg");
    imshow("Waldo beach - color",image);

    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imshow("Waldo beach - gray",gray);

    Mat image_templ = imread("waldo.jpg", 0);
    imshow("Waldo - template",image_templ);

    Mat result;
    matchTemplate(gray, image_templ, result, TM_CCOEFF);
    double min_val, max_val;
    Point min_loc, max_loc;
    minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);
    Point top_left = max_loc;
    Point bottom_right;
    bottom_right.x = top_left.x + 50;
    bottom_right.y = top_left.y + 50;
    rectangle(image, top_left, bottom_right, Scalar(0, 0, 255), 5);
    imshow("Where is Waldo", image);
    waitKey(0);

    return 0;
}
