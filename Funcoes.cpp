#include<iostream>
#include "Estruturas.h"

/*--Entram aqui os operadores do Programa 2.4--*/
void FLVazia(TipoLista *Lista) //Faz a lista fica vazia, assim inicializando ela
{
    Lista->Primeiro = new TipoCelula;
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = null;
}

short Vazia(TipoLista Lista) // verifica se a lista está vazia
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem *x, TipoLista *Lista) // Procedimento pra inserir um item a lista
{
    /*-- Insere depois do ultimo item da lista --*/
    Lista->Ultimo->Prox = new TipoCelula;
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = *x;
    Lista->Ultimo->Prox = null;
}

/*-- Fim operadores do Programa 2.4 --*/
void FGVazio(TipoGrafo *Grafo) // Faz o grafo vazio, esta funcão faz a utilização da função faça lista vazia
{
    long i;
    for (i = 0; i < Grafo->NumVertices; i++)
        FLVazia(&Grafo->Adj[i]);
}

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)// Insere um nova aresta
{
    TipoItem x;
    x.Vertice = *V2;
    x.Peso = *Peso;
    Insere(&x, &Grafo->Adj[*V1]);
}

short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2,TipoGrafo *Grafo)// Faz uma pesquisa para verificar se determinada aresta existe
{
    Apontador Aux; //TipoCelula *Aux;
    short  EncontrouAresta = false;
    Aux = Grafo->Adj[Vertice1].Primeiro->Prox;

    while (Aux != null && EncontrouAresta == false)
    {
        if (Vertice2 == Aux->Item.Vertice)
            EncontrouAresta = true;
        Aux = Aux->Prox;
    }
    return EncontrouAresta;
}

/*-- Operadores para obter a lista de adjacentes --*/
short  ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo) // Verifica  a lista em adjacência está vazia
{
    return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

Apontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo) // Retorna a posição na memória do primeiro item na lista de adjacência
{
    return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo,
             TipoValorVertice *Adj, TipoPeso *Peso,
             Apontador *Prox, short *FimListaAdj)//Verifica qual é o próximo item apontado
{
    /* --Retorna Adj e Peso do Item apontado por Prox--*/
    *Adj = (*Prox)->Item.Vertice;
    *Peso = (*Prox)->Item.Peso;
    *Prox = (*Prox)->Prox;
    if (*Prox == null)
        *FimListaAdj = true;
}

void Retira(Apontador p, TipoLista *Lista, TipoItem *Item)// Retira um item da lista fazendo as devidas alterações
{
    /*--Obs.: item a ser retirado e o seguinte ao apontado por p--*/
    Apontador q;
    if (Vazia(*Lista) || p == null || p->Prox == null)
    {
        cout<<"Erro: Lista vazia ou posicao nao existe\n";
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if (p->Prox == null)
        Lista->Ultimo = p;

    delete(q);
}

void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2,
                  TipoPeso *Peso, TipoGrafo *Grafo)//Faz as alterações demaneira que retire a aresta respectiva
{
    Apontador AuxAnterior, Aux;
    short EncontrouAresta = false;
    TipoItem x;
    AuxAnterior = Grafo->Adj[*V1].Primeiro;
    Aux = Grafo->Adj[*V1].Primeiro->Prox;
    while (Aux != null && EncontrouAresta == null)
    {
        if (*V2 == Aux->Item.Vertice)
        {
            Retira(AuxAnterior, &Grafo->Adj[*V1], &x);
            Grafo->NumArestas--;
            EncontrouAresta = true;
        }
        AuxAnterior = Aux;
        Aux = Aux->Prox;
    }
}

void LiberaGrafo(TipoGrafo *Grafo)// Torna o grafo vazio
{
    Apontador AuxAnterior, Aux;
    for (int i = 0; i < Grafo->NumVertices; i++)
    {
        Aux = Grafo->Adj[i].Primeiro->Prox;
        delete(Grafo->Adj[i].Primeiro);   /*Libera celula cabeca*/
        Grafo->Adj[i].Primeiro=null;

        while(Aux != null)
        {
            AuxAnterior = Aux;
            Aux = Aux->Prox;
            delete(AuxAnterior);
        }
    }
    Grafo->NumVertices = 0;
}

void ImprimeGrafo(TipoGrafo *Grafo)// Faz impressão do grafo demosntrando seus vértices e arestas presentes
{
    int i;
    Apontador Aux;
    for (i = 0; i < Grafo->NumVertices; i++)
    {
        cout<<"Vertice "<<i<<" :";
        if (!Vazia(Grafo->Adj[i]))
        {
            Aux = Grafo->Adj[i].Primeiro->Prox;
            while (Aux != null)
            {
                cout<<Aux->Item.Vertice<<" ("<<Aux->Item.Peso<<") ";
                Aux = Aux->Prox;
            }
        }
        cout<<endl;
    }
}

void ImprimeLista(TipoLista Lista)// Imprime a lista mostrando o vértice e o peso
{
    Apontador Aux;
    Aux = Lista.Primeiro->Prox;
    while (Aux != null)
    {
        cout<<Aux->Item.Vertice<<Aux->Item.Peso;
        Aux = Aux->Prox;
    }
}

void GrafoTransposto(TipoGrafo *Grafo, TipoGrafo *GrafoT)//Inverte o grafo em suas direções
{
    short FimListaAdj;
    TipoValorVertice v, Adj;
    TipoPeso Peso;
    Apontador Aux;
    GrafoT->NumVertices = Grafo->NumVertices;
    GrafoT->NumArestas = Grafo->NumArestas;
    FGVazio(GrafoT);
    for (v = 0; v <= Grafo->NumVertices - 1; v++)
    {
        if (!ListaAdjVazia(&v, Grafo))
        {
            Aux = PrimeiroListaAdj(&v, Grafo);
            FimListaAdj = false;
            while (!FimListaAdj)
            {
                ProxAdj(&v, Grafo, &Adj, &Peso, &Aux, &FimListaAdj);
                InsereAresta(&Adj, &v, &Peso, GrafoT);
            }
        }
    }
}
