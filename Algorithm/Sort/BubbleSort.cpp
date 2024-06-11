// #include <iostream>

// int main()
// {
//     int arr[] = {64, 25, 12, 22, 11};
//     constexpr int length = std::size(arr);

//     for (int i{0}; i < length - 1; i++) // how many it will iterate
//     {
//         bool isSwapped = false;
//         for (int j{0}; j < length - 1 - i; j++)
//         {

//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//                 isSwapped = true;
//             }
//         }

//         if (!isSwapped)
//         {
//             break;
//         }
//     }

//     for (int i{0}; i < length; i++)
//     {
//         std::cout << arr[i] << " ";
//     }
// }
