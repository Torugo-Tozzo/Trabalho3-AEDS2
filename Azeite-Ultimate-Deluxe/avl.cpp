#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include "avl.h"

using namespace std;

template <typename T>
bool search(Node<T>* node, T value) {
    if (node == nullptr) {
        return false;
    }
    if (node->value == value) {
        return true;
    }
    if (value < node->value) {
        return search(node->left, value);
    }
    return search(node->right, value);
}

template <typename T>
int height(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

template <typename T>
int getBalance(Node<T> *node) {
  if (node == nullptr)
    return 0;
  return height(node->left) - height(node->right);
}

template <typename T>
Node<T>* rightRotate(Node<T>* node) {
    Node<T>* left = node->left;
    Node<T>* leftRight = left->right;
    left->right = node;
    node->left = leftRight;
    node->height = max(height(node->left), height(node->right)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;
    return left;
}

template <typename T>
Node<T>* leftRotate(Node<T>* node) {
    Node<T>* right = node->right;
    Node<T>* rightLeft = right->left;
    right->left = node;
    node->right = rightLeft;
    node->height = max(height(node->left), height(node->right)) + 1;
    right->height = max(height(right->left), height(right->right)) + 1;
    return right;
}

template <typename T>
Node<T>* insert(Node<T>* node, T value){
  // Inserção normal de um nó em uma árvore binária de busca
  if (node == nullptr) {
    return new Node<T>(value);
  } else if (value < node->value)
    node->left = insert(node->left, value);
  else if (value > node->value)
    node->right = insert(node->right, value);
  else
    return node;

  // Atualização da altura do nó atual
  node->height = 1 + std::max(height(node->left), height(node->right));

  // Calcula o fator de balanceamento deste nó ancestral para verificar se a
  // árvore está desbalanceada
  int balance = getBalance(node);

  // Se a árvore estiver desbalanceada, precisamos realizar uma rotação
  if (balance > 1 && value < node->left->value) {
    // Rotação simples à direita
    return rightRotate(node);
  }
  if (balance < -1 && value > node->right->value) {
    // Rotação simples à esquerda
    return leftRotate(node);
  }
  if (balance > 1 && value > node->left->value) {
    // Rotação dupla à direita
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance < -1 && value < node->right->value) {
    // Rotação dupla à esquerda
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  // Se a árvore não estiver desbalanceada, retornamos o nó atual
  return node;
}

template <typename T>
void preOrder(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void inOrder(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    std::cout << node->value << " ";
    inOrder(node->right);
}

template <typename T>
void postOrder(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->value << " ";
}

template <typename T>
Node<T>* minValueNode(Node<T>* node) {
    Node<T>* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <typename T>
Node<T>* deleteNode(Node<T>* root, T value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node<T>* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node<T>* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    if (root == nullptr) {
        return root;
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

template <typename T>
void freeTree(Node<T>* root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

template <typename T>
void printTree(Node<T>* root, int level) {
    if (root == nullptr) {
        return;
    }
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        std::cout << "        ";
    }
    std::cout << root->value << std::endl;
    printTree(root->left, level + 1);
}