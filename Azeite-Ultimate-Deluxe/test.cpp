#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;
    int height;
};

int maxS(int a, int b) {
    return (a > b) ? a : b;
}
//same
int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}
//same
int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* node) {
    Node* left = node->left;
    Node* leftRight = left->right;
    left->right = node;
    node->left = leftRight;
    node->height = maxS(height(node->left), height(node->right)) + 1;
    left->height = maxS(height(left->left), height(left->right)) + 1;
    return left;
}

Node* leftRotate(Node* node) {
    Node* right = node->right;
    Node* rightLeft = right->left;
    right->left = node;
    node->right = rightLeft;
    node->height = maxS(height(node->left), height(node->right)) + 1;
    right->height = maxS(height(right->left), height(right->right)) + 1;
    return right;
}


Node* insert(Node* node, string newName) {
    if (node == nullptr) {
        return new Node({newName, nullptr, nullptr, 1});
    }
    if (newName < node->name) {
        node->left = insert(node->left, newName);
    } else if (newName > node->name) {
        node->right = insert(node->right, newName);
    } else {
        // nome já existente
        return node;
    }

    node->height = 1 + maxS(height(node->left), height(node->right));
    int balance = getBalance(node);
    // verificar e fazer rotações para manter a propriedade AVL
    if (balance > 1 && newName < node->left->name) {
        return rightRotate(node);
    }
    if (balance < -1 && newName > node->right->name) {
        return leftRotate(node);
    }
    if (balance > 1 && newName > node->left->name) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && newName < node->right->name) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << node->name << " ";
        inOrder(node->right);
    }
}

void printTree(Node* node, int level) {
    if (node != nullptr) {
        printTree(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "        ";
        }
        std::cout << node->name << std::endl;
        printTree(node->left, level + 1);
    }
}


int main() {
    Node* root = nullptr;
    root = insert(root, "John123");
    root = insert(root, "Mike999");
    root = insert(root, "MAN7774");
    root = insert(root, "Sara");
    root = insert(root, "Emily");
    std::cout << "In-order traversal:" << std::endl;
    inOrder(root);
    cout << "--------------------" << endl;
    printTree(root,0);
    std::cout << std::endl;
    return 0;
}
