/*
 * RoVi1
 * Exercise 1: Basic operations with images
 */

// e17-1-gbe848aa

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

static constexpr int X1 = 350;
static constexpr int X2 = 440;
static constexpr int Y1 = 100;
static constexpr int Y2 = 220;

// Helper function to convert type identifier to a human-readable string.
// By stackoverflow user 'Octopus', at https://stackoverflow.com/a/17820615
std::string type2str(int type) {
    std::string ret;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth) {
        case CV_8U: ret = "8U"; break;
        case CV_8S: ret = "8S"; break;
        case CV_16U: ret = "16U"; break;
        case CV_16S: ret = "16S"; break;
        case CV_32S: ret = "32S"; break;
        case CV_32F: ret = "32F"; break;
        case CV_64F: ret = "64F"; break;
        default: ret = "User"; break;
    }

    ret += "C";
    ret += (chans + '0');

    return ret;
}

// Black box, method 1: Direct (pointer) access.
// Unsafe but fast.
void black_box_1(const cv::Mat& src)
{
    cv::Mat img = src.clone();

    for (int i = Y1; i < Y2; i++) { // Iterate rows
        // Get the address of the i'th row
        cv::Vec3b* p_row = img.ptr<cv::Vec3b>(i);

        for (int j = X1; j < X2; j++) { // Iterate columns
            p_row[j][0] = 0; // B
            p_row[j][1] = 0; // G
            p_row[j][2] = 0; // R
        }
    }

    cv::imshow("Black box 1", img);
    cv::waitKey();
}

// Black box, method 2: Array element access.
// Safe-ish (checks bounds in debug builds).
// Here, each array element (one pixel) is a vector of 3 elements, containing
// the B,G,R channels.
void black_box_2(const cv::Mat& src)
{
    cv::Mat img = src.clone();

    for (int i = Y1; i < Y2; i++) { // Iterate rows
        for (int j = X1; j < X2; j++) { // Iterate columns
            img.at<cv::Vec3b>(i, j) = cv::Vec3b::all(0); // Set all 3 channels to zero
        }
    }

    cv::imshow("Black box 2", img);
    cv::waitKey();
}

// Black box, method 3: Array element access (short notation)
// Same as method 2, but requires us to know the matrix data type at compilation
// time. This indexing method is slighty shorter and easier to read.
void black_box_3(const cv::Mat& src)
{
    cv::Mat_<cv::Vec3b> img = src.clone();

    for (int i = Y1; i < Y2; i++) {
        for (int j = X1; j < X2; j++) {
            img(i, j) = cv::Vec3b::all(0);
        }
    }

    cv::imshow("Black box 3", img);
    cv::waitKey();
}

// Black box, method 4: Draw a filled rectangle using the cv::rectangle function.
void black_box_4(const cv::Mat& src)
{
    cv::Mat img = src.clone();

    cv::rectangle(img, cv::Point(X1, Y1), cv::Point(X2, Y2), 0, cv::FILLED);

    cv::imshow("Black box 4", img);
    cv::waitKey();
}

// Black box, method 5: Select a region of interest (ROI) and paint it black.
void black_box_5(const cv::Mat& src)
{
    cv::Mat img = src.clone();

    cv::Mat roi(img, cv::Rect(X1, Y1, X2-X1, Y2-Y1));
    roi = cv::Vec3b::all(0);

    cv::imshow("Black box 5", img);
    cv::waitKey();
}

// Draw a colored box using the ROI method.
void colored_box(const cv::Mat& src)
{
    cv::Mat img = src.clone();

    cv::Mat roi(img, cv::Rect(X1, Y1, X2-X1, Y2-Y1));
    roi = cv::Vec3b(0, 255, 255); // Paint the ROI yellow

    cv::imshow("Colored box", img);
    cv::waitKey();
}

// Convert image to grayscale and draw a black box.
void grayscale(const cv::Mat& img)
{
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    // we can also load images as grayscale directly with
    // cv::imread(filename, cv::IMREAD_GRAYSCALE);

    std::cout << "Grayscale type: " << type2str(gray.type()) << std::endl;

    for (int i = Y1; i < Y2; i++) {
        for (int j = X1; j < X2; j++) {
            gray.at<uchar>(i, j) = 0; // Note that elements are single-channel
        }
    }

    cv::imshow("Grayscale with box", gray);
    cv::waitKey();
}

int main(int argc, char* argv[])
{
    cv::CommandLineParser parser(argc, argv,
        "{help   |             | print this message}"
        "{@image | ./color.png | image path}"
    );

    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    // Load image
    std::string filename = parser.get<std::string>("@image");
    cv::Mat src = cv::imread(filename);

    if (src.empty()) {
        std::cout << "Input image not found at '" << filename << "'\n";
        return 1;
    }

    // Show the unmodified image
    std::cout << "Original type: " << type2str(src.type()) << std::endl;
    cv::imshow("Original", src);
    cv::waitKey();

    // 1. Different methods of drawing a "black box"
    black_box_1(src);
    black_box_2(src);
    black_box_3(src);
    black_box_4(src);
    black_box_5(src);

    // 2. Draw a colored box
    colored_box(src);

    // 3. Convert to grayscale and draw a black box
    grayscale(src);

    return 0;
}
