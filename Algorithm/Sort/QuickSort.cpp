// O(NlogN)
// #include <iostream>

// int Partition(int arr[], int pivot, int high)
// {
//     int i = pivot + 1;
//     int j = high;
//     while (true)
//     {
//         while (i < high && arr[i] < arr[pivot])
//         {
//             i += 1;
//         }
//         while (j > pivot && arr[j] > arr[pivot])
//         {
//             j--;
//         }
//         if (j <= i)
//         {
//             break;
//         }

//         std::swap(arr[i], arr[j]);
//         i++;
//         j--;
//     }

//     std::swap(arr[j], arr[pivot]);
//     return j;
// }

// void QuickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pivot = Partition(arr, low, high);
//         QuickSort(arr, low, pivot - 1);
//         QuickSort(arr, pivot + 1, high);
//     }
// }

// void PrintArray(const int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
// }

// int main()
// {
//     int arr[] = {39, 23, 15, 47, 11, 56, 61, 16, 12, 19, 21, 41};
//     int length = sizeof(arr) / sizeof(arr[0]);

//     std::cout << "Array before sorting: ";
//     PrintArray(arr, length);

//     QuickSort(arr, 0, length - 1);

//     std::cout << "Array after sorting: ";
//     PrintArray(arr, length);

//     return 0;
// }
