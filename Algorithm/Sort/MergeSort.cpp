// #include <iostream>

// // O(NlogN)

// void Merge(int arr[], int low, int mid, int high)
// {
//     int n1 = mid - low + 1;
//     int n2 = high - mid;

//     // create tempt arrays
//     int *leftArray = new int[n1];
//     int *rightArray = new int[n2];

//     // copy data to temp arrays
//     for (int i = 0; i < n1; i++)
//     {
//         leftArray[i] = arr[low + i];
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         rightArray[i] = arr[mid + 1 + i];
//     }

//     // Merge the tempt array back into arr
//     int i = 0;   // initial index of left array
//     int j = 0;   // initial index of right array
//     int k = low; // initial index of merged subarray

//     while (i < n1 && j < n2)
//     {
//         if (leftArray[i] <= rightArray[j])
//         {
//             arr[k] = leftArray[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = rightArray[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1)
//     {
//         arr[k] = leftArray[i];
//         i++;
//         k++;
//     }
//     while (j < n2)
//     {
//         arr[k] = rightArray[j];
//         j++;
//         k++;
//     }

//     delete[] leftArray;
//     delete[] rightArray;
// }

// void MergeSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int mid = low + (high - low) / 2;
//         MergeSort(arr, low, mid);
//         MergeSort(arr, mid + 1, high);
//         Merge(arr, low, mid, high);
//     }
// }

// void PrintArray(const int arr[], int length)
// {
//     for (int i = 0; i < length; i++)
//     {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << '\n';
// }

// int main()
// {
//     int arr[] = {39, 23, 15, 47, 11, 56, 61, 16, 12, 19, 21, 41};
//     int length = sizeof(arr) / sizeof(arr[0]);

//     std::cout << "Array before sorting: ";
//     PrintArray(arr, length);

//     MergeSort(arr, 0, length - 1);

//     std::cout << "Array after sorting: ";
//     PrintArray(arr, length);

//     return 0;
// }
