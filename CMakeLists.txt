cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(cuda_image_processor LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Example CUDA flags; adjust for your environment
if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
  set(CMAKE_CUDA_ARCHITECTURES 60 75 80 86)
endif()

add_executable(cuda_image_processor
  src/main.cpp
  src/cuda_kernels.cu
)

target_include_directories(cuda_image_processor PRIVATE include)

# Link libraries if needed (NPP)
# find_package(CUDA REQUIRED)
# target_link_libraries(cuda_image_processor PRIVATE nppig nppicc)

set_target_properties(cuda_image_processor PROPERTIES
  CUDA_SEPARABLE_COMPILATION ON
)
