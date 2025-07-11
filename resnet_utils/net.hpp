#ifndef NET_HPP
#define NET_HPP
#include <vector>
#include <memory>
#include <functional>

class Block;
class Net {
    public:
    Net(const std::vector<int>& sizes, const std::vector<std::shared_ptr<Block>>& blocks, int outputStride);
    std::vector<float> forward(const std::vector<float>& input);
    private:
    std::vector<int> sizes;
    std::vector<std::shared_ptr<Block>> blocks;
    int outputStride;
    std::vector<std::function<float(float)>> activations;
    std::vector<float> applyActivation(const std::vector<float>& input);
};

#endif // NET_HPP