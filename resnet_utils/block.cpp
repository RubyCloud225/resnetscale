#include "block.hpp"
#include <iostream>

 Block::Block(int B, int H, int W, int C, int SF, int S) : B(B), H(H), W(W), C(C), SF(SF), S(S) {}

 std::vector<float> Block::process(const std::vector<float>& input) {
    if (input.size() != B * H * W * C) {
        std::cerr << "Error: Input size does not match block size." << std::endl;
        return {};
    }

    // if subsample factor is 1 return the input intact
    if (SF == 1) {
        return input;
    }
    // Calculate the new dimensions after subsampling
    int new_H = H / SF;
    int new_W = W / SF;
    int new_size = B * new_H * new_W * C;

    std::vector<float> output(new_size);
    int outputIndex = 0;

    // perform subsampling 
    for ( int b = 0 ; b < B; ++b ) {
        for ( int h = 0 ; h < new_H; ++h ) {
            for ( int w = 0 ; w < new_W; ++w ) {
                for ( int c = 0 ; c < C; ++c ) {
                    int inputIndex = b * H * W * C + (h * SF) * W * C + (w * SF) * W * C + c;
                    output[outputIndex++] = input[inputIndex];
                }
            }
        }
    }

    return output;
 }