#include "dnn.h"

Net Net_ReadNetFromCaffe(const char* prototxt, const char* caffeModel) {
    Net n = new cv::dnn::Net(cv::dnn::readNetFromCaffe(prototxt, caffeModel));
    return n;
}

bool Net_Empty(Net net) {
    return net->empty();
}

void Net_SetInput(Net net, Mat blob, const char* name) {
    net->setInput(*blob, name);
}

Mat Net_Forward(Net net, const char* outputName) {
    return new cv::Mat(net->forward(outputName));
}

Mat Net_BlobFromImage(Mat image, double scalefactor, Size size, Scalar mean, bool swapRB, bool crop) {
    cv::Size sz(size.width, size.height);
    cv::Scalar cm = cv::Scalar(mean.val1, mean.val2, mean.val3, mean.val4);
    return new cv::Mat(cv::dnn::blobFromImage(*image, scalefactor, sz, cm, swapRB, crop));
}
