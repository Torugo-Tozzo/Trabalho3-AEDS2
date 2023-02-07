#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

class NoAVL
{
public:
    string valor;
    int altura;
    NoAVL *esq;
    NoAVL *dir;

    NoAVL::NoAVL()
    {
        esq = NULL;
        dir = NULL;
        altura = 1;
        valor = nullptr;
    }

    NoAVL(int valor)
    {
        this->valor = valor;
        this->altura = 1;
        this->esq = NULL;
        this->dir = NULL;
    }
};
NoAVL *novoNoAVL(string chave)
{
    NoAVL *novoNo = new NoAVL();
    novoNo->valor = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->altura = 1;
    return novoNo;
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

int getFatorBalanco(NoAVL *node)
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

void atualizaAltura(NoAVL *node)
{
    node->altura = max(getAltura(node->esq), getAltura(node->dir)) + 1;
}

NoAVL *rotacaoDireita(NoAVL *node)
{
    NoAVL *temp = node->esq;
    node->esq = temp->dir;
    temp->dir = node;
    atualizaAltura(node);
    atualizaAltura(temp);
    return temp;
}

NoAVL *rotacaoEsquerda(NoAVL *node)
{
    NoAVL *temp = node->dir;
    node->dir = temp->esq;
    temp->esq = node;
    atualizaAltura(node);
    atualizaAltura(temp);
    return temp;
}

NoAVL *rotacaoDuplaDireita(NoAVL *node)
{
    node->esq = rotacaoEsquerda(node->esq);
    return rotacaoDireita(node);
}

NoAVL *rotacaoDuplaEsquerda(NoAVL *node)
{
    node->dir = rotacaoDireita(node->dir);
    return rotacaoEsquerda(node);
}

NoAVL *inserirNoAVL(NoAVL *node, string valor)
{
    if (node == NULL)
    {
        return novoNoAVL(valor);
    }
    if (valor < node->valor)
    {
        node->esq = inserirNoAVL(node->esq, valor);
    }
    else if (valor > node->valor)
    {
        node->dir = inserirNoAVL(node->dir, valor);
    }
    else
    {
        return node;
    }

    node->altura = 1 + max(getAltura(node->esq), getAltura(node->dir));

    int fatorBalanceamento = getFatorBalanco(node);

    if (fatorBalanceamento > 1 && valor < node->esq->valor)
    {
        return rotacaoDireita(node);
    }
    if (fatorBalanceamento < -1 && valor > node->dir->valor)
    {
        return rotacaoEsquerda(node);
    }
    if (fatorBalanceamento > 1 && valor > node->esq->valor)
    {
        node->esq = rotacaoEsquerda(node->esq);
        return rotacaoDireita(node);
    }
    if (fatorBalanceamento < -1 && valor < node->dir->valor)
    {
        node->dir = rotacaoDireita(node->dir);
        return rotacaoEsquerda(node);
    }

    return node;
}
