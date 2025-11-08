#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <chrono>

extern void process_batch_on_gpu(const std::vector<std::string>& batch_files, const std::string& operation);

int main(int argc, char** argv) {
    // This is a simplified CLI parser for demonstration.
    std::string input_dir = "data/sample_input_small";
    std::string output_dir = "proof/out_small";
    int batch_size = 32;
    std::string operation = "all";

    // In a real implementation, parse argc/argv for overrides.
    std::cout << "Starting CUDA Batch Image Processor (skeleton)\n";
    std::cout << "Input dir: " << input_dir << "\n";
    std::cout << "Output dir: " << output_dir << "\n";
    std::cout << "Batch size: " << batch_size << "\n";
    std::cout << "Operation: " << operation << "\n";

    // Enumerate files (simple)
    namespace fs = std::filesystem;
    std::vector<std::string> files;
    for (auto &p : fs::directory_iterator(input_dir)) {
        if (p.is_regular_file()) files.push_back(p.path().string());
    }

    std::cout << "Found " << files.size() << " input files\n";

    // Process in batches
    for (size_t i = 0; i < files.size(); i += batch_size) {
        size_t end = std::min(files.size(), i + batch_size);
        std::vector<std::string> batch(files.begin()+i, files.begin()+end);
        auto t0 = std::chrono::high_resolution_clock::now();
        process_batch_on_gpu(batch, operation);
        auto t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dt = t1 - t0;
        std::cout << "Processed batch " << (i/batch_size) << " (" << batch.size() << " images) in " << dt.count() << " s\n";
    }

    std::cout << "Done\n";
    return 0;
}
