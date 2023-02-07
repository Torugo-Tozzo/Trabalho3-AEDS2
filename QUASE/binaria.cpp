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