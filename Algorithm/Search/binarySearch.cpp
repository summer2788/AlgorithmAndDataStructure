/*
binary search
lower bound and upper bound
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int n;

int LowerBound(int key)
{
    int lb = -1, ub = n;
    while (lb + 1 < ub)
    {
        int mid = (lb + ub) / 2;
        if (a[mid] < key)
            lb = mid;
        else
            ub = mid;
    }
    return ub;
}

int UpperBound(int key)
{
    int lb = -1, ub = n;
    while (lb + 1 < ub)
    {
        int mid = (lb + ub) / 2;
        if (a[mid] <= key)
            lb = mid;
        else
            ub = mid;
    }
    return ub;
}

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int key;
    cin >> key;
    cout << LowerBound(key) << endl;

    return 0;
}
