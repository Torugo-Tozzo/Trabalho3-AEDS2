#include <iostream>
#include <string>
#include "lista.h"
#include "no.h"

using namespace std;

class ArvAVL
{
public:
    No *raiz;

    ArvAVL()
    {
        raiz = NULL;
    }

    int height(No *no)
    {
        if (no == NULL)
            return 0;
        return no->h;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    No *rightRotate(No *y)
    {
        No *x = y->left;
        No *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->h = max(height(y->left), height(y->right)) + 1;
        x->h = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    No *leftRotate(No *x)
    {
        No *y = x->right;
        No *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->h = max(height(x->left), height(x->right)) + 1;
        y->h = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(No *no)
    {
        if (no == NULL)
            return 0;
        return height(no->left) - height(no->right);
    }

    No *insert(No *node, Veiculo *veiculo)
    {
        if (node == NULL)
            return new No(veiculo);

        if (veiculo->placa < node->veiculo->placa)
            node->left = insert(node->left, veiculo);
        else if (veiculo->placa > node->veiculo->placa)
            node->right = insert(node->right, veiculo);
        else
            return node;

        node->h = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && veiculo->placa < node->left->veiculo->placa)
            return rightRotate(node);

        if (balance < -1 && veiculo->placa > node->right->veiculo->placa)
            return leftRotate(node);

        if (balance > 1 && veiculo->placa > node->left->veiculo->placa)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && veiculo->placa < node->right->veiculo->placa)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    No *minValueNode(No *node)
    {
        No *current = node;

        while (current->left != NULL)
            current = current->left;

        return current;
    }
// arrumar
   No* deleteNode(No* root, string placa) {
    if (root == nullptr) {
        return root;
    }
    if (placa < root->veiculo->placa) {
        root->left = deleteNode(root->left, placa);
    } else if (placa > root->veiculo->placa) {
        root->right = deleteNode(root->right, placa);
    } else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            No* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            No* temp = minValueNode(root->right);
            root->veiculo->placa = temp->veiculo->placa;
            root->right = deleteNode(root->right, temp->veiculo->placa);
        }
    }
    if (root == nullptr) {
        return root;
    }
    root->h = max(height(root->left), height(root->right)) + 1;
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


    void buscar(No *no, string placa, int cond)
    {
        if (no == NULL)
        {
            cout << "not found" << endl;
            cond = 1;
        }
        else if (placa < no->veiculo->placa)
            return buscar(no->left, placa, cond);
        else if (placa > no->veiculo->placa)
            return buscar(no->right, placa, cond);
        else
            cond = 2;
        cout << "Veiculo encontrado" << endl;
    }

    void exibirArvore(No *root, int level)
    {
        if (root == nullptr)
        {
            return;
        }
        exibirArvore(root->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            std::cout << "        ";
        }
        std::cout << root->veiculo->placa << std::endl;
        exibirArvore(root->left, level + 1);
    }

    void in_order(No *no)
    {
        if (no != NULL)
        {
            in_order(no->left);
            cout << no->veiculo->placa << " ";
            in_order(no->right);
        }
    }

    void pre_order(No *no)
    {
        if (no != NULL)
        {
            cout << no->veiculo->placa << " ";
            pre_order(no->left);
            pre_order(no->right);
        }
    }

    void post_order(No *no)
    {
        if (no != NULL)
        {
            post_order(no->left);
            post_order(no->right);
            cout << no->veiculo->placa << " ";
        }
    }
};