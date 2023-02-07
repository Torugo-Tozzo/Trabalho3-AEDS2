#pragma
#include <string>

using namespace std;

// Nós da arvore
template <typename T>
struct Node {
  T value;
  int height; // altura nó
  Node *left;
  Node *right;

   Node(T value) : value(value), height(1), left(nullptr), right(nullptr) {}
};

template <typename T>
Node<T>* insert(Node<T>* node, T value);