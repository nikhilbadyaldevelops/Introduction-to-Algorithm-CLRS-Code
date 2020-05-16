cmake_minimum_required(VERSION 3.16)
project(Introduction_to_Algorithm_CLRS_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(03data_structure/10elementary/dequeue)
include_directories(03data_structure/10elementary/linked_list/doubly)
include_directories(03data_structure/10elementary/linked_list/doubly/list_with_sentinal)
include_directories(03data_structure/10elementary/linked_list/singly)
include_directories(03data_structure/10elementary/queue)
include_directories(03data_structure/10elementary/set)
include_directories(03data_structure/10elementary/stack)
include_directories(03data_structure/10elementary/stack/double_stack)
include_directories(03data_structure/12bst/int_tree)
include_directories(03data_structure/13red_black)
include_directories(03data_structure/14augmenting_structures)

add_executable(Introduction_to_Algorithm_CLRS_Code
        01foundation/02getting_started/binaryAdder.cpp
        01foundation/02getting_started/inversion_count_using_merge_sort.cpp
        01foundation/02getting_started/linear_search.cpp
        01foundation/02getting_started/merge_sort.cpp
        01foundation/02getting_started/recursive_nd_iterative_binary_search.cpp
        01foundation/02getting_started/recursive_nd_iterative_insertion_sort.cpp
        01foundation/02getting_started/selection_sort.cpp
        01foundation/02getting_started/sum_check.cpp
        01foundation/04divide_conquer/75sqaure_matrix_multiplication.cpp
        01foundation/04divide_conquer/77recursive_sqaure_matrix_multiplication.cpp
        01foundation/04divide_conquer/P4.1.5iterative_max_sub_array.cpp
        01foundation/04divide_conquer/P4.1.3modified_max_array_with_mixed_brute_nd_recursive.cpp
        01foundation/04divide_conquer/75naive_matrix_multiplication.cpp
        01foundation/04divide_conquer/72recursive_max_sub_array.cpp
        02sorting_nd_order_statics/06heap_sort/max_min_iterative_recursive_heapify.cpp
        03data_structure/10elementary/dequeue/deque.cpp
        03data_structure/10elementary/dequeue/deque.h
        03data_structure/10elementary/linked_list/doubly/list_with_sentinal/list.cpp
        03data_structure/10elementary/linked_list/doubly/list_with_sentinal/list.h
        03data_structure/10elementary/linked_list/doubly/list.cpp
        03data_structure/10elementary/linked_list/doubly/list.h
        03data_structure/10elementary/linked_list/singly/list.cpp
        03data_structure/10elementary/linked_list/singly/list.h
        03data_structure/10elementary/queue/queue.cpp
        03data_structure/10elementary/queue/queue.h
        03data_structure/10elementary/queue/using_linked_list.cpp
        03data_structure/10elementary/queue/using_two_stack.cpp
        03data_structure/10elementary/set/set.cpp
        03data_structure/10elementary/set/set.h
        03data_structure/10elementary/stack/double_stack/double_stack.cpp
        03data_structure/10elementary/stack/double_stack/double_stack.h
        03data_structure/10elementary/stack/stack.cpp
        03data_structure/10elementary/stack/stack.h
        03data_structure/10elementary/stack/using_linked_list.cpp
        03data_structure/10elementary/stack/using_two_queue.cpp
        03data_structure/10elementary/tree/left_child_right_sibling/left_child.cpp
        03data_structure/10elementary/tree/Tree.cpp
        03data_structure/12bst/int_tree/tree.h
        03data_structure/12bst/int_tree/treemain.cpp
        03data_structure/13red_black/tree.cpp
        03data_structure/13red_black/tree.h
        03data_structure/14augmenting_structures/order_static.cpp
        03data_structure/14augmenting_structures/red_black_tree.h
        04advanced_design_technique/rot_cut.cpp 01foundation/04divide_conquer/P4.1.2bruteForce.cpp)
