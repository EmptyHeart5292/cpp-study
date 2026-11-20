cmake_minimum_required(VERSION 3.21)
project(binance_ws_cpp20 LANGUAGES CXX)

add_executable(binance_ws src/main.cpp)
target_compile_features(binance_ws PRIVATE cxx_std_20)
set_target_properties(binance_ws PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

find_package(Boost REQUIRED COMPONENTS json)
find_package(OpenSSL REQUIRED)

target_link_libraries(binance_ws PRIVATE Boost::json OpenSSL::SSL OpenSSL::Crypto)

if(MSVC)
    target_compile_options(binance_ws PRIVATE /W4 /utf-8 /EHsc)
else()
    target_compile_options(binance_ws PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()
add_test(NAME parser_demo COMMAND binance_ws --demo)
