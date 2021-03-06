#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "Data.h"
#include "LabelParse.h"
//#include "engine.h" Maybe Matlab.

using namespace tesseract;
using namespace cv;

void Convert_To_GrayScale(const char* path);

int main(int argc, char * argv[])
{
    //Engine* engine = engOpen(NULL);

    TessBaseAPI *api = new TessBaseAPI();

    Data data;
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng", tesseract::OEM_TESSERACT_CUBE_COMBINED)) {
        std::cerr << "ERROR::MAIN::Could not initialize tesseract!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (argc <= 1) {
        std::cout << "ERROR::MAIN::Missing arguments:" << std::endl;
        std::cout << "--image_1, --image_2, --image_3... --image_n" << std::endl;
        exit(EXIT_FAILURE);
    }

    api->SetPageSegMode(PSM_AUTO);
    // Open input image with leptonica library
    for (int imageIndex = 1; imageIndex < argc; imageIndex ++) {
        std::cout << "Converting " << argv[imageIndex] << " to gray-scale..." << std::endl;
        Convert_To_GrayScale(argv[imageIndex]);
        std::cout << "Processing " << argv[imageIndex] << "..." << std::endl;
        Pix *image = pixRead(argv[imageIndex]);
        api->SetImage(image);
        std::string outText = api->GetUTF8Text();
        int conf = api->MeanTextConf();
        data.Write(outText, conf, imageIndex);
        pixDestroy(&image);
        std::vector<std::string> results = labelParse("./" + data.GetFileName());
        for (int i = 0; i < results.size(); i++) {
            std::cout << results[i] << std::endl;
        }
    }

    // Destroy used object and release memory
    api->Clear();
    api->End();

    return EXIT_SUCCESS;
}


// Process pulled form: http://stackoverflow.com/questions/1585535/convert-rgb-to-black-white-in-opencv
void Convert_To_GrayScale(const char* path) {
    Mat im_rgb  = imread(path);
    Mat im_gray;
    cvtColor(im_rgb,im_gray,CV_RGB2GRAY);
    Mat img_bw = im_gray > 128;
    std::string old_path = path;
    imwrite(path, img_bw);
}





















