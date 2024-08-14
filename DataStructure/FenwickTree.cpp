#include <iostream>
#include <vector>

using namespace std;

class FT
{
public:
    FT(int N) : tree(N + 1)
    {
    }

    void update(int i, int num)
    {
        while (i <= tree.size())
        {
            tree[i] += num;
            i += (i & -i);
        }
    }

    int sum(int i)
    {
        int res = 0;
        while (i > 0)
        {
            res += tree[i];
            i -= (i & -i);
        }
        return res;
    }

private:
    vector<int> tree;
};

int main()
{
    FT ft(10);
    ft.update(1, 1);
    ft.update(2, 2);
    ft.update(3, 3);
    ft.update(4, 4);
    ft.update(5, 5);
    ft.update(6, 6);
    ft.update(7, 7);
    ft.update(8, 8);
    ft.update(9, 9);
    ft.update(10, 10);

    cout << ft.sum(10) << endl;

    return 0;
}
