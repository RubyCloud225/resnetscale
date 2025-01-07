#ifndef CONV2D_HPP
#define CONV2D_HPP
#include <vector>

class Conv2D {
    public:
    Conv2D(int batch, int height, int width, int channels, int numOutputs, int kernelSize, int stride, int dilationRate);
    std::vector<float> forward(const std::vector<float>& input);
    private:
    int batch;
    int height;
    int width;
    int channels;
    int numOutputs;
    int kernelSize;
    int stride;
    int dilationRate;
    std::vector<float> relu(const std::vector<float>& input);
};

#endif // CONV2D_HPP