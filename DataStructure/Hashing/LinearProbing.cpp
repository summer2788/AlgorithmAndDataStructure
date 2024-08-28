// #include <iostream>
// #include <vector>
// #include <string>

// class LinearProbing
// {
// private:
//     struct HashNode
//     {
//         std::string key;
//         int value;
//         bool isDeleted;

//         HashNode() : key(""), value(0), isDeleted(false) {}
//         HashNode(std::string k, int v) : key(k), value(v), isDeleted(false) {}
//     };

//     std::vector<HashNode> table;
//     int capacity;
//     int size;

//     int hash(const std::string &key)
//     {
//         int hashValue = 0;
//         for (char ch : key)
//         {
//             hashValue = (hashValue * 31 + ch) % capacity;
//         }

//         return hashValue;
//     }

// public:
//     LinearProbing(int cap) : capacity(cap), size(0)
//     {
//         table.resize(capacity);
//     }

//     void insert(const std::string &key, int data)
//     {
//         if (size == capacity)
//         {
//             std::cout << "Hash table is full\n";
//             return;
//         }

//         int hashIndex = hash(key);

//         while (!table[hashIndex].key.empty() && !table[hashIndex].isDeleted && table[hashIndex].key != key)
//         {
//             hashIndex = (hashIndex + 1) % capacity;
//         }

//         table[hashIndex] = HashNode(key, data);
//         size++;
//     }

//     bool search(const std::string &key)
//     {
//         int hashIndex = hash(key);
//         int firstIndex = hashIndex;
//         while (!table[hashIndex].key.empty())
//         {
//             if (table[hashIndex].key == key && !table[hashIndex].isDeleted)
//             {
//                 return true;
//             }
//             hashIndex = (hashIndex + 1) % capacity;

//             if (hashIndex == firstIndex)
//                 break;
//         }
//         return false;
//     }

//     void remove(const std::string &key)
//     {
//         int hashIndex = hash(key);
//         int startIndex = hashIndex;

//         while (!table[hashIndex].key.empty())
//         {
//             if (table[hashIndex].key == key && !table[hashIndex].isDeleted)
//             {
//                 table[hashIndex].isDeleted = true;
//                 size--;
//                 return;
//             }

//             hashIndex = (hashIndex + 1) % capacity;

//             if (hashIndex == startIndex)
//             {
//                 std::cout << "nothing to delete! \n";
//                 break;
//             }
//         }
//     }

//     void display()
//     {
//         for (auto e : table)
//         {
//             if (e.key.empty())
//             {
//                 std::cout << "xx ";
//             }
//             else if (e.isDeleted)
//             {
//                 std::cout << "~~ ";
//             }
//             else
//             {
//                 std::cout << e.key << ":" << e.value << " ";
//             }
//         }
//         std::cout << std::endl;
//     }
// };

// int main()
// {
//     LinearProbing hm(7);

//     hm.insert("apple", 10);
//     hm.insert("banana", 20);
//     hm.insert("grape", 5);
//     hm.insert("cherry", 15);

//     hm.display();

//     if (hm.search("grape"))
//     {
//         std::cout << "Found grape with value " << "\n";
//     }
//     else
//     {
//         std::cout << "grape Not found\n";
//     }

//     hm.remove("apple");
//     hm.display();

//     if (hm.search("apple"))
//     {
//         std::cout << "Found apple with value " << "\n";
//     }
//     else
//     {
//         std::cout << "apple Not found\n";
//     }

//     return 0;
// }
