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
# include "avl.cpp"
#include "lista.cpp"

using namespace std;

//Inserção sem balanceamento
template <typename T> //paradinha muito bacana que permite int e string
Node<T>* insertBI(Node<T>* node, T value) { // logo os parametros dessa função podem alternar entre placas ou preços com ftoi() ou numeros
    if (node == nullptr) {
        return new Node<T>(value);
    }
    if (value < node->value) {
        node->left = insertBI(node->left, value);
    } else if (value > node->value) {
        node->right = insertBI(node->right, value);
    } else {
        // ja existe
        return node;
    }
    return node;
}

template <typename T>
Node<T>* deleteNodeB(Node<T>* root, T value)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the value to be deleted is
    // smaller than the root's
    // value, then it lies in left subtree
    if (value < root->value)
        root->left = deleteNodeB(root->left, value);
 
    // If the value to be deleted is
    // greater than the root's
    // value, then it lies in right subtree
    else if (value > root->value)
        root->right = deleteNodeB(root->right, value);
 
    // if value is same as root's value, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left == NULL and root->right == NULL)
            return NULL;
 
        // node with only one child or no child
        else if (root->left == NULL) {
            Node<T>* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node<T>* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node<T>* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->value = temp->value;
 
        // Delete the inorder successor
        root->right = deleteNodeB(root->right, temp->value);
    }
    return root;
}


