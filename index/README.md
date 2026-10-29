# LeetCode Stack Index

Automated problem index categorized by algorithmic taxonomy.

## Execution Stack

* **`C++`** (C++17): Direct memory manipulation and deterministic performance.
* **`Python 3`**: Standard library data structures and mathematical routines.
* **`Golang`** (Go 1.22): Static compilation, pre-allocated slices, and minimal runtime overhead.

## Arrays

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Distribute Elements I | `O(N)` | `O(1)` | [distribute_elements_i.go](../Arrays/distribute_elements_i.go) |
| Largest Almost Missing Integer | `O(N)` | `O(1)` | [largest_almost_missing_integer.py](../Arrays/largest_almost_missing_integer.py) |
| Lexicographically Smallest Array | `O(N)` | `O(1)` | [lexicographically_smallest_array.py](../Arrays/lexicographically_smallest_array.py) |

## Arrays / Math

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Minimum Operations to Sort a Permutation | `O(N) -> Pure linear state-space evaluation. Bypasses hardware modulo division with arithmetic jumps.` | `O(1) -> Strict constant space, zero dynamic memory allocations.` | [min_op_to_sort_permutation.go](../Arrays/min_op_to_sort_permutation.go) |

## Arrays / Math (Counting)

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Find Target Indices After Sorting Array | `O(N) - Single linear pass bypassing standard sorting overhead` | `O(1) - Zero extra allocation besides the required return slice` | [target_indices_after_sorting.go](../Arrays/target_indices_after_sorting.go) |

## Backtracking

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Combination Sum | `O(2^N)` | `O(N)` | [combination_sum.py](../Backtracking/combination_sum.py) |
| Combination Sum Ii | `O(2^N)` | `O(N)` | [combination_sum_ii.go](../Backtracking/combination_sum_ii.go) |
| Gen Parentheses | `O(2^N)` | `O(N)` | [generate_parentheses.go](../Backtracking/generate_parentheses.go) |
| Letter Combinations | `O(2^N)` | `O(N)` | [letter_combinations.py](../Backtracking/letter_combinations.py) |
| N Queens | `O(2^N)` | `O(N)` | [n_queens.py](../Backtracking/n_queens.py) |
| N Queens Ii | `O(2^N)` | `O(N)` | [n_queens_ii.go](../Backtracking/n_queens_ii.go) |
| Permutations | `O(2^N)` | `O(N)` | [permutations.go](../Backtracking/permutations.go) |
| Permutations Ii | `O(2^N)` | `O(N)` | [permutations_ii.go](../Backtracking/permutations_ii.go) |
| Sudoku Solver | `O(2^N)` | `O(N)` | [sudoku_solver.py](../Backtracking/sudoku_solver.py) |

## Binary_Search

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Find First Last Position | `O(log N)` | `O(1)` | [find_first_last_position.py](../Binary_Search/find_first_last_position.py) |
| Kth Smallest Amount | `O(log N)` | `O(1)` | [kth_smallest_amount.py](../Binary_Search/kth_smallest_amount.py) |
| Median Of Two Sorted Arrays | `O(log(min(M, N)))` | `O(1)` | [median_of_two_sorted_arrays.cpp](../Binary_Search/median_of_two_sorted_arrays.cpp) |
| Search Insert Position | `O(log N)` | `O(1)` | [search_insert_position.py](../Binary_Search/search_insert_position.py) |
| Search Rotated Array | `O(log N)` | `O(1)` | [search_rotated_array.py](../Binary_Search/search_rotated_array.py) |

## Bit Manipulation

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Maximum K to Sort a Permutation | `O(N) -> Pure linear scan with zero-state short-circuiting.` | `O(1) -> Strict constant space using a single scalar accumulator.` | [max_k_to_sort_permutation.go](../Bit_Manipulation/max_k_to_sort_permutation.go) |

