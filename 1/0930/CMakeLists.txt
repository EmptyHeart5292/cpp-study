cmake_minimum_required(VERSION 3.16)
project(orders LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(orders
    src/main.cpp
    src/order.cpp
)
target_include_directories(orders PRIVATE include)
target_compile_options(orders PRIVATE
    -Wall
    -fsanitize=address,undefined
)
target_link_options(orders PRIVATE
    -fsanitize=address,undefined
)