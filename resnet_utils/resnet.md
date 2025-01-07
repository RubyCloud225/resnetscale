num channels 
bring in renet arg scope form utils for our scope

slim - look into this as the orginal paper comes from tensorflow 

no op context manager - this is a context manager that does nothing

slim add arg scope - this is a function that adds an arg scope to the current graph
adding bottleneck layers - this is a function that adds bottleneck layers to the current graph
     params: 
        - inputs, size of batch, height, width, channels 
        - depth,  depth of resnet output,
        - depth_bottleneck, depth of bottleneck layer
        - stride, units stride, amount of downsampling
        - block_id, 
        - unit_id, 
        - rate,int for the atrous convolution
        - output_collections, collection to add to Resnet unit
        - scope, varable scope
        - use bounded activation, lend it selfto quantized inference
    return resnet output

scale resnet 
training data - 224x224
testing data - 256x256
scale resnet to 224x224
use output scale of 16

args: 
    - inputs
    - blocks
    - num_classes
    _ is_training
    - global pool
    - output stride
    - include root block- followed by max pooling
    - spatial squeeze - squeeze spatial dimensions
    - store non strided activations
    - reuse
    - scope

scale - resnet block
- scope of block. 
- base depth
- num units
- stride

return resnet bottleneck block
    


