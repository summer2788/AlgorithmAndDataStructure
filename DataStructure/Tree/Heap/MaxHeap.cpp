/*
Heap is a data structure that satisfy the complete binary tree property and the property that
of priority of the parent node is highert than the child one.
key
*/

// #include <iostream>
// #include <vector>

// // Max Heap
// class BinaryHeap
// {
// private:
//     std::vector<int> heap;

//     void swap(int a, int b)
//     {
//         int temp = heap[a];
//         heap[a] = heap[b];
//         heap[b] = temp;
//     }

//     void downHeap(int index)
//     {
//         while (2 * index + 1 <= heap.size() - 1)
//         {
//             int k = 2 * index + 1;
//             if (k + 1 <= heap.size() && heap[k] < heap[k + 1])
//                 k++;
//             if (heap[k] < heap[index])
//                 break;
//             swap(index, k);
//             index = k;
//         }
//     }

//     void upHeap(int index)
//     {
//         while (index > 0 && heap[index] > heap[(index - 1) / 2])
//         {
//             swap(index, (index - 1) / 2);
//             index = (index - 1) / 2;
//         }
//     }

// public:
//     // Default Constructor
//     BinaryHeap() {}
//     // Constructor to build heap from vector
//     BinaryHeap(const std::vector<int> &input)
//     {
//         BuildHeap(input);
//     }

//     void BuildHeap(const std::vector<int> &input)
//     {
//         heap = input;
//         for (int i = heap.size() / 2 - 1; i >= 0; --i)
//         {
//             downHeap(i);
//         }
//     }

//     void insert(int input)
//     {
//         heap.push_back(input);
//         upHeap(heap.size() - 1);
//     }

//     int ExtractMax()
//     {
//         int max = heap[0];
//         swap(0, heap.size() - 1);
//         downHeap(0);
//         heap.pop_back();
//         return max;
//     }

//     void PrintHeap()
//     {
//         for (int i{0}; i < heap.size(); ++i)
//         {
//             std::cout << heap[i] << " ";
//         }
//     }
// };

// int main()
// {
//     BinaryHeap maxHeap;

//     maxHeap.insert(10);
//     maxHeap.insert(20);
//     maxHeap.insert(30);
//     maxHeap.insert(5);
//     maxHeap.insert(7);
//     maxHeap.insert(40);

//     maxHeap.PrintHeap();

//     std::cout << "Extracted max: " << maxHeap.ExtractMax() << std::endl;
//     maxHeap.PrintHeap();

//     return 0;
// }
