cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)


option(CODE_COVERAGE "Enable coverage reporting" ON)

# Building Part
project(Tests)

add_executable(insertion_sort_test ./tests/foundations/insertion_sort_test.cc)
add_executable(merge_sort_test ./tests/foundations/merge_sort_test.cc)
add_executable(max_sub_array ./tests/foundations/max_sub_array_test.cc)
add_executable(strassens ./tests/foundations/strassens_algorithm_test.cc)
add_executable(permute_by_sort ./tests/foundations/permute_by_sort_test.cc)
add_executable(heap_sort ./tests/sorting/heapsort_test.cc)
add_executable(quicksort ./tests/sorting/quicksort_test.cc)
add_executable(count_sort ./tests/sorting/countingsort_test.cc)
add_executable(stack_queue ./tests/data_structures/stack_queue.cc)
add_executable(linked_list ./tests/data_structures/linked_list.cc)



include_directories(AFTER ./)

enable_testing()

# Testing Part

add_test(Insertion-Sort insertion_sort_test)
add_test(Merge-Sort merge_sort_test)
add_test(Max-Sub-Array max_sub_array)
add_test(Strassen-Algorithm strassens)
add_test(Heap-Sort heap_sort)
add_test(Quick-sort quicksort)
add_test(Counting-sort count_sort)
add_test(Stack-Queue stack_queue)
add_test(Linked-List linked_list)

if(CODE_COVERAGE AND CMAKE_COMPILER_IS_GNUCXX)
message("Coverage Enabled")
set(CMAKE_CXX_FLAGS "-O0 -g -ftest-coverage -fprofile-arcs")
set(CMAKE_EXE_LINKER_FLAGS "-ftest-coverage -fprofile-arcs")
else()
message("Not Enabled Coverage")
endif()