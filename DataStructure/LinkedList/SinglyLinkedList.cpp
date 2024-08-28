// #include <iostream>

// class SinglyLinkedList
// {
// private:
//     struct Node
//     {
//         int data;
//         Node *next;

//         Node(int val) : data(val), next(nullptr) {}
//     };
//     Node *head;

// public:
//     SinglyLinkedList() : head(nullptr) {}
//     ~SinglyLinkedList()
//     {
//         Node *current = head;
//         Node *next;
//         while (current != nullptr)
//         {
//             next = current->next;
//             delete current;
//             current = next;
//         }
//         head = nullptr;
//     }

//     bool IsEmpty() const
//     {
//         return head == nullptr;
//     }

//     int Size() const
//     {
//         int count{0};
//         Node *current = head;
//         while (current != nullptr)
//         {
//             count += 1;
//             current = current->next;
//         }

//         return count;
//     }

//     // method to add Node at the very first
//     void Add(int val)
//     {
//         Node *tempt = new Node(val);
//         if (head == nullptr)
//         {
//             head = tempt;
//         }
//         else
//         {
//             tempt->next = head;
//             head = tempt;
//         }
//     }

//     bool Search(int val)
//     {
//         Node *tempt = head;
//         while (tempt != nullptr)
//         {
//             if (tempt->data == val)
//             {
//                 return true;
//             }

//             tempt = tempt->next;
//         }
//         return false;
//     }

//     void Remove(int val)
//     {
//         Node *previous = nullptr;
//         Node *tempt = head;
//         while (tempt != nullptr)
//         {
//             if (tempt->data == val)
//             {
//                 if (previous == nullptr)
//                 {
//                     Node *toDelete = head;
//                     head = head->next;
//                     delete toDelete;
//                 }
//                 else
//                 {
//                     previous->next = tempt->next;
//                     delete tempt;
//                 }
//                 return;
//             }
//             else
//             {
//                 previous = tempt;
//                 tempt = tempt->next;
//             }
//         }
//     }

//     void display()
//     {
//         if (head == nullptr)
//         {
//             std::cout << "List is empty \n";
//             return;
//         }

//         Node *tempt = head;
//         while (tempt != nullptr)
//         {
//             std::cout << tempt->data << "-> ";
//             tempt = tempt->next;
//         }
//         std::cout << "NULL" << std::endl;
//     }
// };

// int main()
// {
//     SinglyLinkedList list;

//     list.Add(10);
//     list.Add(20);
//     list.Add(30);

//     std::cout << "List after insertion: ";
//     list.display();

//     list.Remove(20);

//     std::cout << "List after deletion: ";
//     list.display();

//     return 0;
// }
