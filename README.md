# CUDA Batch Image Processor

## Overview
This project processes large amounts of image data on the GPU using CUDA and NVIDIA Performance Primitives (NPP) where possible. It supports grayscale conversion, Gaussian blur, and Sobel edge detection. The program is intended to demonstrate ability to run across many images and produce proof artifacts.

## Repo structure
- src/                # C++/CUDA source
- include/            # headers
- data/sample_input_small/  # a few small example images for quick testing (committed)
- scripts/            # run scripts and helper utilities
- build/              # build output
- proof/              # example logs and before/after images (not huge files)

## Building
Requirements:
- CUDA Toolkit (tested with 11.x)
- CMake
- (Optional) NPP libraries (part of CUDA Toolkit)

Build:
```bash
mkdir -p build && cd build
cmake ..
make -j
```

## Usage
Command line interface:
```bash
./cuda_image_processor --input-dir ../data/sample_input   --output-dir ../data/output --batch-size 32 --operation all
```
CLI options:
- `--input-dir`  : directory with input images
- `--output-dir` : directory to save processed images
- `--batch-size` : number of images per batch (tune for GPU memory)
- `--operation`  : `grayscale`, `blur`, `edge`, or `all`
- `--log-file`   : optional

Examples:
```bash
./cuda_image_processor --input-dir ./data/sample_input_small   --output-dir ./proof/out_small --batch-size 128 --operation all --log-file proof/run_small_batch.log
```

## Testing / Proof
Included in `proof/` are example run logs and before/after images demonstrating processing of both many small images and several large images.

## License
[MIT] - adapt as needed
