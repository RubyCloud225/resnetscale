#include <iostream>
#include "block.hpp"
#include "Conv2D.hpp"

int main() {
    int B = 1;
    int W = 4;
    int H = 4;
    int C = 1;
    int SF = 2;
    int S = 1;

    Block block(B, H, W, C, SF, S);
    std::vector<float> input = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    };

    std::vector<float> output = block.process(input);
    std::cout << "output: ";
    for (float value : output) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    // params for conv 2d
    int numOutputs = 2;
    int kernelSize = 2;
    int dilationRate = 1;
    // create conv 2d object
    Conv2D conv2d(B, H / SF, W / SF, C, numOutputs, kernelSize, S, dilationRate);
    // process output
    std::vector<float> convOutput = conv2d.forward(output);
    // print output
    std::cout << "convOutput: ";
    for (float value : convOutput) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}