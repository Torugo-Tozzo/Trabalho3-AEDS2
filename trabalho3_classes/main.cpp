/*----------------------------------------------------------------------------------------------*	
	Victor Hugo Tozzo Filho	- 2020.1.08.018
	Pedro Henrique Alves Barbosa - 2022.1.08.043
	Rafael Silva Fortuna- 2022.1.08.026	
--------------------------------------------------------------------------------------------------
    !!!!!!AVISO IMPORTANTE!!!!!!
    Nesta implementação de lista encadiada, 
    o primeiro slot (o primeiro nó da lista), ficará sempre vazio, contendo valores nulos
    ou seja a lista começa a partir do segundo nó
--------------------------------------------------------------------------------------------------*/
# include <iostream>
# include <string>
#include "lista.h"
#include "lista.cpp"
#include "binaria.cpp"
#include "avl.cpp"

using namespace std;


int main(int argc, char**argv){
    

    Cabecalho *cabeca = new Cabecalho;

    cabeca->inicio = new Veiculo;

    leArq(cabeca,"BD_veiculos_2.txt");

    ArvBinaria binaria;

    Veiculo* percorredor = cabeca->inicio->prox;
    while (percorredor != NULL)
    {
        binaria.inserir(percorredor);
        percorredor = percorredor->prox;
    }

    binaria.exibirArvore(binaria.raiz, 0);

    binaria.in_order(binaria.raiz);

   NoAVL *tree;

    tree = inserirNoAVL(tree, "dwada");
    tree = inserirNoAVL(tree, "uiwoa");
    tree = inserirNoAVL(tree, "dfefeisa");

    string modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa,preco;

    cout << "\n-----------------------------Menu---------------------------------\n" 
            " [1] - Buscar carro na arvore\n"
            " [2] - Add carro na arvore(arquivo)\n"
            " [3] - Excluir carro na arvore\n"
            " [1] - Buscar carro na arvore\n"<< endl;


    int escolha;

    switch (escolha)
    {
    case 1:
        /* code */
        break;
    
    default:
        break;
    }

   // Node<string>* rootAVL = nullptr;
   // Node<string>* rootBI = nullptr;
   // Node<string>* rootAVLFiltro = nullptr;
   // Node<string>* rootBIFiltro = nullptr;


/*
    AVL<int> avlTree;
    avlTree.root = avlTree.insert(avlTree.root, 100);
    avlTree.root = avlTree.insert(avlTree.root, 20);
    avlTree.root = avlTree.insert(avlTree.root, 380);
    avlTree.root = avlTree.insert(avlTree.root, 40);
    avlTree.root = avlTree.insert(avlTree.root, 50);
    avlTree.root = avlTree.insert(avlTree.root, 25);
    avlTree.inOrder(avlTree.root);
*/



        
            salva(cabeca);
   // } while (resp != 1);
    //encerra_lista(cabeca); encerra_lista(placas);encerra_lista(pilha); encerra_lista(fila);
    //freeTree(rootAVL);freeTree(rootBI);freeTree(rootBIFiltro);freeTree(rootAVLFiltro);
    return 0;
}