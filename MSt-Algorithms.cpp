#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000

/*
-> Nos querermos fazer uma arvore geradora de peso minimo, ou seja,
queremos manter todos os vertices ligados com o menor peso possível
entre cada um;
*/

//======================================Prim=========================================

void Prim(int s){//Muito parecido com Dijkstra, ate com o mesmo tempo
    vi d(vertices, INF);
    d[s] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> heap;
    heap.push(ii(0, s));

    while(!heap.empty()){
        ii aux = heap.top(); heap.pop();

        int now = aux.second;
        for(int i=0; i<adj[now].size(); i++){
            ii here = adj[vertice][i];
            if(d[here.second]>here.first){
                d[here.second] = here.first;
                heap.push(ii(here.first, here.second));
            }
        }
    }
}

//====================================================================================

//=======================================Kruskal======================================
int findSet(int x);
int union(int v, int u);

vector<pair<int, ii> edges;

void Kruskal(){//Baseado em disjoint sets
    int arestas=0, i, j;

    //Nao há nenhuma ligação no começo
    for(i = 0; i<vertices; i++){
        dad[i] = i;

        //Coloca todas as arestas no vector edges
        for(j = 0; i<adj[i].size(); j++){
            ii aux = adj[i][j];
            edges.push_back(make_pair(aux.first, ii(i, aux.second)));
            arestas++;
        }
    }

    sort(edge.begin(), edge.end());//ordem crescente

    for(i = 0; i < arestas; i++){
        pair<int, ii> aux = edge[i];
        if(findSet(aux.second.first)!=findSet(aux.second.second)){
            union(aux.second.first, aux.second.second);
        }
    }
}


int findSet(int x){
    if(dad[x]==x){
        return x;
    }else{
        return dad[dad[x]];
    }
}

int union(int v, int u){
    if(dad[v]==v){
        dad[v] = u;
    }else{
        union(dad[v], u);
    }
}

//====================================================================================
