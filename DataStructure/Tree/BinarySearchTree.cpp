// #include "Node.h"
// #include <iostream>
// /*
// Binary Search Tree satisfy two property
// 1. All key of nodes have distinctive value
// 2. the key value of specific node N is bigger than the ones which are in the left sides and lesser that the righ sides
// */

// class BinarySearchTree
// {
// private:
//     Node *root;

//     Node *search(Node *node, int key)
//     {
//         if (node == nullptr || node->GetKey() == key)
//             return node;
//         else if (key < node->GetKey())
//             return search(node->GetLeft(), key);
//         else
//             return search(node->GetRight(), key);
//     }

//     Node *insert(Node *node, int key)
//     {
//         if (node == nullptr)
//             return new Node(key);
//         if (node->GetKey() > key)
//             node->SetLeft(insert(node->GetLeft(), key));
//         else if (node->GetKey() < key)
//             node->SetRight(insert(node->GetRight(), key));
//         return node;
//     }

//     Node *findMin(Node *node)
//     {
//         if (node->GetLeft() == nullptr)
//             return node;
//         return findMin(node->GetLeft());
//     }

//     Node *deleteMin(Node *node)
//     {
//         if (node->GetLeft() == nullptr)
//             return node->GetRight();
//         node->SetLeft(deleteMin(node->GetLeft()));
//         return node;
//     }

//     Node *deleteNode(Node *node, int key)
//     {
//         if (node == nullptr)
//             return nullptr;
//         if (key < node->GetKey())
//             node->SetLeft(deleteNode(node->GetLeft(), key));
//         else if (key > node->GetKey())
//             node->SetRight(deleteNode(node->GetRight(), key));
//         else
//         {
//             if (node->GetLeft() == nullptr)
//                 return node->GetRight();
//             else if (node->GetRight() == nullptr)
//                 return node->GetLeft();
//             Node *temp = node;
//             node = findMin(node->GetRight());
//             node->SetLeft(temp->GetLeft());
//             node->SetRight(deleteMin(temp->GetRight()));
//         }
//         return node;
//     }

// public:
//     BinarySearchTree() : root{nullptr}
//     {
//     }

//     bool Search(int key)
//     {
//         return search(root, key) != nullptr;
//     }

//     void Insert(int key)
//     {
//         root = insert(root, key);
//     }

//     Node *FindMin()
//     {
//         if (root == nullptr)
//             return nullptr;
//         return findMin(root);
//     }

//     void DeleteMin()
//     {
//         if (root == nullptr)
//             std::cout << "Tree is empty." << " ";
//         root = deleteMin(root);
//     }

//     void Delete(int key)
//     {
//         root = deleteNode(root, key);
//     }
// };

// // Example usage
// int main()
// {
//     BinarySearchTree bst;
//     bst.Insert(5);
//     bst.Insert(3);
//     bst.Insert(7);
//     bst.Insert(2);
//     bst.Insert(4);
//     bst.Insert(6);
//     bst.Insert(8);

//     std::cout << "Min: " << bst.FindMin() << " "; // Should print 2

//     bst.DeleteMin();
//     std::cout << "Min after deleting min: " << bst.FindMin() << " "; // Should print 3

//     std::cout << "Search 4: " << (bst.Search(4) ? "Found" : "Not Found") << " "; // Should print "Found"
//     bst.Delete(4);
//     std::cout << "Search 4 after deletion: " << (bst.Search(4) ? "Found" : "Not Found") << " "; // Should print "Not Found"

//     return 0;
// }