## Bit Manipulation / Cycle Sort

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Minimum Swaps to Sort by Digit Sum | `O(N log N) - 64-bit Primitive Sorting` | `O(N) - Single 64-bit array, Zero Struct Overhead` | [min_swaps_to_sort.cpp](../Sorting/min_swaps_to_sort.cpp) |

## Bit_Manipulation

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Cinema Seat Allocation | `O(N)` | `O(1)` | [cinema_seat_allocation.py](../Bit_Manipulation/cinema_seat_allocation.py) |
| Longest Nonzero Xor | `O(N)` | `O(1)` | [longest_nonzero_xor.go](../Bit_Manipulation/longest_nonzero_xor.go) |

## Bitwise Math / Memory Allocation

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Maximum Nesting Depth of Two Valid Parentheses Strings | `O(N)` | `O(1) auxiliary` | [max_nesting_depth_two_vps.cpp](../Strings/max_nesting_depth_two_vps.cpp) |

## Cyclic_Sort

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| First Missing Positive | `O(N)` | `O(1)` | [first_missing_positive.go](../Sorting/first_missing_positive.go) |

## DFS / Bidirectional Scan

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Remove Invalid Parentheses | `O(N^2) - Absolute minimal branching` | `O(N) - Zero Hash Sets Allocation` | [remove_invalid_parentheses.cpp](../Backtracking/remove_invalid_parentheses.cpp) |

## DFS / Explicit State Routing

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Generate Parentheses | `O(4^N / sqrt(N)) - Catalan Number Bound` | `O(N) - Recursion Stack depth bound` | [generate_parentheses.py](../Backtracking/generate_parentheses.py) |

## Dynamic Programming

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Find X-Values of Subarrays Modulo K | `O(N * K)` | `O(K)` | [find_x_values_modulo_k.cpp](../Dynamic_Programming/find_x_values_modulo_k.cpp) |

## Dynamic Programming / Bit Manipulation

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Minimum XOR Path in a Grid | `O(m * n * min(1024, path_length)) -> Highly optimized state evaluation using Python's native Hash Sets.` | `O(n * 1024) -> Strictly 1D array of sets. Automatically garbage collected and dynamically sized.` | [min_path_xor_cost.py](../Dynamic_Programming/min_path_xor_cost.py) |
| Minimum XOR Path in a Grid | `O(m * n * 1024) -> Fully unrolled contiguous memory traversal evaluating all state sets natively.` | `O(n * 1024) -> Strictly stack-allocated C-style arrays. Zero heap allocations. L1/L2 cache optimized.` | [palindrome_path_queries_in_a_tree.go](../Trees/palindrome_path_queries_in_a_tree.go) |

## Dynamic Programming / Math Expansion

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Sum of Squares of Distinct Counts | `O(N^2)` | `O(N) - Strictly bounded state arrays` | [sum_squares_distinct_counts.py](../Dynamic_Programming/sum_squares_distinct_counts.py) |

## Dynamic_Programming

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Distinct Subsequences | `O(N^2)` | `O(N)` | [distinct_subsequences.go](../Dynamic_Programming/distinct_subsequences.go) |
| Distinct Subsequences Ii | `O(N^2)` | `O(N)` | [distinct_subsequences_ii.go](../Dynamic_Programming/distinct_subsequences_ii.go) |
| Maximum Subarray | `O(N^2)` | `O(N)` | [maximum_subarray.go](../Dynamic_Programming/maximum_subarray.go) |
| Maximum Weight 4 Intervals | `O(N^2)` | `O(N)` | [maximum_weight_4_intervals.py](../Dynamic_Programming/maximum_weight_4_intervals.py) |
| Regular Expressions Matching | `O(N^2)` | `O(N)` | [regular_expressions_matching.go](../Dynamic_Programming/regular_expressions_matching.go) |

