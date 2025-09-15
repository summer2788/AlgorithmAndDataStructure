
#include <iostream>

// Exact TC analysis is hard
// but in this case O(N^2)

int main()
{
    int arr[] = {39, 23, 15, 47, 11, 56, 61, 16, 12, 19, 21, 41};
    constexpr int length = std::size(arr);

    for (int gap = length / 2; gap >= 1; gap /= 2)
    {
        for (int i = gap; i < length; i++)
        {
            int tempt = arr[i]; // item to be inserted

            int j = i;
            // j >= gab because j- gap should be >=0
            while (j >= gap && arr[j - gap] > tempt) // Start insertion sort
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tempt;
        }
    }

    for (int i{0}; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
}
