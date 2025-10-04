#include <bits/stdc++.h>
using namespace std;

// ---------- Binary Tree Node ----------
struct Node {
  int val;
  Node *left;
  Node *right;
  explicit Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// ---------- DFS Traversals (Recursive) ----------
void preorder(Node *root, vector<int> &out) {
  if (!root)
    return;
  out.push_back(root->val);   // Root
  preorder(root->left, out);  // Left
  preorder(root->right, out); // Right
}

void inorder(Node *root, vector<int> &out) {
  if (!root)
    return;
  inorder(root->left, out);  // Left
  out.push_back(root->val);  // Root
  inorder(root->right, out); // Right
}

void postorder(Node *root, vector<int> &out) {
  if (!root)
    return;
  postorder(root->left, out);  // Left
  postorder(root->right, out); // Right
  out.push_back(root->val);    // Root
}

// ---------- BFS Traversal (Level-Order) ----------
vector<int> levelOrder(Node *root) {
  vector<int> out;
  if (!root)
    return out;
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *cur = q.front();
    q.pop();
    out.push_back(cur->val);
    if (cur->left)
      q.push(cur->left);
    if (cur->right)
      q.push(cur->right);
  }
  return out;
}

// ---------- Utility: print a vector ----------
void printVec(const string &label, const vector<int> &v) {
  cout << label << ": ";
  for (size_t i = 0; i < v.size(); ++i) {
    if (i)
      cout << ' ';
    cout << v[i];
  }
  cout << '\n';
}

// ---------- Demo ----------
int main() {
  /*
          1
         / \
        2   3
       / \   \
      4   5   6
  */
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);

  vector<int> pre, in, post;
  preorder(root, pre);
  inorder(root, in);
  postorder(root, post);
  vector<int> level = levelOrder(root);

  printVec("Preorder   (DFS)", pre);   // 1 2 4 5 3 6
  printVec("Inorder    (DFS)", in);    // 4 2 5 1 3 6
  printVec("Postorder  (DFS)", post);  // 4 5 2 6 3 1
  printVec("Level-order(BFS)", level); // 1 2 3 4 5 6

  // Cleanup (recursive delete)
  function<void(Node *)> destroy = [&](Node *n) {
    if (!n)
      return;
    destroy(n->left);
    destroy(n->right);
    delete n;
  };
  destroy(root);
  return 0;
}