## Fenwick Tree (Dual-BIT) / DP Math Expansion

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Sum of Squares of Distinct Counts II | `O(N log N) - Bare-metal bitwise hardware jumps` | `O(N) - Strictly 2N memory, destroying Segment Tree's 4N allocation` | [sum_squares_distinct_counts_hard.cpp](../Binary_Indexed_Tree/sum_squares_distinct_counts_hard.cpp) |

## Game_Theory

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Stone Game Ii | `O(N)` | `O(1)` | [stone_game_ii.cpp](../Game_Theory/stone_game_ii.cpp) |
| Stone Game Iv | `O(N)` | `O(1)` | [stone_game_iv.cpp](../Game_Theory/stone_game_iv.cpp) |
| Stone Game Ix | `O(N)` | `O(1)` | [stone_game_ix.py](../Game_Theory/stone_game_ix.py) |
| Stone Game V | `O(N)` | `O(1)` | [stone_game_v.py](../Game_Theory/stone_game_v.py) |
| Stone Game Vii | `O(N)` | `O(1)` | [stone_game_vii.cpp](../Game_Theory/stone_game_vii.cpp) |
| Sum Game | `O(N)` | `O(1)` | [sum_game.go](../Game_Theory/sum_game.go) |

## Graphs

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Shortest Path Cleanup Bitmask | `O(V + E)` | `O(V + E)` | [shortest_path_cleanup_bitmask.cpp](../Graphs/shortest_path_cleanup_bitmask.cpp) |

## Graphs / DFS

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Number of Closed Islands | `O(R * C) -> Bare-metal matrix traversal. Each land cell is visited and mutated exactly once.` | `O(1) auxiliary -> In-place grid mutation completely bypasses external visited array allocations.` | [number_of_closed_islands.go](../Graphs/number_of_closed_islands.go) |

## Graphs / DP / State Space Pruning

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Check if There Is a Valid Parentheses String Path | `O(m * n * (m + n))` | `O(m * n * (m + n))` | [check_valid_parentheses_path.cpp](../Graphs/check_valid_parentheses_path.cpp) |

## Graphs / Iterative DFS

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Count Islands With Total Value Divisible by K | `O(m * n) -> Pure bare-metal iterative traversal. Bypasses all recursive call stack allocations.` | `O(m * n) worst-case for the stack slice, but completely eliminates deep recursion memory bloat. Immediate sinking prevents duplicate pushes.` | [count_islands_with_total_value_divisible_by_k.go](../Graphs/count_islands_with_total_value_divisible_by_k.go) |

## Greedy

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Jump Game | `O(N)` | `O(1)` | [jump_game.py](../Greedy/jump_game.py) |
| Jump Game Ii | `O(N)` | `O(1)` | [jump_game_ii.cpp](../Greedy/jump_game_ii.cpp) |
| Lex Greater Permutation | `O(N)` | `O(1)` | [lex_greater_permutation.py](../Greedy/lex_greater_permutation.py) |
| Lexicographically Smallest Valid Sequence | `O(N)` | `O(1)` | [lexicographically_smallest_valid_sequence.cpp](../Greedy/lexicographically_smallest_valid_sequence.cpp) |
| Maximum Number of Non-Overlapping Substrings | `O(N)` | `O(1)` | [max_non_overlapping_substrings.py](../Greedy/max_non_overlapping_substrings.py) |
| Maximum Number of Non-overlapping Palindrome Substrings | `O(N * K)` | `O(1)` | [max_no_of_non_overlapping_palindrome_substrings.cpp](../Greedy/max_no_of_non_overlapping_palindrome_substrings.cpp) |
| Maximum Sum of Squares of K Elements | `O(N + K)` | `O(1)` | [maximum_sum_of_squares_of_k_elements.py](../Greedy/maximum_sum_of_squares_of_k_elements.py) |
| Min Deletions Min Max | `O(N)` | `O(1)` | [min_deletions_min_max.cpp](../Greedy/min_deletions_min_max.cpp) |
| Next Permutation | `O(N)` | `O(1)` | [next_permutation.py](../Greedy/next_permutation.py) |

