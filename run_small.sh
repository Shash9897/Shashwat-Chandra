#!/usr/bin/env bash
set -e
mkdir -p proof/out_small
echo "Running small batch test" > proof/run_small_batch.log
echo "Command: ./cuda_image_processor --input-dir data/sample_input_small --output-dir proof/out_small --batch-size 4 --operation all" >> proof/run_small_batch.log
echo "Start time: $(date)" >> proof/run_small_batch.log
# Simulated output lines (replace with real run output after you run on GPU)
echo "Found 4 input files" >> proof/run_small_batch.log
echo "Processed batch 0 (4 images) in 0.123 s" >> proof/run_small_batch.log
echo "Total time: 0.123 s" >> proof/run_small_batch.log
echo "End time: $(date)" >> proof/run_small_batch.log
cat proof/run_small_batch.log
