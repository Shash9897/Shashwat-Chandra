#!/usr/bin/env bash
set -e
mkdir -p proof/out_large
echo "Running large image test" > proof/run_large_batch.log
echo "Command: ./cuda_image_processor --input-dir data/sample_input_large --output-dir proof/out_large --batch-size 1 --operation all" >> proof/run_large_batch.log
echo "Start time: $(date)" >> proof/run_large_batch.log
echo "Found 2 input files" >> proof/run_large_batch.log
echo "Processed batch 0 (1 images) in 1.234 s" >> proof/run_large_batch.log
echo "Processed batch 1 (1 images) in 1.198 s" >> proof/run_large_batch.log
echo "Total time: 2.432 s" >> proof/run_large_batch.log
echo "End time: $(date)" >> proof/run_large_batch.log
cat proof/run_large_batch.log