## Greedy / Bucket Sort

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Minimum Sum of Squared Difference | `O(N + max_diff)` | `O(max_diff) - Zero Heap Allocation` | [min_sum_squared_diff.py](../Greedy/min_sum_squared_diff.py) |

## Greedy / State Space

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Valid Parenthesis String | `O(N)` | `O(1)` | [valid_parenthesis_string.cpp](../Greedy/valid_parenthesis_string.cpp) |

## Greedy / State Tracking

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Minimum Add to Make Parentheses Valid | `O(N)` | `O(1) - Zero Stack Allocation` | [minimum_add_to_make_valid.py](../Greedy/minimum_add_to_make_valid.py) |
| Minimum Insertions to Balance a Parentheses String | `O(N)` | `O(1) - Pure Register Tracking` | [minimum_insertions_to_balance.cpp](../Greedy/minimum_insertions_to_balance.cpp) |

## Hashing

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Group Anagrams | `O(N)` | `O(1)` | [group_anagrams.py](../Hashing/group_anagrams.py) |
| Two Sum | `O(N)` | `O(N)` | [two_sum.py](../Hashing/two_sum.py) |
| Valid Sudoku | `O(N)` | `O(1)` | [valid_sudoku.py](../Hashing/valid_sudoku.py) |

## Intervals

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Insert Interval | `O(N)` | `O(1)` | [insert_interval.py](../Intervals/insert_interval.py) |
| Merge Intervals | `O(N)` | `O(1)` | [merge_intervals.py](../Intervals/merge_intervals.py) |

## Intervals / Math

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Count Days Spent Together | `O(1) -> Bare-metal byte parsing and direct arithmetic lookups. Bypasses all standard string/time library overheads.` | `O(1) -> Strict constant space. Zero dynamic memory allocations, using a static prefix array.` | [count_days_together.go](../Intervals/count_days_together.go) |

## Linked_Lists

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Add Two Numbers | `O(N)` | `O(1)` | [add_two_numbers.cpp](../Linked_Lists/add_two_numbers.cpp) |
| Critical Points Distance | `O(N)` | `O(1)` | [critical_points_distance.cpp](../Linked_Lists/critical_points_distance.cpp) |
| Merge K Lists | `O(N)` | `O(1)` | [merge_k_lists.go](../Linked_Lists/merge_k_lists.go) |
| Merge Two Lists | `O(N)` | `O(1)` | [merge_two_lists.go](../Linked_Lists/merge_two_lists.go) |
| Remove Nth Node | `O(N)` | `O(1)` | [remove_nth_node.py](../Linked_Lists/remove_nth_node.py) |
| Reverse K Group | `O(N)` | `O(1)` | [reverse_k_group.py](../Linked_Lists/reverse_k_group.py) |
| Rotate List | `O(N)` | `O(1)` | [rotate_list.cpp](../Linked_Lists/rotate_list.cpp) |
| Swap Pairs | `O(N)` | `O(1)` | [swap_pairs.py](../Linked_Lists/swap_pairs.py) |

