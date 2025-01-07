Residual network (ResNet) [START_REF] Deep Residual Learning for Image Recognition, He [END_REF]

This subsample the output activation rather than the input activation in the first layer of the network

this is more efficent 

Taken from https://github.com/Eli-YiLi/ScaleNet/blob/2c27b4207691dbe72f7e19fd88bfccc5ce5b3080/tensorflow/scale_resnet_utils.py

## ResNet 

Class block

parts: 
    -scope
    -unit_fn
    -num_units: depth, depth bottleneck, stride

subsample:
-args: 
    - inputs: vector of sixe[batch, height in, width in, channels]
    - factors: subsample factor
    - stride: variable scope
- returns:
    - vector of size with input either intact or subsampled if factor is > 1

conv2d- relu- without bottleneck
params: Input, num-output, kernel_size, stride, rate = 1, scope = none
returns: output of conv2d

conv2d-same
params: 
    _ 4D vector of size [Batch, height in, width in, channels]
    _ num-outputs integer, number of output filters
    - kernal_size - int with kernel size of the filters
    - stride - int with stride of the filters
    - rate - int with rate of the filters
    - scope - string with scope of the variable
returns: 4D vector of sixe with convolution output

arg-scope- stack blocks dense
params 
    - net: vector of size 
    - blocks : list of block objects
    - output stride : int with output stride
    - store non strided activation
    - output collections: list of collections to store the output
return:
    - net output vector with stride equal to the specified output_stride

value error if not valid - validate

scale resnet arg scopr
params: 
    weight decay
    batch norm decay
    batch norm eps
    batch norm scale
    activation_fn
    use batch norm
    batch norm updates collection
returns
    arg scope to use in the resnet model


