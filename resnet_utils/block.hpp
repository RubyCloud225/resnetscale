#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <vector>

class Block {
    public:
    // B= block
    // H = height
    // W = width
    // C = channels
    // SF = subsample factor
    // S = stride
    Block(int B, int H, int W, int C, int SF, int S);
    std::vector<float> process(const std::vector<float>& input);

    private:
    int B;
    int H;
    int W;
    int C;
    int SF;
    int S;
};

#endif // BLOCK_HPP