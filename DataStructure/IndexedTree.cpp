#include <iostream>
#include <vector>

using namespace std;

class IDT
{
public:
    IDT(int size) : idt(size * 4)
    {
        for (start = 1; start < size; start <<= 1)
            ;
    }

    void update(int node, int v)
    {
        node += (start - 1);
        idt[node] = v;
        while (node >>= 1)
        {
            idt[node] = idt[node << 1] + idt[(node << 1) | 1];
        }
    }

    int query(int l, int r)
    {
        l += (start - 1);
        r += (start - 1);

        int sum = 0;
        while (l <= r)
        {
            if ((l & 1) == 1)
            {
                sum += idt[l];
            }
            if ((r & 1) == 0)
            {
                sum += idt[r];
            }

            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }

        return sum;
    }

private:
    vector<int> idt;
    int start;
};

int main()
{

    IDT idt(8);
    idt.update(1, 1);
    idt.update(2, 2);
    idt.update(3, 3);
    idt.update(4, 4);
    idt.update(5, 5);
    idt.update(6, 6);
    idt.update(7, 7);
    idt.update(8, 8);

    cout << idt.query(1, 8) << endl;

    return 0;
}
