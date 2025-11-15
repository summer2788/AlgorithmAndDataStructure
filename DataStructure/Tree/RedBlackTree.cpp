#include <iostream>

enum Color
{
    RED,
    BLACK
};

struct RBNode
{
    int key;
    Color color;
    RBNode *left;
    RBNode *right;
    RBNode *parent;

    RBNode(int value = 0, Color nodeColor = BLACK)
        : key(value), color(nodeColor), left(nullptr), right(nullptr), parent(nullptr)
    {
    }
};

class RedBlackTree
{
public:
    RedBlackTree()
    {
        TNULL = new RBNode();
        TNULL->color = BLACK;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    ~RedBlackTree()
    {
        clear(root);
        delete TNULL;
    }

    void Insert(int key)
    {
        RBNode *node = new RBNode(key, RED);
        node->parent = nullptr;
        node->left = TNULL;
        node->right = TNULL;

        RBNode *y = nullptr;
        RBNode *x = root;

        while (x != TNULL)
        {
            y = x;
            if (node->key < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr)
        {
            root = node;
        }
        else if (node->key < y->key)
        {
            y->left = node;
        }
        else
        {
            y->right = node;
        }

        if (node->parent == nullptr)
        {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr)
        {
            return;
        }

        insertFix(node);
    }

    void Delete(int key)
    {
        RBNode *node = root;
        RBNode *z = TNULL;
        while (node != TNULL)
        {
            if (node->key == key)
            {
                z = node;
            }

            if (node->key <= key)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }

        if (z == TNULL)
        {
            std::cout << "Key " << key << " not found in the tree." << std::endl;
            return;
        }

        RBNode *y = z;
        RBNode *x;
        Color yOriginalColor = y->color;

        if (z->left == TNULL)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == TNULL)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;

        if (yOriginalColor == BLACK)
        {
            deleteFix(x);
        }
    }

    bool Search(int key) const
    {
        RBNode *node = root;
        while (node != TNULL)
        {
            if (key == node->key)
            {
                return true;
            }
            else if (key < node->key)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return false;
    }

    void InOrder() const
    {
        inOrderHelper(root);
        std::cout << std::endl;
    }

private:
    RBNode *root;
    RBNode *TNULL;

    void clear(RBNode *node)
    {
        if (node == TNULL)
        {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void inOrderHelper(RBNode *node) const
    {
        if (node == TNULL)
        {
            return;
        }
        inOrderHelper(node->left);
        std::cout << node->key << " ";
        inOrderHelper(node->right);
    }

    void leftRotate(RBNode *x)
    {
        RBNode *y = x->right;
        x->right = y->left;
        if (y->left != TNULL)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(RBNode *x)
    {
        RBNode *y = x->left;
        x->left = y->right;
        if (y->right != TNULL)
        {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insertFix(RBNode *k)
    {
        RBNode *u;
        while (k->parent != nullptr && k->parent->color == RED)
        {
            if (k->parent == k->parent->parent->right)
            {
                u = k->parent->parent->left;
                if (u->color == RED)
                {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->left)
                    {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }
            else
            {
                u = k->parent->parent->right;
                if (u->color == RED)
                {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->right)
                    {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root)
            {
                break;
            }
        }
        root->color = BLACK;
    }

    void deleteFix(RBNode *x)
    {
        RBNode *s;
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                s = x->parent->right;
                if (s->color == RED)
                {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK)
                {
                    s->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (s->right->color == BLACK)
                    {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else
            {
                s = x->parent->left;
                if (s->color == RED)
                {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->left->color == BLACK)
                {
                    s->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (s->left->color == BLACK)
                    {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void transplant(RBNode *u, RBNode *v)
    {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    RBNode *minimum(RBNode *node) const
    {
        while (node->left != TNULL)
        {
            node = node->left;
        }
        return node;
    }
};

int main()
{
    RedBlackTree tree;

    tree.Insert(7);
    tree.Insert(3);
    tree.Insert(18);
    tree.Insert(10);
    tree.Insert(22);
    tree.Insert(8);
    tree.Insert(11);
    tree.Insert(26);

    std::cout << "In-order traversal: ";
    tree.InOrder();

    std::cout << "Contains 10? " << (tree.Search(10) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 5? " << (tree.Search(5) ? "Yes" : "No") << std::endl;

    tree.Delete(18);
    std::cout << "In-order after deleting 18: ";
    tree.InOrder();

    tree.Delete(7);
    std::cout << "In-order after deleting 7: ";
    tree.InOrder();

    return 0;
}