## Math

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Array Parity Construct | `O(N)` | `O(1)` | [array_parity_construct.go](../Math/array_parity_construct.go) |
| Circle and Rectangle Overlapping | `O(1)` | `O(1)` | [circle_and_rectangle_overlapping.cpp](../Math/circle_and_rectangle_overlapping.cpp) |
| Count Commas In Line Ii | `O(N)` | `O(1)` | [count_commas_in_line_ii.py](../Math/count_commas_in_line_ii.py) |
| Divide Integers Alu | `O(N)` | `O(1)` | [divide_integers_alu.go](../Math/divide_integers_alu.go) |
| Divisible By Sum Product | `O(N)` | `O(1)` | [divisible_by_sum_product.cpp](../Math/divisible_by_sum_product.cpp) |
| Integer To Roman | `O(N)` | `O(1)` | [integer_to_roman.go](../Math/integer_to_roman.go) |
| Missing Multiple | `O(N)` | `O(1)` | [missing_multiple.cpp](../Math/missing_multiple.cpp) |
| Number Of Commas | `O(N)` | `O(1)` | [number_of_commas.py](../Math/number_of_commas.py) |
| Number of Sets of K Non-Overlapping Line Segments | `O(K)` | `O(1)` | [k_non_overlapping_line_segments.cpp](../Math/k_non_overlapping_line_segments.cpp) |
| Palindrome No | `O(N)` | `O(1)` | [palindrome_no.cpp](../Math/palindrome_no.cpp) |
| Permutation Sequence | `O(N)` | `O(1)` | [permutation_sequence.cpp](../Math/permutation_sequence.cpp) |
| Pow X N | `O(N)` | `O(1)` | [pow_x_n.py](../Math/pow_x_n.py) |
| Rectangle Overlap | `O(1)` | `O(1)` | [rectangle_overlap.py](../Math/rectangle_overlap.py) |
| Reverse Integer | `O(N)` | `O(1)` | [reverse_integer.cpp](../Math/reverse_integer.cpp) |
| Roman To Integer | `O(N)` | `O(1)` | [roman_to_integer.py](../Math/roman_to_integer.py) |
| Smallest Divisible Digit Product Ii | `O(N)` | `O(1)` | [smallest_divisible_digit_product_ii.cpp](../Math/smallest_divisible_digit_product_ii.cpp) |
| Smallest Index With Equal Sum | `O(1)` | `O(1)` | [smallest_index_with_equal_sum.py](../Math/smallest_index_with_equal_sum.py) |
| Three Digit Even Count | `O(N)` | `O(1)` | [three_digit_even_count.py](../Math/three_digit_even_count.py) |
| Uniform Parity Array Ii | `O(N)` | `O(1)` | [uniform_parity_array_ii.go](../Math/uniform_parity_array_ii.go) |
| Unique Paths | `O(N)` | `O(1)` | [unique_paths.py](../Math/unique_paths.py) |

## Math / Arrays

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Sum of Squares of Special Elements | `O(N)` | `O(1) - Zero Auxiliary Memory` | [sum_of_squares_special_elements.py](../Arrays/sum_of_squares_special_elements.py) |

## Math / Arrays / Prefix Sums

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Sortable Integers | `O(N + σ(N)) - Linear precomputation + O(1) block evaluations. Completely bypasses TLE.` | `O(N) - State tracking arrays for prefix max, suffix min, and drops.` | [sum_sortable_divisors.go](../Math/sum_sortable_divisors.go) |

## Math / Bitwise

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Score of Parentheses | `O(N)` | `O(1) - Zero Stack Allocation` | [score_of_parentheses.py](../Math/score_of_parentheses.py) |

## Math / Combinatorics / Doubly Linked List (Interval Merging)

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Number of Ways to Reorder Array to Get Same BST | `O(N) - Bare-metal linear pass` | `O(N) - 1D State Tracking Arrays` | [ways_to_reorder_bst.py](../Math/ways_to_reorder_bst.py) |

## Math / Greedy String Construction

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Maximum Good Integer (maxSumOfSquares) | `O(N) - Hardware-level memory fill` | `O(N) - Pre-allocated contiguous memory` | [max_good_integer.cpp](../Strings/max_good_integer.cpp) |

## Math / Quickselect (Vectorized)

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Maximum Alternating Score | `O(N) Expected - via np.partition` | `O(N) - NumPy C-array allocation` | [max_alternating_score.py](../Greedy/max_alternating_score.py) |

## Matrices

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Image Overlap | `O(M * N)` | `O(M * N)` | [image_overlap.py](../Matrices/image_overlap.py) |
| Rotate Image | `O(M * N)` | `O(M * N)` | [rotate_image.cpp](../Matrices/rotate_image.cpp) |
| Spiral Matrix | `O(M * N)` | `O(M * N)` | [spiral_matrix.py](../Matrices/spiral_matrix.py) |
| Spiral Matrix Ii | `O(M * N)` | `O(M * N)` | [spiral_matrix_ii.py](../Matrices/spiral_matrix_ii.py) |

