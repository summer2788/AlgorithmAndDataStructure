#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int Find(int a);

void Union(int a, int b)
{
    int aRoot = Find(a);
    int bRoot = Find(b);
    parent[aRoot] = bRoot;
}

int Find(int a)
{
    if (parent[a] == a)
    {
        return a;
    }

    return parent[a] = Find(parent[a]);
}

int main()
{
    int n = 10;
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    Union(1, 2);
    Union(2, 3);
    Union(3, 4);
    Union(5, 6);
    Union(6, 7);
    Union(7, 8);

    cout << Find(1) << endl;
    cout << Find(2) << endl;
    cout << Find(3) << endl;
    cout << Find(4) << endl;
    cout << Find(5) << endl;
    cout << Find(6) << endl;
    cout << Find(7) << endl;
    cout << Find(8) << endl;

    return 0;
}
