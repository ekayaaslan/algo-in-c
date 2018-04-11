# algo-in-c
Yet another algorithms package written in C

The primary design principle is to be useful like all many others. Some more specific principles:

1) Self-containment matters. No excessive use of other files in the library.
2) No bulk allocation from memory, if needed an array of bytes should be provided in the parameter list from the callee.
3) Avoid using recursion if not logarithmic or less.
4) Efficiency matters. Operate on sparse graphs.

Data Structures
---
[Binary Search Tree](/source/binary_search_tree.c) <br />
[Priority Queue](/source/priority_queue.c) <br />
[Stack](/source/stack.c) <br />
[Queue](/source/queue.c) <br />
[Red Black Tree](/source/red_black_tree.c) <br />
Disjoint Set <br />

Algorithms
---
[Bentley McIlroy 3way Partition](/source/bentley_mcilroy_3way_partition.c) <br />
[Graph Connected Components](/source/graph_connected_components.c) <br />
[Depth First Search](/source/depth_first_search.c) <br />
[Graph Depth First Search Preorder](/source/graph_dfs_preorder.c) <br />
[Graph Depth First Search Postorder](/source/graph_dfs_postorder.c) <br />
[Tree Preorder](/source/tree_preorder.c) <br />
[Tree Postorder](/source/tree_postorder.c) <br />
[Topological Order](/source/topological_order.c) <br />
[Greatest Common Divisor](/source/greatest_common_divisor.c) <br />
[Heap Sort](/source/heap_sort.c) <br />
[Insertion Sort](/source/insertion_sort.c) <br />
[Knuth Shuffle](/source/knuth_shuffle.c) <br />
[Kosarajo Sharir Strongly Connected Components](/source/kosarajo_sharir_scc.c) <br />
[Push Relabel Maximum Flow](/source/push_relabel_max_flow.c) <br />
[Quicksort](/source/quicksort.c) <br />
Maximum Cardinality Bipartite Matching <br />
Maximum Weighted Bipartite Matching <br />
Hungarian Algorithm <br />
Edmond Blossom Algorithm <br />
Maximum Cardinality Matching <br />
Ford Fulkerson Maximum Flow <br />
Karp Mean Cycle <br />
Karp Sipser Randomized Matching <br />
Howard Mean Cycle <br />
Sloer Wegner Minimum Cut <br />
Dijsktra Shortest Path <br />
Bellman Ford Shortest Path <br />
Prim Minimum Spanning Tree <br />
Kruskal Minimum Spanning Tree <br />
Boruvska Minimum Spanning Tree <br />
Sieve of Erastothenes <br />
Counting Sort <br />
Quick Select <br />
Bipartite Stable Matching <br />
Eulerian Path <br />
Prime Factorization <br />
Euclid Extended Algorithm <br />
Modular Multiplicative Inverse <br />
Floyd Warshall All Pairs Shortest Path <br />
Merge Sort <br />
Manacher Longest Palindromic Substring <br />
Johnson All Pairs Shortest Path <br />
Jarvis Convex Hull <br />
Graham Scan <br />
Knuth Morris Pratt String Search <br />
Run Length Encoding <br />
Huffman Coding <br />
Lempel Zip Compression <br />
Burrows Wheeler Transform <br />
Breath First Search <br />
