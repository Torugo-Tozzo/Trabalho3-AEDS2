#pragma
#include <string>

using namespace std;

struct Veiculo{
    string modelo;
    string marca;
    string versao;
    string ano;
    string kilometragem;
    string motor;
    string consumo;
    string moua;
    string direcao;
    string cor;
    string portas;
    string placa;
    float preco;
    struct Veiculo *prox;
};

struct Cabecalho{
    int tam;
    struct Veiculo *inicio;    
};
void addLista(Cabecalho *listaAlvo, Cabecalho *listaCopia);
void leArq(Cabecalho *listaAlvo, string filename);
void imprime(Cabecalho *exemplo);
void imprime_placa(Cabecalho *placas);
void busca(Cabecalho *cabeca, string placaexemplo);
void exclui(Cabecalho *cabeca,string placaexemplo);
void insere_inicio(Cabecalho *cabeca , string modelo,string marca,string versao,string ano,string kilometragem,string motor,string consumo,string moua,string direcao,string cor,string portas,string placa,float preco);
void insere_fim(Cabecalho *cabeca , string modelo,string marca,string versao,string ano,string kilometragem,string motor,string consumo,string moua,string direcao,string cor,string portas,string placa,float preco);
void inserir_ordenado(Cabecalho *placas, string placa, string modelo);
void ordena_placa(Cabecalho *cabeca, Cabecalho *placas);
void encerra_lista(Cabecalho *cabeca);
void insere_fim(Cabecalho *pilha, string direcao, string modelo, string moua);
void remove_fim(Cabecalho *pilha);
void cria_pilha(Cabecalho *cabeca, Cabecalho *pilha);
void remove_inicio(Cabecalho *fila);
void cria_fila(Cabecalho *cabeca, Cabecalho *fila);
void salva(Cabecalho *exemplo);

