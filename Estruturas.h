#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

using namespace std;

const int MaxNumVertices = 100; //Aqui criasse uma vari�vel que recebe o n�mero m�ximo de v�rtices
const int MaxNumArestas = 4500; //Aqui criasse uma vari�vel que recebe o n�mero m�ximo de ar�stas
const int null = 0; //Criasse uma constante null que ser� utilizada para apontador nulo

typedef int TipoValorVertice; // Faz-se um typedef para o valor do v�rtice
typedef int TipoPeso; // Aqui se faz o mesmo para o peso

struct TipoItem // Essa estrutura possui os dados que estara dentro da lista criada
{
    TipoValorVertice Vertice;
    TipoPeso Peso;
};

typedef struct TipoCelula *Apontador; // Esse procedimento cria um ponteiro para o tipo c�lula

struct TipoCelula // Dentro dessa posssui  o tipo item e ponteiro para o pr�ximo
{
    TipoItem Item;
    Apontador Prox; //TipoCelula *Prox;
};

typedef struct TipoCelula Celula;

struct TipoLista // Esse possui os ponteiros para o primeiro e ultimos elementos
{
    Apontador Primeiro, Ultimo; //TipoCelula *Primeiro,*Ultimo;
};

struct TipoGrafo  /* O tipo grafo � constituido de uma vetor de lista contendo o numero de
                     v�rtices, al�m de vari�veias para o n�mero de v�rtiecs e arestas */
{
    TipoLista Adj[MaxNumVertices];
    TipoValorVertice NumVertices;
    short NumArestas;
};

#endif // ESTRUTURAS_H_INCLUDED
