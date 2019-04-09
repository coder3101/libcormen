cmake_minimum_required(VERSION 3.1)

if(CMAKE_COMPILER_IS_GNUCC)
	add_compile_options(--coverage O0)
endif()

# Building Part

project(Tests)

add_executable(insertion_sort_test ./tests/foundations/insertion_sort_test.cc)
target_link_libraries(insertion_sort_test --coverage)

add_executable(merge_sort_test ./tests/foundations/merge_sort_test.cc)
target_link_libraries(merge_sort_test --coverage)

add_executable(max_sub_array ./tests/foundations/max_sub_array_test.cc)
target_link_libraries(max_sub_array --coverage)

add_executable(strassens ./tests/foundations/strassens_algorithm_test.cc)
target_link_libraries(strassens --coverage)

add_executable(permute_by_sort ./tests/foundations/permute_by_sort_test.cc)
target_link_libraries(permute_by_sort --coverage)

add_executable(heap_sort ./tests/sorting/heapsort_test.cc)
target_link_libraries(heap_sort --coverage)

add_executable(quicksort ./tests/sorting/quicksort_test.cc)
target_link_libraries(quicksort --coverage)

add_executable(count_sort ./tests/sorting/countingsort_test.cc)
target_link_libraries(count_sort --coverage)

add_executable(stack_queue ./tests/data_structures/stack_queue.cc)
target_link_libraries(stack_queue --coverage)

add_executable(linked_list ./tests/data_structures/linked_list.cc)
target_link_libraries(linked_list --coverage)


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
