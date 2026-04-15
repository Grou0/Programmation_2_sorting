cmake_minimum_required(VERSION 3.26)
project(S7_Sort_repo C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(sort_test
        source/bubbleSort.c
        source/quickSort.c
        include/mergeSort.h
        source/mergeSort.c
        include/PQ.h
        source/PQ.c
        source/heapSort.c
        include/heapSort.h
        source/main-heapSort-test.c
)