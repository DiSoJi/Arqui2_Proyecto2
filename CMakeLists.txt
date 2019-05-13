cmake_minimum_required(VERSION 3.14)
project(Arqui2_Proyecto2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arqui2_Proyecto2 main.cpp src/mem_ops.cpp src/mem_ops.h src/ALU.cpp src/ALU.h src/vector_loader.cpp src/vector_loader.h src/pipelines.cpp src/pipelines.h src/signals.h src/picture_tools.cpp src/picture_tools.h src/vCPU.cpp src/decode.cpp src/decode.h src/image.cpp src/image.h src/pgm.cpp src/pgm.h)