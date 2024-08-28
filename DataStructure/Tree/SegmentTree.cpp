#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
public:
    SegmentTree(const vector<int> &initialA) : arr(initialA), st(arr.size() * 4)
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
            build(2 * node, l, (l + r) / 2);
            build(2 * node + 1, (l + r) / 2 + 1, r);
            st[node] = st[2 * node] + st[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int left, int right) // subsum query
    {
        if (end < left || right < start)
        {
            return 0;
        }

        if (left <= start && end <= right)
        {
            return st[node];
        }

        int lsum = query(node * 2, start, (start + end) / 2, left, right);
        int rsum = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        return lsum + rsum;
    }

    void update(int node, int start, int end, int index, int val)
    {
        if (index < start || end < index)
        {
            return;
        }

        if (start == end)
        {
            st[node] = val;
            return;
        }

        update(2 * node, start, (start + end) / 2, index, val);
        update(2 * node + 1, (start + end) / 2 + 1, end, index, val);
        st[node] = st[node * 2] + st[node * 2 + 1];
    }

private:
    vector<int> arr;
    vector<int> st;
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree st(arr);

    cout << st.query(1, 0, arr.size() - 1, 0, 3) << endl;
    st.update(1, 0, arr.size() - 1, 0, 10);
    cout << st.query(1, 0, arr.size() - 1, 0, 3) << endl;

    return 0;
}
