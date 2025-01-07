#include "Conv2D.hpp"
#include <iostream>
#include <cmath>

Conv2D::Conv2D(int batch, int height, int width, int channels, int numOutputs, int kernelSize, int stride, int dilationRate) : batch(batch), height(height), width(width), channels(channels), numOutputs(numOutputs), kernelSize(kernelSize), stride(stride), dilationRate(dilationRate) {}
std::vector<float> Conv2D::forward(const std::vector<float>& input) {
    if (input.size() != batch * height * width * channels) {
        std::cerr << "Error: Input size does not match the Conv2D layer's input." << std::endl;
    }
    // Calculate output dimensions
    int outputHeight = (height - (kernelSize -1) * dilationRate -1) / stride + 1;
    int outputWidth = (width - (kernelSize -1) * dilationRate -1) / stride + 1;

    std::vector<float> output(batch * outputHeight * outputWidth * numOutputs, 0.0f);
    // Perform convolution operation (naive implementation)
    for (int b = 0; b < batch; ++b) {
        for (int oh = 0; oh < outputHeight; ++oh) {
            for (int ow = 0; ow < outputWidth; ++ow) {
                for (int co = 0; co < numOutputs; ++co) {
                    float sum = 0.0f;
                    for (int kh = 0; kh < kernelSize; ++kh) {
                        for (int kw = 0; kw < kernelSize; ++kw) {
                            for (int ci = 0; ci < channels; ++ci) {
                                int ih = oh * stride + kh * dilationRate;
                                int iw = ow * stride + kw * dilationRate;
                                if (ih < height && iw < width) {
                                    int inputIndex = b * height * width * channels + ih * width * channels + iw * channels + ci;
                                    sum += input[inputIndex];
                                }
                            }
                        }
                    }
                    int outputIndex = b * outputHeight * outputWidth * numOutputs + oh * outputWidth *numOutputs + ow * numOutputs + co;
                    output[outputIndex] = sum;
                }
            }
        }
    }
    return relu(output);
}

std::vector<float> Conv2D::relu(const std::vector<float>& input) {
    std::vector<float> output(input.size());
    for (int i = 0; i < input.size(); ++i) {
        output[i] = std::max(0.0f, input[i]);
    }
    return output;
}