/*
    Victor Hugo Tozzo Filho	- 2020.1.08.018
    Pedro Henrique Alves Barbosa - 2022.1.08.043
    Rafael Silva Fortuna- 2022.1.08.026

        !!!!!!AVISO IMPORTANTE!!!!!!
        Nesta implementação de lista encadiada,
        o primeiro slot (o primeiro nó da lista), ficará sempre vazio, contendo valores nulos
        ou seja a lista começa a partir do segundo nó
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include "lista.h"

using namespace std;

int resultado;

void leArq(Cabecalho *listaAlvo, string filename)
{
    Veiculo *bd = listaAlvo->inicio;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            bd->prox = new Veiculo;
            bd = bd->prox;
            myfile >> bd->modelo;
            myfile >> bd->marca;
            myfile >> bd->versao;
            myfile >> bd->ano;
            myfile >> bd->kilometragem;
            myfile >> bd->motor;
            myfile >> bd->consumo;
            myfile >> bd->moua;
            myfile >> bd->direcao;
            myfile >> bd->cor;
            myfile >> bd->portas;
            myfile >> bd->placa;
            myfile >> bd->preco;
            listaAlvo->tam++;
        }
        myfile.close();
    }
    else
        cout << "unable to open the file";
}

void insere_fim(Cabecalho *cabeca, string modelo, string marca, string versao, string ano, string kilometragem, string motor, string consumo, string moua, string direcao, string cor, string portas, string placa, string preco)
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
    cout << "veiculo inserido no fim da lista " << endl;
}

void addLista(Cabecalho *listaAlvo, Cabecalho *listaCopia)
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
        insere_fim(listaAlvo, model, marc, versa, an, kilometrage, moto, consum, mou, direca, co, porta, plac, prec);
        ac = ac->prox;
    }
}

void imprime(Cabecalho *exemplo)
{
    Veiculo *percorredor;
    percorredor = exemplo->inicio;
    while (percorredor != NULL)
    {
        cout << percorredor->modelo << " ";
        cout << percorredor->marca << " ";
        cout << percorredor->versao << " ";
        cout << percorredor->ano << " ";
        cout << percorredor->kilometragem << " ";
        cout << percorredor->motor << " ";
        cout << percorredor->consumo << " ";
        cout << percorredor->moua << " ";
        cout << percorredor->direcao << " ";
        cout << percorredor->cor << " ";
        cout << percorredor->portas << " ";
        cout << percorredor->placa << " ";
        cout << percorredor->preco << endl;
        percorredor = percorredor->prox;
    }
    cout << "-------------------------------------------------------------------------------\n";
}

void busca(Cabecalho *cabeca, string placaexemplo)
{
    Veiculo *percorredor;
    percorredor = cabeca->inicio->prox;
    int pos = 1;
    while (pos <= cabeca->tam)
    {
        if (percorredor->placa != placaexemplo)
        {
            percorredor = percorredor->prox;
            pos++;
        }
        else if (percorredor->placa == placaexemplo)
        {
            cout << "Carro encontrado na posição " << pos << endl;
            resultado = pos;
            pos = cabeca->tam + 1;
        }
        else
            cout << "Tem essa placa aqui não, fiotão.";
    }
}

void exclui(Cabecalho *cabeca, string placaexemplo)
{
    Veiculo *visitor;
    Veiculo *ant;
    visitor = cabeca->inicio;
    while (visitor->placa != placaexemplo)
    {
        ant = visitor;
        visitor = visitor->prox;
    }
    ant->prox = visitor->prox;
    free(visitor);
    cabeca->tam--;
}

void insere_inicio(Cabecalho *cabeca, string modelo, string marca, string versao, string ano, string kilometragem, string motor, string consumo, string moua, string direcao, string cor, string portas, string placa, float preco)
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
    novo->prox = cabeca->inicio->prox;
    cabeca->inicio->prox = novo;
    cabeca->tam++;
    cout << "veiculo inserido no inicio da lista " << endl;
}

void insereArq(Cabecalho *guard, Cabecalho *cabec)
{
    Veiculo *perc = guard->inicio;
    while (perc != NULL)
    {
        Veiculo *perc2 = cabec->inicio->prox;
        while (perc2 != NULL)
        {
            perc2 = perc2->prox;
        }
        perc2 = new Veiculo;
        perc2 = perc;
        perc2->prox = NULL;
        perc = perc->prox;
    }
}

void encerra_lista(Cabecalho *cabeca)
{
    Veiculo *ant = cabeca->inicio;
    Veiculo *pont = cabeca->inicio;
    while (ant != NULL)
    {
        pont = ant->prox;
        delete (ant);
        ant = pont;
    }
    delete (cabeca);
    cout << "-As listas/pilhas/filas foram desalocadas." << endl;
}
void insere_fim(Cabecalho *pilha, string direcao, string modelo, string moua)
{
    Veiculo *percorredor, *novo = new Veiculo;
    novo->direcao = direcao;
    novo->modelo = modelo;
    novo->moua = moua;
    novo->prox = NULL;
    if (pilha->tam == 0)
    {
        novo->direcao = direcao;
        novo->modelo = modelo;
        pilha->inicio = novo;
        pilha->tam++;
    }
    else
    {
        percorredor = pilha->inicio;
        while (percorredor->prox != NULL)
        {
            percorredor = percorredor->prox;
        }
        novo->direcao = direcao;
        percorredor->prox = novo;
        pilha->tam++;
    }
    // cout<<"Carro Inserido" <<  endl;
}
void remove_fim(Cabecalho *pilha)
{
    Veiculo *percorredor, *ant, *antant;
    percorredor = pilha->inicio;
    ant = percorredor;
    while (percorredor->prox != NULL)
    {
        ant = percorredor;
        percorredor = percorredor->prox;
    }
    if (pilha->tam > 0)
    {
        ant->prox = NULL;
        free(percorredor);
        pilha->tam--;
        // cout << "Ultimo elemento da lista removido!\n";
    }
    else
    {
        // cout << "lista vazia\n";
    }
}

void remove_inicio(Cabecalho *fila)
{
    Veiculo *primeiro;
    if (fila->tam > 0)
    {
        primeiro = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(primeiro);
        fila->tam--;
        // cout << "Primeiro elemento da lista removido!\n";
    }
    else
    {
        // cout << "pilha vazia\n";
    }
}

void salva(Cabecalho *exemplo)
{
    ofstream myfile("BD_veiculos_2.txt");
    if (myfile.is_open())
    {
        Veiculo *percorredor;
        percorredor = exemplo->inicio->prox;
        while (percorredor != NULL)
        {
            myfile << percorredor->modelo << " ";
            myfile << percorredor->marca << " ";
            myfile << percorredor->versao << " ";
            myfile << percorredor->ano << " ";
            myfile << percorredor->kilometragem << " ";
            myfile << percorredor->motor << " ";
            myfile << percorredor->consumo << " ";
            myfile << percorredor->moua << " ";
            myfile << percorredor->direcao << " ";
            myfile << percorredor->cor << " ";
            myfile << percorredor->portas << " ";
            myfile << percorredor->placa << " ";
            if (percorredor->prox == NULL)
            {
                myfile << percorredor->preco;
            }
            else
                myfile << percorredor->preco << endl;
            percorredor = percorredor->prox;
        }
    }
}
