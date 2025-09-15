// // O(nlogn)

// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to partition the array
// int partition(vector<int> &arr, int low, int high)
// {
//     int pivot = arr[high]; // Choose the pivot
//     int i = low - 1;       // Index of smaller element

//     for (int j = low; j < high; j++)
//     {
//         // If the current element is smaller than the pivot
//         if (arr[j] < pivot)
//         {
//             i++; // Move the boundary for elements smaller than pivot
//             swap(arr[i], arr[j]);
//         }
//     }
//     // Place the pivot element in the correct position
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// // Quick Sort function
// void quickSort(vector<int> &arr, int low, int high)
// {
//     if (low < high)
//     {
//         // Partition the array
//         int pi = partition(arr, low, high);

//         // Recursively sort elements before and after partition
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main()
// {
//     vector<int> arr = {10, 80, 30, 90, 40, 50, 70};
//     int n = arr.size();

//     cout << "Original array: ";
//     for (int x : arr)
//         cout << x << " ";
//     cout << endl;

//     quickSort(arr, 0, n - 1);

//     cout << "Sorted array: ";
//     for (int x : arr)
//         cout << x << " ";
//     cout << endl;

//     return 0;
// }
