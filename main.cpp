/* Trabalho Final
   Nomes: Eduardo Augusto
          João Vitor
          Luiz Filipe
          Maíla
*/

#include<iostream>
#include "Estruturas.h"
#include "Funcoes.h"

using namespace std;

int main()
{
    cout<<"=================================================================\n";
    cout<<"Grafos e a sua implementacao por meio de Listas de Adjacencia\n";
    cout<<"usando estruturas auto-referenciavais\n\n";

   /*-- Programa principal --*/
    int TEMP;
    int TEMP1;

    /* -- NumVertices: definido antes da leitura das arestas --*/
    /* -- NumArestas: inicializado com zero e incrementado a --*/
    /* -- cada chamada de InsereAresta                       --*/

    cout<<"Numero de vertices:";
    cin>>TEMP;
    NVertices = TEMP;
    cout<<"Numero de arestas:";
    cin>>NArestas;

    Grafo.NumVertices = NVertices;
    Grafo.NumArestas = 0;
    FGVazio(&Grafo);

    for (i = 0; i < NArestas; i++)
    {
        cout<<"Insere V1 -- V2 -- Peso:";
        cin>>TEMP;
        cin>>TEMP1;
        cin>>Peso;

        V1 = TEMP;
        V2 = TEMP1;
        Grafo.NumArestas++;
        InsereAresta(&V1, &V2, &Peso, &Grafo);   /* 1 chamada g-direcionado    */
        /*InsereAresta(V2, V1, Peso, Grafo);*/
        /* 2 chamadas g-naodirecionado*/
    }
    ImprimeGrafo(&Grafo);

    cout<<"\nGrafo transposto:\n";
    GrafoTransposto(&Grafo, &GrafoT);
    ImprimeGrafo(&GrafoT);

    cout<<"\nInsere V1 -- V2 -- Peso:";
    cin>>V1;
    cin>>V2;
    cin>>Peso;

    if (ExisteAresta(V1, V2, &Grafo))
        cout<<"Aresta ja existe\n";
    else
    {
        Grafo.NumArestas++;
        InsereAresta(&V1, &V2, &Peso, &Grafo);
        /*InsereAresta(V2, V1, Peso, Grafo);*/
    }
    ImprimeGrafo(&Grafo);

    cout<<"\nLista adjacentes de: ";
    cin>>TEMP;
    V1 = TEMP;
    if (!ListaAdjVazia(&V1, &Grafo))
    {
        Aux = PrimeiroListaAdj(&V1, &Grafo);
        FimListaAdj = false;
        while (!FimListaAdj)
        {
            ProxAdj(&V1, &Grafo, &Adj, &Peso, &Aux, &FimListaAdj);
            cout<<Adj<<Peso;
        }
        cout<<endl;
    }

    cout<<"\nRetira aresta V1 -- V2:";
    cin>>V1;
    cin>>V2;

    if(ExisteAresta(V1, V2, &Grafo))
    {
        Grafo.NumArestas--;
        RetiraAresta(&V1, &V2, &Peso, &Grafo);
        /*RetiraAresta(V2, V1, Peso, Grafo);*/
    }

    else
        cout<<"Aresta nao existe\n";

    ImprimeGrafo(&Grafo);

    cout<<"\nExiste aresta V1 -- V2:";
    cin>>TEMP;
    cin>>TEMP1;

    V1 = TEMP;
    V2 = TEMP1;
    if (ExisteAresta(V1, V2, &Grafo))
        cout<<" Sim\n";
    else
        cout<<" Nao\n";
    LiberaGrafo(&Grafo);   /* Imprime sujeira normalmente */
    ImprimeGrafo(&Grafo);

    cout<<"\n=================================================================\n";

    return 0;
}
