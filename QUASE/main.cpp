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
#include <iostream>
#include <string>
#include "arvores.cpp"
#include "lista.h"
#include "lista.cpp"
#include "binaria.cpp"
#include "avl.cpp"
#include "no.h"

using namespace std;

void insere_fim_arv(Cabecalho *cabeca, ArvAVL avl, ArvBinaria binaria, string modelo, string marca, string versao, string ano, string kilometragem, string motor, string consumo, string moua, string direcao, string cor, string portas, string placa, string preco)
{
    Veiculo *novo = new Veiculo;
    novo->modelo = modelo;
    novo->marca = marca;
    novo->versao = versao;
    novo->ano = ano;
    novo->kilometragem = kilometragem;
    novo->motor = motor;
    novo->consumo = consumo;
    novo->moua = moua;
    novo->direcao = direcao;
    novo->cor = cor;
    novo->portas = portas;
    novo->placa = placa;
    novo->preco = preco;

    Veiculo *percorredor;
    percorredor = cabeca->inicio;
    while (percorredor->prox != NULL)
    {
        percorredor = percorredor->prox;
    }
    percorredor->prox = novo;
    novo->prox = NULL;
    cabeca->tam++;
    avl.insert(avl.raiz, novo);
    binaria.inserir(novo);
    cout << "veiculo inserido na arvore" << endl;
}

void addLista_arv(Cabecalho *listaAlvo, Cabecalho *listaCopia, ArvAVL avl, ArvBinaria binaria)
{
    Veiculo *ac = listaCopia->inicio->prox;
    Veiculo *bd = listaAlvo->inicio->prox;
    while (ac != NULL)
    {
        while (bd->prox != NULL)
        {
            bd = bd->prox;
        }
        string model = ac->modelo;
        string marc = ac->marca;
        string versa = ac->versao;
        string an = ac->ano;
        string kilometrage = ac->kilometragem;
        string moto = ac->motor;
        string consum = ac->consumo;
        string mou = ac->moua;
        string direca = ac->direcao;
        string co = ac->cor;
        string porta = ac->portas;
        string plac = ac->placa;
        string prec = ac->preco;
        insere_fim_arv(listaAlvo, avl, binaria, model, marc, versa, an, kilometrage, moto, consum, mou, direca, co, porta, plac, prec);
        ac = ac->prox;
    }
}

int main(int argc, char **argv)
{

    Cabecalho *cabeca = new Cabecalho;
    Cabecalho *arquivo = new Cabecalho;

    cabeca->inicio = new Veiculo;
    arquivo->inicio = new Veiculo;

    leArq(cabeca, "BD_veiculos_2.txt");

    ArvBinaria binaria;

    Veiculo *percorredor = cabeca->inicio->prox;
    while (percorredor != NULL)
    {
        binaria.inserir(percorredor);
        percorredor = percorredor->prox;
    }

    ArvAVL avl;

    percorredor = cabeca->inicio->prox;
    while (percorredor != NULL)
    {
        avl.raiz = avl.insert(avl.raiz, percorredor);
        percorredor = percorredor->prox;
    }

    ArvAVL avlFiltro;

    percorredor = cabeca->inicio->prox;
    while (percorredor != NULL)
    {   
        if(percorredor->moua == "Automático")
        {
        avlFiltro.raiz = avl.insert(avl.raiz, percorredor);
        }
        percorredor = percorredor->prox;
    }

    string modelo, marca, versao, ano, kilometragem, motor, consumo, moua, direcao, cor, portas, placa, preco;
    int escolha, escolha1, escolha2, excoun; // do swtch 1 ,2 ,3 ,n.....
    string consulta, arq_name;               // da busca placa , nome do arquivo a ser adicionado
    do
    {
        cout << "\n-----------------------------Menu---------------------------------\n"
                " (0) - Mostrar arvores\n"
                " (1) - Buscar carro na arvore (excluir)\n"
                " (2) - Add carro na arvore(arquivo)\n"
                " (3) - \n"
             << endl;

        cin >> escolha;
        switch (escolha)
        {
        case 0:
            cout << " (1) - Arvore Binaria\n"
                    " (2) - Arvore AVL\n"
                    " (3) - Arvore AVL com filtro de carros automaticos com preço acima de 75k \n"
                 << endl;
            cin >> escolha1;
            switch (escolha1)
            {
            case 1:
                binaria.exibirArvore(binaria.raiz, 0);
                cout << "placas em ordem:" << endl;
                binaria.in_order(binaria.raiz);
                break;

            case 2:
                avl.exibirArvore(avl.raiz, 0);
                cout << "placas em ordem:" << endl;
                avl.in_order(avl.raiz);
                break;
            case 3:
                avlFiltro.exibirArvore(avlFiltro.raiz, 0);
                cout << "placas em ordem:" << endl;
                avlFiltro.in_order(avlFiltro.raiz);
                break;

            default:
                break;
            }
            break;
        case 1:
            cout << "placa a ser buscada na arvore: " << endl;
            cin >> consulta;
            avl.buscar(avl.raiz, consulta, escolha1);

            cout << "Deseja excluir?\n"
                    "(1) - sim\n"
                    "(2) - nao\n"
                 << endl;
            cin >> excoun;
            if (excoun == 1)
            {
                avl.raiz = avl.deleteNode(avl.raiz, consulta);
                binaria.raiz = binaria.deleteNodeB(binaria.raiz, consulta);
                cout << "Done" << endl;
            }
            else
                cout << "ok!" << endl;

            break;
        case 2:
            cout << "(1) - Para inserir manualmente\n"
                    "(2) - Para inserir a partir de um arquivo"
                 << endl;
            cin >> escolha2;
            switch (escolha2)
            {
            case 1:
                cout << "informe o modelo: ";
                cin >> modelo;
                cout << "informe marca: ";
                cin >> marca;
                cout << "informe versao: ";
                cin >> versao;
                cout << "informe ano: ";
                cin >> ano;
                cout << "informe kilometragem: ";
                cin >> kilometragem;
                cout << "informe motor: ";
                cin >> motor;
                cout << "informe consumo: ";
                cin >> consumo;
                cout << "informe se é manual ou automatico: ";
                cin >> moua;
                cout << "informe direcao: ";
                cin >> direcao;
                cout << "informe a cor: ";
                cin >> cor;
                cout << "informe o n de portas: ";
                cin >> portas;
                cout << "informe a placa: ";
                cin >> placa;
                cout << "informe o preco: ";
                cin >> preco;
                insere_fim_arv(cabeca, avl, binaria, modelo, marca, versao, ano, kilometragem, motor, consumo, moua, direcao, cor, portas, placa, preco);
                break;

            case 2:
                cout << "Nome do arquivo a ser inserido: " << endl;
                cin >> arq_name;
                leArq(arquivo, arq_name);
                addLista_arv(cabeca, arquivo, avl, binaria);
                break;

            default:
                break;
            }
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;

        default:
            break;
        }
    } while (escolha != 7);
    salva(cabeca);

    encerra_lista(cabeca);
    // freeTree(rootAVL);freeTree(rootBI);freeTree(rootBIFiltro);freeTree(rootAVLFiltro);
    return 0;
}