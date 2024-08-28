// #include <iostream>

// class DoublyLinkedList
// {
// private:
//     struct Node
//     {
//         int data;
//         Node *prev;
//         Node *next;

//         // Constructor
//         Node(int val) : data(val), next(nullptr), prev(nullptr) {}
//     };
//     Node *head;
//     Node *tail;

// public:
//     DoublyLinkedList() : head(nullptr), tail(nullptr) {}
//     ~DoublyLinkedList()
//     {
//         Node *tempt = head;
//         if (head == nullptr)
//         {
//             return;
//         }
//         while (tempt != nullptr)
//         {
//             Node *next = tempt->next;
//             delete tempt;
//             tempt = next;
//         }
//     }

//     bool IsEmpty() const
//     {
//         return head == nullptr;
//     }

//     int Size() const
//     {
//         int cnt{0};
//         if (head == nullptr)
//         {
//             return cnt;
//         }
//         Node *tempt = head;
//         while (tempt != nullptr)
//         {
//             cnt++;
//             tempt = tempt->next;
//         }
//         return cnt;
//     }

//     bool Search(int val) const
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

//     void Add(int data)
//     {
//         Node *tempt = new Node(data);
//         if (head == nullptr)
//         {
//             head = tail = tempt;
//         }
//         else
//         {
//             tempt->next = head;
//             head->prev = tempt;
//             head = tempt;
//         }
//     }

//     void Append(int data)
//     {
//         Node *tempt = new Node(data);
//         if (head == nullptr)
//         {
//             head = tail = tempt;
//         }
//         else
//         {
//             tail->next = tempt;
//             tempt->prev = tail;
//             tail = tempt;
//         }
//     }

//     void InsertAfter(int item, int x)
//     {
//         Node *tempt = head;
//         while (tempt != nullptr && (tempt->data != item))
//         {
//             tempt = tempt->next;
//         }
//         if (tempt == nullptr)
//         {
//             std::cout << "Value " << x << "not found in the list. \n";
//             return;
//         }

//         Node *newNode = new Node(x);
//         newNode->next = tempt->next;
//         newNode->prev = tempt;
//         if (tempt->next == nullptr)
//         {
//             tail = newNode;
//         }
//         else
//         {
//             tempt->next->prev = newNode;
//         }
//         tempt->next = newNode;
//     }

//     void InsertBefore(int item, int x)
//     {
//         Node *tempt = head;
//         while (tempt != nullptr && (tempt->data != item))
//         {
//             tempt = tempt->next;
//         }
//         if (tempt == nullptr)
//         {
//             std::cout << "Value " << x << "not found in the list. \n";
//             return;
//         }

//         Node *newNode = new Node(x);
//         newNode->next = tempt;
//         newNode->prev = tempt->prev;
//         if (tempt->prev == nullptr)
//         {
//             head = newNode;
//         }
//         else
//         {
//             tempt->prev->next = newNode;
//         }
//         tempt->prev = newNode;
//     }

//     int PopFirst()
//     {
//         if (head == nullptr)
//         {
//             std::cout << "List is empty\n";
//             return -1;
//         }
//         Node *tempt = head;
//         int data = tempt->data;
//         head = tempt->next;
//         if (head == nullptr)
//         {
//             // empty list
//             tail = nullptr;
//         }
//         else
//         {
//             head->prev = nullptr;
//         }
//         delete tempt;
//         return data;
//     }

//     int PopLast()
//     {
//         if (head == nullptr)
//         {
//             std::cout << "List is empty\n";
//             return -1;
//         }
//         Node *tempt = tail;
//         int data = tempt->data;
//         tail = tempt->prev;
//         if (tail == nullptr)
//         {
//             head = nullptr;
//         }
//         else
//         {
//             tail->next = nullptr;
//         }
//         delete tempt;
//         return data;
//     }

//     void DeleteNode(int data)
//     {
//         Node *tempt = head;
//         while (tempt != nullptr && (tempt->data != data))
//         {
//             tempt->next = tempt;
//         }
//         if (head == nullptr)
//         {
//             std::cout << "Value " << data << " not found in the list \n";
//             return;
//         }

//         if (tempt->prev == nullptr)
//         {
//             head = tempt->next;
//         }
//         else
//         {
//             tempt->prev->next = tempt->next;
//         }

//         if (tempt->next == nullptr)
//         {
//             tail = tempt->prev;
//         }
//         else
//         {
//             tempt->next->prev = tempt->prev;
//         }
//         delete tempt;
//     }

//     void display() const
//     {
//         Node *tempt = head;
//         while (tempt != nullptr)
//         {
//             std::cout << tempt->data << "<->";
//             tempt = tempt->next;
//         }
//         std::cout << "NULL" << std::endl;
//     }
// };

// int main()
// {
//     DoublyLinkedList list;

//     list.Add(10);
//     list.Append(20);
//     list.Append(30);
//     list.InsertAfter(25, 20);
//     list.InsertBefore(5, 10);

//     std::cout << "List after insertions: ";
//     list.display();

//     std::cout << "List is empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
//     std::cout << "Size of the list: " << list.Size() << std::endl;
//     std::cout << "Searching for 25: " << (list.Search(25) ? "Found" : "Not Found") << std::endl;

//     std::cout << "First element popped: " << list.PopFirst() << std::endl;
//     std::cout << "Last element popped: " << list.PopLast() << std::endl;

//     list.DeleteNode(25);

//     std::cout << "List after deletions: ";
//     list.display();

//     return 0;
// }
