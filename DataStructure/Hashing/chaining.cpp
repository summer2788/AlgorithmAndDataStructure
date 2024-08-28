// #include <iostream>
// #include <vector>

// class Node
// {
// public:
//     int key;
//     int data;
//     Node *next;

//     Node(int key, int data, Node *next = nullptr)
//     {
//         this->key = key;
//         this->data = data;
//         this->next = next;
//     }
// };

// class HashTable
// {
// private:
//     std::vector<Node *> table;
//     int size;

//     int hash(int key)
//     {
//         return key % size;
//     }

// public:
//     HashTable(int size)
//     {
//         this->size = size;
//         table.resize(size, nullptr);
//     }

//     void Insert(int key, int data)
//     {
//         int hashIndex = hash(key);
//         Node *tempt = table[hashIndex];
//         while (tempt != nullptr)
//         {
//             if (tempt->key == key)
//             {
//                 tempt->data = data;
//                 return;
//             }

//             tempt = tempt->next;
//         }
//         table[hashIndex] = new Node(key, data, table[hashIndex]);
//     }

//     bool Search(int key)
//     {
//         int hashIndex = hash(key);
//         Node *tempt = table[hashIndex];
//         while (tempt != nullptr)
//         {
//             if (tempt->key == key)
//                 return true;

//             tempt = tempt->next;
//         }
//         return false;
//     }

//     void Remove(int key)
//     {
//         int hashIndex = hash(key);
//         Node *tempt = table[hashIndex];
//         Node *previous = nullptr;
//         while (tempt != nullptr)
//         {
//             if (tempt->key == key)
//             {
//                 if (!previous)
//                 {
//                     table[hashIndex] = tempt->next;
//                 }
//                 else
//                 {
//                     previous->next = tempt->next;
//                 }
//                 return;
//             }
//             previous = tempt;
//             tempt = tempt->next;
//         }
//     }

//     void display()
//     {
//         for (int i = 0; i < size; ++i)
//         {
//             std::cout << "Bucket: " << i << ": ";
//             Node *tempt = table[i];
//             while (tempt)
//             {
//                 std::cout << "(" << tempt->key << ", " << tempt->data << "-> ";
//                 tempt = tempt->next;
//             }
//             std::cout << "NULL" << std::endl;
//         }
//     }

//     ~HashTable()
//     {
//         for (int i = 0; i < size; ++i)
//         {
//             Node *tempt = table[i];
//             while (tempt)
//             {
//                 Node *toDelete = tempt;
//                 tempt = tempt->next;
//                 delete toDelete;
//             }
//         }
//     }
// };

// int main()
// {
//     // Create a hash table of size 10
//     HashTable hashTable(10);

//     // Insert some key-data pairs
//     hashTable.Insert(15, 100);
//     hashTable.Insert(11, 200);
//     hashTable.Insert(27, 300);
//     hashTable.Insert(8, 400);
//     hashTable.Insert(12, 500);

//     // Display the hash table
//     hashTable.display();

//     // Search for a key
//     std::cout << "Search for 27: " << (hashTable.Search(27) ? "Found" : "Not Found") << std::endl;

//     // Remove a key
//     hashTable.Remove(27);

//     // Display the hash table after removal
//     hashTable.display();

//     return 0;
// }
