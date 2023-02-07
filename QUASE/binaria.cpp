#include <iostream>
#include <string>
#include "lista.h"
#include "no.h"

using namespace std;

class ArvBinaria
{
public:
  No *raiz;

  ArvBinaria()
  {
    raiz = NULL;
  }

  void inserir(Veiculo *veiculo)
  {
    No *novoNo = new No(veiculo);
    if (raiz == NULL)
    {
      raiz = novoNo;
    }
    else
    {
      No *atual = raiz;
      No *anterior = NULL;
      while (atual != NULL)
      {
        anterior = atual;
        if (veiculo->placa < atual->veiculo->placa)
        {
          atual = atual->left;
        }
        else
        {
          atual = atual->right;
        }
      }
      if (veiculo->placa < anterior->veiculo->placa)
      {
        anterior->left = novoNo;
      }
      else
      {
        anterior->right = novoNo;
      }
    }
  }

  Veiculo *buscar(No *no, string placa)
  {
    if (no == NULL)
      return NULL;

    if (placa < no->veiculo->placa)
      return buscar(no->left, placa);
    else if (placa > no->veiculo->placa)
      return buscar(no->right, placa);
    else
      return no->veiculo;
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

  No *deleteNodeB(No *root, string placa)
  {
    // base case
    if (root == NULL)
      return root;

    // If the placa to be deleted is
    // smaller than the root's
    // placa, then it lies in left subtree
    if (placa < root->veiculo->placa)
      root->left = deleteNodeB(root->left, placa);

    // If the placa to be deleted is
    // greater than the root's
    // placa, then it lies in right subtree
    else if (placa > root->veiculo->placa)
      root->right = deleteNodeB(root->right, placa);

    // if placa is same as root's placa, then This is the node
    // to be deleted
    else
    {
      // node has no child
      if (root->left == NULL and root->right == NULL)
        return NULL;

      // node with only one child or no child
      else if (root->left == NULL)
      {
        No *temp = root->right;
        free(root);
        return temp;
      }
      else if (root->right == NULL)
      {
        No *temp = root->left;
        free(root);
        return temp;
      }

      // node with two children: Get the inorder successor
      // (smallest in the right subtree)
      No *temp = minValueNode(root->right);

      // Copy the inorder successor's content to this node
      root->veiculo = temp->veiculo;

      // Delete the inorder successor
      root->right = deleteNodeB(root->right, temp->veiculo->placa);
    }
    return root;
  }

  No *minValueNode(No *node)
    {
        No *current = node;

        while (current->left != NULL)
            current = current->left;

        return current;
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
};