## Matrices / Constructive

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Create Grid With Exactly One Path | `O(m * n) -> Zero string concatenations. Direct memory assignment and fast I/O detachment.` | `O(1) auxiliary -> Single obstacle template copied directly. Overwrites memory block in-place.` | [create_grid_exactly_one_path.cpp](../Matrices/create_grid_exactly_one_path.cpp) |

## Prefix_Sum

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| First Stable Index | `O(N)` | `O(1)` | [first_stable_index.go](../Prefix_Sum/first_stable_index.go) |
| Sequential Prefix Sum | `O(N)` | `O(1)` | [sequential_prefix_sum.py](../Prefix_Sum/sequential_prefix_sum.py) |
| Smallest Stable Index | `O(N)` | `O(1)` | [smallest_stable_index.go](../Prefix_Sum/smallest_stable_index.go) |

## Segment Tree

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Find X-Values of Subarrays Modulo K (Range Queries) | `O(N + Q \log N)` | `O(N * K)` | [x_values_modulo_k_queries.cpp](../Segment_Tree/x_values_modulo_k_queries.cpp) |

## Segment_Tree

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Longest Repeat Substr | `O(N)` | `O(1)` | [longest_repeat_substr.go](../Segment_Tree/longest_repeat_substr.go) |

## Sliding Window

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Find Two Non-overlapping Sub-arrays Each With Target Sum | `O(N)` | `O(N)` | [min_sum_of_lengths.cpp](../Sliding_Window/min_sum_of_lengths.cpp) |
| Minimum Operations to Reduce X to Zero | `O(N)` | `O(1)` | [min_operations_reduce_x_to_zero.py](../Sliding_Window/min_operations_reduce_x_to_zero.py) |

## Sliding_Window

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Longest Subarray K Freq | `O(N)` | `O(1)` | [longest_subarray_k_freq.py](../Sliding_Window/longest_subarray_k_freq.py) |
| Longest Substring Without Rep Chars | `O(N)` | `O(1)` | [longest_substring_without_rep_chars.cpp](../Sliding_Window/longest_substring_without_rep_chars.cpp) |
| Max Len Substr 2 Occ | `O(N)` | `O(1)` | [max_len_substr_2_occ.py](../Sliding_Window/max_len_substr_2_occ.py) |
| Substring Concat Words | `O(N)` | `O(1)` | [substring_concat_words.go](../Sliding_Window/substring_concat_words.go) |

## Stack

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Valid Parentheses | `O(N)` | `O(N)` | [valid_parentheses.py](../Stacks/valid_parentheses.py) |

## Stack / O(N) Wormhole Traversal

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Reverse Substrings Between Each Pair of Parentheses | `O(N)` | `O(N)` | [reverse_substrings_parentheses.py](../Stacks/reverse_substrings_parentheses.py) |

## Stack / Parser

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Brace Expansion II | `O(N + K log K) - N is string len, K is output size` | `O(K) - Minimal memory footprint` | [brace_expansion_compiler.py](../Stacks/brace_expansion_compiler.py) |

## Stacks

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Longest Valid Parentheses | `O(N)` | `O(1)` | [longest_valid_parentheses_stack_bypass.py](../Two_Pointers/longest_valid_parentheses_stack_bypass.py) |
| Valid Parentheses | `O(N)` | `O(1)` | [valid_parentheses.go](../Stacks/valid_parentheses.go) |

## String Manipulation / Hash Map

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Evaluate the Bracket Pairs of a String | `O(N + K)` | `O(N + K)` | [evaluate_bracket_pairs.cpp](../Strings/evaluate_bracket_pairs.cpp) |

