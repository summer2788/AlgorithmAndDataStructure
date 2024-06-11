
class Node
{
private:
    int key;
    Node *left;
    Node *right;

public:
    Node(int k) : key{k}, left{nullptr}, right{nullptr} {}

    int GetKey() { return key; }
    Node *GetRight() { return right; }
    Node *GetLeft() { return left; }
    void SetKey(int k) { key = k; };
    void SetLeft(Node *l) { left = l; }
    void SetRight(Node *r) { right = r; }
};
