cmake_minimum_required(VERSION 3.17)
project(milestone3_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(milestone3_4 MainTrain.cpp Server.cpp Server.h anomaly_detection_util.h anomaly_detection_util.cpp AnomalyDetector.h SimpleAnomalyDetector.h SimpleAnomalyDetector.cpp timeseries.h timeseries.cpp HybridAnomalyDetector.h HybridAnomalyDetector.cpp minCircle.h minCircle.cpp commands.h CLI.cpp CLI.h )
# MainTrain.cpp
#// test_commands.cpp
#
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread -std=c++11")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")