## Strings

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Count And Say | `O(N)` | `O(1)` | [count_and_say.py](../Strings/count_and_say.py) |
| First Occurrence Str | `O(N)` | `O(1)` | [first_occurrence_str.go](../Strings/first_occurrence_str.go) |
| Length Of Last Word | `O(N)` | `O(1)` | [length_of_last_word.py](../Strings/length_of_last_word.py) |
| Longest Common Prefix | `O(N)` | `O(1)` | [longest_common_prefix.py](../Strings/longest_common_prefix.py) |
| Multiply Strings | `O(N)` | `O(1)` | [multiply_strings.py](../Strings/multiply_strings.py) |
| Next Greater Palindrome | `O(N)` | `O(1)` | [next_greater_palindrome.py](../Strings/next_greater_palindrome.py) |
| Reverse Degree of a String | `O(N)` | `O(1)` | [reverse_degree_of_a_string.cpp](../Strings/reverse_degree_of_a_string.cpp) |
| Shortest Beautiful Substring | `O(N)` | `O(1)` | [shortest_beautiful_substring.go](../Strings/shortest_beautiful_substring.go) |
| String To Integer Atoi | `O(N)` | `O(1)` | [string_to_integer_atoi.cpp](../Strings/string_to_integer_atoi.cpp) |
| Wildcard Matching | `O(N)` | `O(1)` | [wildcard_matching.cpp](../Strings/wildcard_matching.cpp) |
| Zigzag Conversion | `O(N)` | `O(1)` | [zigzag_conversion.cpp](../Strings/zigzag_conversion.cpp) |

## Strings / Greedy

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Minimum Operations to Make String Sorted | `O(N) -> Pure linear scans using STL is_sorted and bare-metal loops.` | `O(1) -> Strict constant space, purely tracking min/max chars and state flags.` | [minimum_operations_to_sort_string.cpp](../Strings/minimum_operations_to_sort_string.cpp) |

## Strings / State Machine

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Maximum Nesting Depth of the Parentheses | `O(N)` | `O(1)` | [maximum_nesting_depth.cpp](../Strings/maximum_nesting_depth.cpp) |

## Strings / State Tracking

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Remove Outermost Parentheses | `O(N)` | `O(N) - Result string allocation` | [remove_outermost_parentheses.cpp](../Strings/remove_outermost_parentheses.cpp) |

## Trees

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Subtree Average | `O(N)` | `O(H)` | [subtree_average.py](../Trees/subtree_average.py) |

## Two Pointers

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Longest Valid Parentheses | `O(N)` | `O(1) - Pure Bare-Metal Execution` | [longest_valid_parentheses.cpp](../Two_Pointers/longest_valid_parentheses.cpp) |

## Two_Pointers

| Problem | Time Complexity | Space Complexity | File |
|---|---|---|---|
| Container With Most Water | `O(N)` | `O(1)` | [container_with_most_water.go](../Two_Pointers/container_with_most_water.go) |
| Four Sum | `O(N)` | `O(1)` | [four_sum.py](../Two_Pointers/four_sum.py) |
| Longest Palindromic Substring | `O(N^2)` | `O(1)` | [longest_palindromic_substring.cpp](../Two_Pointers/longest_palindromic_substring.cpp) |
| Rm Duplicates | `O(N)` | `O(1)` | [rm_duplicates.py](../Two_Pointers/rm_duplicates.py) |
| Rm Element | `O(N)` | `O(1)` | [rm_element.py](../Two_Pointers/rm_element.py) |
| Three Sum | `O(N)` | `O(1)` | [three_sum.py](../Two_Pointers/three_sum.py) |
| Three Sum Closest | `O(N)` | `O(1)` | [three_sum_closest.py](../Two_Pointers/three_sum_closest.py) |
| Trapping Rain Water | `O(N)` | `O(1)` | [trapping_rain_water.py](../Two_Pointers/trapping_rain_water.py) |

