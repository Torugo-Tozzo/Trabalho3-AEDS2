#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

class No {
 public:
  Veiculo *veiculo;
  No *esq;
  No *dir;

  No(Veiculo *v) {
    veiculo = v;
    esq = NULL;
    dir = NULL;
  }
};

class ArvBinaria {
 public:
  No *raiz;

  ArvBinaria() {
    raiz = NULL;
  }

  void inserir(Veiculo *veiculo) {
    No *novoNo = new No(veiculo);
    if (raiz == NULL) {
      raiz = novoNo;
    } else {
      No *atual = raiz;
      No *anterior = NULL;
      while (atual != NULL) {
        anterior = atual;
        if (veiculo->placa < atual->veiculo->placa) {
          atual = atual->esq;
        } else {
          atual = atual->dir;
        }
      }
      if (veiculo->placa < anterior->veiculo->placa) {
        anterior->esq = novoNo;
      } else {
        anterior->dir = novoNo;
      }
    }
  }

  void in_order(No *no) {
    if (no != NULL) {
      in_order(no->esq);
      cout << no->veiculo->placa << " ";
      in_order(no->dir);
    }
  }

  void pre_order(No *no) {
    if (no != NULL) {
      cout << no->veiculo->placa << " ";
      pre_order(no->esq);
      pre_order(no->dir);
    }
  }

  void post_order(No *no) {
    if (no != NULL) {
      post_order(no->esq);
      post_order(no->dir);
      cout << no->veiculo->placa << " ";
    }
  }
  
void exibirArvore(No* root, int level) {
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