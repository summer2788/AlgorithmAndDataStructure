// #include <iostream>

// int main()
// {
//     int arr[] = {64, 25, 12, 22, 11};
//     constexpr int length = std::size(arr);

//     for (int startIndex{1}; startIndex < length; startIndex++)
//     {
//         int key = arr[startIndex]; // the value being inserted
//         int currentIndex = startIndex - 1;
//         while (currentIndex >= 0 && arr[currentIndex] > key)
//         {
//             arr[currentIndex + 1] = arr[currentIndex];
//             currentIndex--;
//         }
//         arr[currentIndex + 1] = key;
//     }

//     for (int i{0}; i < length; i++)
//     {
//         std::cout << arr[i] << " ";
//     }
// }
