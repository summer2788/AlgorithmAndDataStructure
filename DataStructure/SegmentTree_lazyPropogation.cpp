#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
public:
    SegmentTree(const vector<int> &initialA) : arr(initialA), st(arr.size() * 4), lazy(st.size())
    {
        build(1, 0, arr.size() - 1);
    }

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            st[node] = arr[l];
        }
        else
        {
            build(node * 2, l, (l + r) / 2);
            build(node * 2 + 1, (l + r) / 2 + 1, r);
            st[node] = st[node * 2] + st[node * 2 + 1];
        }
    }

    void lazy_update(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            st[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int L, int R, int diff)
    {
        lazy_update(node, start, end); // check if lazy is set
        if (end < L || R < start)
        {
            return;
        }

        if (L <= start && end <= R)
        {
            st[node] += (end - start + 1) * diff;
            // set the lazy if child exist
            if (start != end)
            {
                lazy[node * 2] += diff;
                lazy[node * 2 + 1] += diff;
            }
            return;
        }

        update(node * 2, start, (start + end) / 2, L, R, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, L, R, diff);
        st[node] = st[node * 2] + st[node * 2 + 1];
    }

    int query(int node, int start, int end, int L, int R)
    {
        lazy_update(node, start, end);

        if (end < L || R < start)
        {
            return 0;
        }

        if (L <= start && end <= R)
        {
            return st[node];
        }

        int lsum = query(node * 2, start, (start + end) / 2, L, R);
        int rsum = query(node * 2 + 1, (start + end) / 2 + 1, end, L, R);
        return lsum + rsum;
    }

private:
    vector<int> arr;
    vector<int> st;
    vector<int> lazy;
};

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    SegmentTree st(arr);

    cout << st.query(1, 0, arr.size() - 1, 0, 3) << endl;

    st.update(1, 0, arr.size() - 1, 0, 3, 3);

    cout << st.query(1, 0, arr.size() - 1, 0, 3) << endl;

    return 0;
}
