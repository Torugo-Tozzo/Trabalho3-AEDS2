#ifndef _LISTA_H_
#define _LISTA_H_
#include <string>

using namespace std;

struct Veiculo{
    string modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa,preco;
    struct Veiculo *prox;
};

struct Cabecalho{
    int tam;
    struct Veiculo *inicio;    
};

#endif