#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include "Estruturas.h"

Apontador Aux; //TipoCelula* Aux;
long i;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;
TipoGrafo Grafo, GrafoT;
TipoValorVertice NVertices;
int  NArestas;
short FimListaAdj;

void FLVazia(TipoLista *Lista);
short Vazia(TipoLista Lista);
void Insere(TipoItem *x, TipoLista *Lista);
void FGVazio(TipoGrafo *Grafo);
void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);
short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2,TipoGrafo *Grafo);
short  ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo);
Apontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo);

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo,
             TipoValorVertice *Adj, TipoPeso *Peso,
             Apontador *Prox, short *FimListaAdj);

void Retira(Apontador p, TipoLista *Lista, TipoItem *Item);

void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2,
                  TipoPeso *Peso, TipoGrafo *Grafo);

void LiberaGrafo(TipoGrafo *Grafo);
void ImprimeGrafo(TipoGrafo *Grafo);
void ImprimeLista(TipoLista Lista);
void GrafoTransposto(TipoGrafo *Grafo, TipoGrafo *GrafoT);


#endif // FUNCOES_H_INCLUDED