int main(int argc, char**argv){
    

    Cabecalho *cabeca = new Cabecalho;
    Cabecalho *placas = new Cabecalho;
    Cabecalho *pilha  = new Cabecalho;
    Cabecalho *fila   = new Cabecalho;
    pilha->tam = 0;
    fila->tam = 0;

    
    cabeca->inicio = new Veiculo;
    
    Cabecalho *guarda = new Cabecalho;
    guarda->inicio = new Veiculo;

    leArq(cabeca,"BD_veiculos_2.txt");

    int resp, caso, caso1;
    string modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa,ex;
    float preco;

    Node<string>* rootAVL = nullptr;
    Node<string>* rootBI = nullptr;
    Node<string>* rootAVLFiltro = nullptr;
    Node<string>* rootBIFiltro = nullptr;
    Node<float>* rootAVLPreco = nullptr;


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



    Veiculo *percorredor;

    /* Fazendo inserção de todos os veiculos nas arvore AVL e BINARIA */
    percorredor = cabeca->inicio->prox;
        while (percorredor != NULL)
        {
            rootAVL = insert(rootAVL, percorredor->placa);
            rootBI = insertBI(rootBI, percorredor->placa);  
            percorredor = percorredor->prox;
        }
    
    do{
        cout << "\n Digite : (1) para buscar(excluir)\n Digite : (2) para adicionar\n Digite : (3) para relatórios da lista principal\n Digite : (4) para empilhar carros (hidraulico add, eletrico rm)\n Digite : (5) para enfileirar carros (automatico add, manual rm)\n Digite : (6) para arvores\n Digite : (7) para sair\n";
        cin >> caso;
        switch (caso){
        case 1:
            cout << "Digite a placa a ser buscada\n";
            cin >> placa;
            busca(cabeca,placa);
            cout << "Deseja excluir?\n Sim ! exclui essa lata velha - digite(1).\n Não, nuca, não exlua, pf! - digite(2)\n";
            cin >> caso1;
            if(caso1 == 1){
                exclui(cabeca,placa);
                deleteNode(rootAVL,placa);
                deleteNodeB(rootBI,placa);
            }
            break;
        case 2:
            int umoudois;
            cout << "Inserir Manualmente - (1)\n ou \nInserir Veiculo de um arquivo - (2)" << endl;
            cin >> umoudois;
            if (umoudois == 1)
            { 
            cout << "Digite modelo\n";
                     cin >> modelo;
            cout << "Digite marca\n";
                     cin >> marca;
            cout << "Digite versao\n";
                     cin >> versao;
            cout << "Digite ano\n";
                     cin >> ano;
            cout << "Digite kilometragem\n";
                     cin >> kilometragem;
            cout << "Digite motor\n";
                     cin >> motor;
            cout << "Digite consumo\n";
                     cin >> consumo;
            cout << "Digite moua\n";
                     cin >> moua;
            cout << "Digite direcao\n";
                     cin >> direcao;
            cout << "Digite cor\n";
                     cin >> cor;
            cout << "Digite portas\n";
                     cin >> portas;
            cout << "Digite placa\n";
                     cin >> placa;
            cout << "Digite preco (em float, ex: 12345.00)\n";
                     cin >> preco;
            cout << "adicionando......\n";
            insere_fim(cabeca,modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa,preco);
            insert(rootAVL,placa);
            insertBI(rootBI,placa);
                     } else
                     {
                        string arq_name;
                        cout << "Digite o nome do arquivo \nExemplo: arquivo_exemplo.txt" << endl;
                        cin >> arq_name;
                        //função lê arquivo 
                        leArq(guarda, arq_name);
                        cout << "Veiculos a serem incluidos:" << endl;
                        imprime(guarda);
                        //função insere
                        addLista(cabeca,guarda);
                        percorredor = cabeca->inicio->prox;
                        while (percorredor != NULL)
                        {
                            rootAVL = insert(rootAVL, percorredor->placa);
                            rootBI = insertBI(rootBI, percorredor->placa);  
                            percorredor = percorredor->prox;
                        }
                        
                        imprime(cabeca);
                     }
        break;
        case 3:
            int c3;
            cout << "Mostrar os veiculos = digite (1)\nOrdenar os veiculos pelas placas = digite (2)\n";
            cin >> c3;
            if(c3 == 1){
                imprime(cabeca);
                }else {
                ordena_placa(cabeca,placas);
                imprime_placa(placas);}
        break;
        case 4:
        cria_pilha(cabeca,pilha);
        break;
        case 5:
        cria_fila(cabeca,fila);
        break;
        case 6:
            int arv1ou2;
            cout << "  Digite : (0) para buscar na arvore\n  Digite : (1) para mostrar Arvore AVL de todos os veiculos \n  Digite : (2) para mostrar Arvore BINARIA de todos os veiculos \n  Digite : (3) para mostrar Arvore AVL de veiculos Automaticos que custam menos de 75000 \n  Digite : (4) para mostrar Arvore Binaria de veiculos flex com direção elétrica \n  Digite : (5) para mostrar Arvore AVL de todos preços\n  Digite : (6) para excluir um nó de uma das arvores" << endl;
            cin >> arv1ou2;
            switch (arv1ou2)
            {
                case 0:
                cout << "Digite a placa a ser buscada" << endl;
                cin >> ex;
                if(search(rootAVL, ex) == true){
                cout << "Pertence a arvore!" << endl;
                }else cout << "NÃO Pertence a arvore!" << endl;
                break;

                case 1:
                printTree(rootAVL,0);
                cout << "AVL Geral - pre ordem:" << endl;
                preOrder(rootAVL);
                break;

                case 2:
                printTree(rootBI,0);
                cout << "Binaria Geral - pre ordem:" << endl;
                preOrder(rootBI);
                break;

                case 3:
                //fazendo as inserções com IF de filtro
                percorredor = cabeca->inicio->prox;
                    while (percorredor != NULL)
                    {
                        if (percorredor->moua == "Automático" && percorredor->preco < 75000.00) 
                        {
                            rootAVLFiltro = insert(rootAVLFiltro, percorredor->placa); 
                            percorredor = percorredor->prox;
                        } else {
                        percorredor = percorredor->prox;
                        }
                    }
                printTree(rootAVLFiltro,0);
                cout << "Pre-ordem:" << endl;
                preOrder(rootAVLFiltro);
                break;

                case 4:
                //fazendo as inserções com IF de filtro
                percorredor = cabeca->inicio->prox;
                    while (percorredor != NULL)
                    {
                        if (percorredor->direcao == "Elétrica" && percorredor->consumo == "Flex" )
                        {
                            rootBIFiltro = insertBI(rootBIFiltro, percorredor->placa); 
                            percorredor = percorredor->prox;
                        }else
                        {
                           percorredor = percorredor->prox; 
                        }
                    }
                printTree(rootBIFiltro,0);
                cout << "Pre-ordem:" << endl;
                preOrder(rootBIFiltro);
                break;

                case 5:
                percorredor = cabeca->inicio->prox;
                 while (percorredor != NULL)
                    {
                            rootAVLPreco = insert(rootAVLPreco, percorredor->preco); 
                            percorredor = percorredor->prox;
                    }
                printTree(rootAVLPreco,0);
                break;

                case 6:
                int tipoarvore;
                cout << "Dê o numero da arvore em que o nó será excluído - (1 - AVL ou 2 - BINARIA)" << endl;
                cin >> tipoarvore;
                cout << "Qual elemento excluir? (placa)" << endl;
                string element;
                cin >> element;
                if (tipoarvore == 1){
                    deleteNode(rootAVL,element);
                }else{
                    cout << "em casa" << endl;
                    deleteNodeB(rootBI,element);
                }

                break;
                
            }
        break;
        case 7:
            salva(cabeca);
            resp = 1;
        break;
        }
    } while (resp != 1);
    encerra_lista(cabeca); encerra_lista(placas);encerra_lista(pilha); encerra_lista(fila);
    freeTree(rootAVL);freeTree(rootBI);freeTree(rootBIFiltro);freeTree(rootAVLFiltro);
    return 0;
}