#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 4;
    vector<int> arr = {1, 2, 3, 4};
    vector<int> prefixSum(n, 0);

    for (int i = 0; i < n; i++)
    {
        prefixSum[i] = arr[i];
        if (i + 1 < n)
        {
            prefixSum[i + 1] = -arr[i];
        }
    }

    for (int i = 1; i < n; i++)
    {
        prefixSum[i] += prefixSum[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << prefixSum[i] << " ";
    }

    return 0;
}
