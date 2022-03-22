#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

using namespace std;

const int MaxNumVertices = 100; //Aqui criasse uma variável que recebe o número máximo de vértices
const int MaxNumArestas = 4500; //Aqui criasse uma variável que recebe o número máximo de aréstas
const int null = 0; //Criasse uma constante null que será utilizada para apontador nulo

typedef int TipoValorVertice; // Faz-se um typedef para o valor do vértice
typedef int TipoPeso; // Aqui se faz o mesmo para o peso

struct TipoItem // Essa estrutura possui os dados que estara dentro da lista criada
{
    TipoValorVertice Vertice;
    TipoPeso Peso;
};

typedef struct TipoCelula *Apontador; // Esse procedimento cria um ponteiro para o tipo célula

struct TipoCelula // Dentro dessa posssui  o tipo item e ponteiro para o próximo
{
    TipoItem Item;
    Apontador Prox; //TipoCelula *Prox;
};

typedef struct TipoCelula Celula;

struct TipoLista // Esse possui os ponteiros para o primeiro e ultimos elementos
{
    Apontador Primeiro, Ultimo; //TipoCelula *Primeiro,*Ultimo;
};

struct TipoGrafo  /* O tipo grafo é constituido de uma vetor de lista contendo o numero de
                     vértices, além de variáveias para o número de vértiecs e arestas */
{
    TipoLista Adj[MaxNumVertices];
    TipoValorVertice NumVertices;
    short NumArestas;
};

#endif // ESTRUTURAS_H_INCLUDED
