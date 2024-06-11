// #include <iostream>

// class CircularLinkedList
// {
// private:
//     struct Node
//     {
//         int data;
//         Node *next;

//         Node(int val) : data{val}, next{nullptr} {}
//     };
//     Node *head; // indicate the very end node

// public:
//     CircularLinkedList() : head{nullptr} {}
//     ~CircularLinkedList()
//     {
//         if (head == nullptr)
//         {
//             return;
//         }

//         Node *current = head->next;
//         head->next = nullptr; // break the cycle
//         while (current != nullptr)
//         {
//             Node *next = current->next;
//             delete current;
//             current = next;
//         }
//     }

//     bool IsEmpty()
//     {
//         return head == nullptr;
//     }

//     // add item at the very first
//     void Add(int val)
//     {
//         Node *tempt = new Node(val);
//         if (head == nullptr)
//         {
//             head = tempt;
//             tempt->next = head;
//             return;
//         }
//         tempt->next = head->next;
//         head->next = tempt;
//     }

//     // add item at the very end
//     void Insert(int val)
//     {
//         Node *tempt = new Node(val);
//         if (head == nullptr)
//         {
//             head = tempt;
//             tempt->next = head;
//             return;
//         }
//         tempt->next = head->next;
//         head->next = tempt;
//         head = tempt;
//     }

//     bool Search(int val) const
//     {
//         if (head == nullptr)
//         {
//             return false;
//         }

//         Node *current = head->next;
//         do
//         {
//             if (current->data == val)
//             {
//                 return true;
//             }
//             current = current->next;
//         } while (
//             current != head->next);

//         return false;
//     }

//     void Remove(int val)
//     {
//         if (head == nullptr)
//         {
//             return;
//         }
//         Node *current = head->next;
//         Node *previous = head;

//         do
//         {
//             if (current->data == val)
//             {
//                 if (current == head->next) //  Node to delete is first node
//                 {
//                     if (head == head->next) // Only one node
//                     {
//                         delete current;
//                         head = nullptr;
//                     }
//                     else
//                     {
//                         head->next = current->next;
//                         delete current;
//                     }
//                 }
//                 else if (current == head) // Node to delete is last node
//                 {
//                     head = previous;
//                     previous->next = current->next;
//                     delete current;
//                 }
//                 else
//                 { // Node to delete is in the middle
//                     previous->next = current->next;
//                     delete current;
//                 }
//                 return;
//             }
//             previous = current;
//             current = current->next;
//         } while (current != head->next);

//         std::cout << "Value not found in the list\n";
//     }

//     void Display() const
//     {
//         if (head == nullptr)
//         {
//             std::cout << "List is empty " << std::endl;
//             return;
//         }
//         Node *current = head->next;
//         do
//         {
//             std::cout << current->data << " -> ";
//             current = current->next;
//         } while (current != head->next);

//         std::cout << "(head)" << std::endl;
//     }
// };

// int main()
// {
//     CircularLinkedList list;
//     list.Insert(10);
//     list.Insert(20);
//     list.Insert(30);

//     std::cout << "List after insertion: ";
//     list.Display();

//     std::cout << "List is empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
//     std::cout << "Searching for 20: " << (list.Search(20) ? "Found" : "Not Found") << std::endl;

//     list.Remove(20);

//     std::cout << "List after deletion: ";
//     list.Display();

//     std::cout << "List is empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
//     std::cout << "Searching for 20: " << (list.Search(20) ? "Found" : "Not Found") << std::endl;
//     return 0;
// }
