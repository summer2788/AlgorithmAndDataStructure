// trie_integrated.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  TrieNode *children[26];
  bool isEnd; // unified flag name (was isLeaf / isEndOfWord in your snippets)

  TrieNode() : isEnd(false) {
    for (int i = 0; i < 26; ++i)
      children[i] = nullptr;
  }
};

// ---------- helpers ----------
static inline int idx(char c) {
  // assumes lowercase 'a'..'z'
  return c - 'a';
}

bool isEmpty(TrieNode *node) {
  for (int i = 0; i < 26; ++i)
    if (node->children[i] != nullptr)
      return false;
  return true;
}

// ---------- core ops ----------
void insert(TrieNode *root, const string &key) {
  TrieNode *curr = root;
  for (char c : key) {
    int i = idx(c);
    if (i < 0 || i >= 26)
      return; // skip invalid chars (keep it simple)
    if (!curr->children[i])
      curr->children[i] = new TrieNode();
    curr = curr->children[i];
  }
  curr->isEnd = true;
}

bool search(TrieNode *root, const string &key) {
  if (!root)
    return false;
  TrieNode *curr = root;
  for (char c : key) {
    int i = idx(c);
    if (i < 0 || i >= 26)
      return false;
    if (!curr->children[i])
      return false;
    curr = curr->children[i];
  }
  return curr->isEnd;
}

bool isPrefix(TrieNode *root, const string &prefix) {
  if (!root)
    return false;
  TrieNode *curr = root;
  for (char c : prefix) {
    int i = idx(c);
    if (i < 0 || i >= 26)
      return false;
    if (!curr->children[i])
      return false;
    curr = curr->children[i];
  }
  return true;
}

// Recursive delete (remove one word). Returns possibly-updated subtree root.
TrieNode *removeWord(TrieNode *root, const string &key, int depth = 0) {
  if (!root)
    return nullptr;

  if (depth == (int)key.size()) {
    // Unmark this node as end of a word
    if (root->isEnd)
      root->isEnd = false;

    // If it has no children, free this node
    if (isEmpty(root)) {
      delete root;
      root = nullptr;
    }
    return root;
  }

  int i = idx(key[depth]);
  if (i < 0 || i >= 26)
    return root; // ignore invalid char

  root->children[i] = removeWord(root->children[i], key, depth + 1);

  // If this node has no children and isn't the end of another word, delete it
  if (isEmpty(root) && !root->isEnd) {
    delete root;
    root = nullptr;
  }
  return root;
}

// Optional: free entire trie
void freeTrie(TrieNode *root) {
  if (!root)
    return;
  for (int i = 0; i < 26; ++i)
    freeTrie(root->children[i]);
  delete root;
}

// ---------- demo ----------
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  TrieNode *root = new TrieNode();

  // Build the trie
  vector<string> words = {"and", "ant", "do", "dad", "bat", "bath"};
  for (const auto &s : words)
    insert(root, s);

  // Search words
  vector<string> searchKeys = {"do", "gee", "bat", "bath", "ba"};
  for (const auto &s : searchKeys) {
    cout << "search(\"" << s << "\"): " << (search(root, s) ? "true" : "false")
         << "\n";
  }
  cout << "\n";

  // Check prefixes
  vector<string> prefixKeys = {"ge", "ba", "do", "de", "an"};
  for (const auto &s : prefixKeys) {
    cout << "isPrefix(\"" << s
         << "\"): " << (isPrefix(root, s) ? "true" : "false") << "\n";
  }
  cout << "\n";

  // Deletions
  cout << "Removing \"bat\"...\n";
  root = removeWord(root, "bat");
  cout << "search(\"bat\"):  " << (search(root, "bat") ? "true" : "false")
       << "\n";
  cout << "isPrefix(\"bat\"): " << (isPrefix(root, "bat") ? "true" : "false")
       << "  (\"bath\" still there)\n\n";

  cout << "Removing \"bath\"...\n";
  root = removeWord(root, "bath");
  cout << "search(\"bath\"): " << (search(root, "bath") ? "true" : "false")
       << "\n";
  cout << "isPrefix(\"ba\"): " << (isPrefix(root, "ba") ? "true" : "false")
       << "\n\n";

  cout << "Removing non-existent \"banana\"...\n";
  root = removeWord(root, "banana"); // safe no-op
  cout << "isPrefix(\"ba\"): " << (isPrefix(root, "ba") ? "true" : "false")
       << "\n";

  // Cleanup (comment out if you want OS to reclaim memory after process ends)
  freeTrie(root);
  root = nullptr;

  return 0;
}
