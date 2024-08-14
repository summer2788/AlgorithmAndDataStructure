
# AlgorithmAndDataStructure

Welcome to the **AlgorithmAndDataStructure** repository! This repository contains a collection of algorithms and data structures implemented in C++. It is designed for anyone interested in learning or referencing fundamental algorithms and data structures commonly used in computer science.

## Table of Contents

- [Project Structure](#project-structure)
- [Algorithms Included](#algorithms-included)
- [Data Structures Included](#data-structures-included)
- [How to Use](#how-to-use)
- [Contributing](#contributing)
- [License](#license)

## Project Structure

The repository is organized into two main directories:

1. **Algorithm/** - Contains various algorithm implementations.
   - **Graph/** - This subdirectory includes algorithms related to graph theory.
   - **Sort/** - This subdirectory contains sorting algorithms.

2. **DataStructure/** - Contains various data structure implementations.

Each algorithm or data structure is implemented in a separate `.cpp` file for clarity and ease of use.

## Algorithms Included

### Graph Algorithms
- **Bellman-Ford Algorithm** (`Bellmanford.cpp`): Computes shortest paths from a single source vertex to all other vertices in a weighted graph.
- **Cut Vertices Algorithm** (`CutVertices.cpp`): Finds articulation points in a graph.
- **Dijkstra's Algorithm** (`Dijkstra.cpp`): Solves the single-source shortest path problem for a graph with non-negative edge weights.
- **Floyd-Warshall Algorithm** (`FloydWarshall.cpp`): Solves the all-pairs shortest path problem.
- **Kruskal's Algorithm** (`kruskalAlgorithm.cpp`): Finds the minimum spanning tree for a connected, undirected graph.
- **Lowest Common Ancestor (LCA)** (`LCA.cpp`): Finds the lowest common ancestor of two nodes in a tree.
- **Prim's Algorithm** (`primAlgorithm.cpp`): Finds the minimum spanning tree of a weighted, undirected graph.
- **Union-Find Algorithm** (`UnionFind.cpp`): Disjoint-set data structure with union and find operations.

### Sorting Algorithms
- **Bubble Sort** (`BubbleSort.cpp`): A simple comparison-based sorting algorithm with a time complexity of O(n^2).
- **Heap Sort** (`HeapSort.cpp`): An efficient comparison-based sorting algorithm that uses a binary heap, with a time complexity of O(n log n).
- **Insertion Sort** (`InsertionSort.cpp`): A simple sorting algorithm that builds the final sorted array one item at a time, with a time complexity of O(n^2).
- **Merge Sort** (`MergeSort.cpp`): A divide-and-conquer sorting algorithm that divides the array into halves, sorts them, and then merges them back together, with a time complexity of O(n log n).
- **Quick Sort** (`QuickSort.cpp`): A highly efficient sorting algorithm that uses partitioning, with a time complexity of O(n log n) on average.
- **Selection Sort** (`SelectionSort.cpp`): A simple comparison-based sorting algorithm that selects the smallest element and swaps it with the first unsorted element, with a time complexity of O(n^2).
- **Shell Sort** (`ShellSort.cpp`): A generalization of insertion sort that allows the exchange of far apart elements, with a time complexity that depends on the gap sequence used.

## Data Structures Included

### Trees
- **Binary Search Tree** (`BinarySearchTree.cpp`): A tree data structure in which each node has at most two children, used for efficient searching, insertion, and deletion.
- **Fenwick Tree** (`FenwickTree.cpp`): Also known as a binary indexed tree, used for efficiently updating elements and calculating prefix sums.
- **Indexed Tree** (`IndexedTree.cpp`): Also known as a segment tree, used for answering range queries and updating array elements.
- **Segment Tree** (`SegmentTree.cpp`): A tree data structure used for storing information about intervals or segments, useful for answering range queries.
- **Segment Tree with Lazy Propagation** (`SegmentTree_lazyPropogation.cpp`): An enhanced segment tree that supports range updates efficiently.

### Linked Lists
- **Singly Linked List** (`SinglyLinkedList.cpp`): A linked list where each node contains a single link to the next node.
- **Doubly Linked List** (`DoublyLinkedList.cpp`): A linked list where each node contains two links, one to the next node and another to the previous node.
- **Circular Linked List** (`CircularLinkedList.cpp`): A linked list where the last node points to the first node, forming a circle.

### Hashing
- **Chaining Method** (`chaining.cpp`): A method of handling collisions in a hash table by chaining all elements that hash to the same index.

### Heaps
- **Max Heap** (`MaxHeap.cpp`): A complete binary tree where the value of each node is greater than or equal to the values of its children.

### Hash Tables
- **Linear Probing** (`LinearProbing.cpp`): A collision resolution technique in hash tables where, upon collision, the algorithm checks the next slots until it finds an empty one.

### Miscellaneous
- **Node Class** (`Node.h`): A header file defining a generic node structure for various data structures.

## How to Use

1. **Clone the repository:**
   ```bash
   git clone https://github.com/summer2788/AlgorithmAndDataStructure.git
   ```
2. **Navigate to the specific algorithm or data structure:**
   ```bash
   cd AlgorithmAndDataStructure/Algorithm/Sort
   ```
3. **Compile and run the C++ file:**
   ```bash
   g++ QuickSort.cpp -o QuickSort
   ./QuickSort
   ```

## Contributing

Contributions are welcome! If you have any improvements or additional algorithms or data structures to add, please submit a pull request. Make sure to include a clear description of your changes and the problem your code solves.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


