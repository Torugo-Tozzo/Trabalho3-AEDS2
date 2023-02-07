#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

class NoAVL
{
public:
    Veiculo *veiculo;
    NoAVL *esq;
    NoAVL *dir;
    int altura;

    NoAVL(Veiculo *v)
    {
        veiculo = v;
        esq = NULL;
        dir = NULL;
        altura = 0;
    }
};

class ArvAVL
{
public:
    NoAVL *raiz;

    ArvAVL()
    {
        raiz = NULL;
    }

    int altura(NoAVL *no)
    {
        if (no == NULL)
            return -1;
        return 1 + max(altura(no->esq), altura(no->dir));
    }

    NoAVL *rotacaoEsquerda(NoAVL *node)
    {
        NoAVL *u = node->dir;
        node->dir = u->esq;
        u->esq = node;
        node->altura = max(altura(node->esq), altura(node->dir)) + 1;
        u->altura = max(altura(u->esq), altura(u->dir)) + 1;
        return u;
    }

    NoAVL *rotacaoDireita(NoAVL *node)
    {
        NoAVL *u = node->esq;
        node->esq = u->dir;
        u->dir = node;
        node->altura = max(altura(node->esq), altura(node->dir)) + 1;
        u->altura = max(altura(u->esq), altura(u->dir)) + 1;
        return u;
    }

    NoAVL *rotacaoEsquerdaDireita(NoAVL *node)
    {
        node->esq = rotacaoEsquerda(node->esq);
        return rotacaoDireita(node);
    }

    NoAVL *rotacaoDireitaEsquerda(NoAVL *node)
    {
        node->dir = rotacaoDireita(node->dir);
        return rotacaoEsquerda(node);
    }

    NoAVL *inserir(NoAVL *node, Veiculo *veiculo)
    {
        if (node == NULL)
        {
            return new NoAVL(veiculo);
        }
        if (veiculo->placa < node->veiculo->placa)
        {
            node->esq = inserir(node->esq, veiculo);
            if (altura(node->esq) - altura(node->dir) == 2)
            {
                if (veiculo->placa < node->esq->veiculo->placa)
                {
                    node = rotacaoDireita(node);
                }
                else
                {
                    node = rotacaoEsquerdaDireita(node);
                }
            }
        }
        else if (veiculo->placa > node->veiculo->placa)
        {
            node->dir = inserir(node->dir, veiculo);
            int balanceamento = getBalanceamento(node);
            if (balanceamento > 1 && veiculo->placa > node->esq->veiculo->placa)
            {
                return rotacaoDireita(node);
            }

            if (balanceamento < -1 && veiculo->placa < node->dir->veiculo->placa)
            {
                return rotacaoEsquerda(node);
            }

            if (balanceamento > 1 && veiculo->placa < node->esq->veiculo->placa)
            {
                node->esq = rotacaoEsquerda(node->esq);
                return rotacaoDireita(node);
            }

            if (balanceamento < -1 && veiculo->placa > node->dir->veiculo->placa)
            {
                node->dir = rotacaoDireita(node->dir);
                return rotacaoEsquerda(node);
            }

            return node;
        }
    }

    int getAltura(NoAVL *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return node->altura;
        }
    }

    int getBalanceamento(NoAVL *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return getAltura(node->esq) - getAltura(node->dir);
        }
    }

    void in_order(NoAVL *no) {
    if (no != NULL) {
      in_order(no->esq);
      cout << no->veiculo->placa << " ";
      in_order(no->dir);
    }
  }

  void pre_order(NoAVL *no) {
    if (no != NULL) {
      cout << no->veiculo->placa << " ";
      pre_order(no->esq);
      pre_order(no->dir);
    }
  }

  void post_order(NoAVL *no) {
    if (no != NULL) {
      post_order(no->esq);
      post_order(no->dir);
      cout << no->veiculo->placa << " ";
    }
  }
  
void exibirArvore(NoAVL* root, int level) {
    if (root == nullptr) {
        return;
    }
    exibirArvore(root->dir, level + 1);
    for (int i = 0; i < level; i++) {
        std::cout << "        ";
    }
    std::cout << root->veiculo->placa << std::endl;
    exibirArvore(root->esq, level + 1);
}
};