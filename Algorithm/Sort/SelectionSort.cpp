// #include <iostream>
// #include <iterator> // for std::size

// void swap(int *xp, int *yp)
// {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }

// int main()
// {
//     // Selection Sort
//     int arr[] = {64, 25, 12, 22, 11};
//     int length = std::size(arr);

//     for (int i{0}; i < length - 1; i++)
//     {
//         int minIndex = i;
//         for (int j{i + 1}; j < length; j++)
//         {
//             if (arr[j] < arr[minIndex])
//             {
//                 minIndex = j;
//             }
//         }

//         swap(&arr[minIndex], &arr[i]);
//     }

//     for (int i{0}; i < length; i++)
//     {
//         std::cout << arr[i] << " ";
//     }
// }
