#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000


void dijkstra(int v){//.first = weight; .second = vertice;

    //Initialize:
    vi d(Vertices, INF);//Seta todas as primeiras distancias como zero
    d[v] = 0;
    ii ini = make_pair(0, v);

    //Cria uma min heap que guardará as distancias para dar sempre as menores
    priority_queue <ii, vector<ii>, greater<ii>> heap;
    heap.push(ini);//Adiciona o par com a distancia (0) e o vertice de agora (v)

    //Enquanto ainda houver distancias "possiveis" de serem melhores, eu continuo o laço
    while(!heap.empty()){
        //Pego a menor distancia até agora
        ii now = heap.top();
        heap.pop();

        int weight = now.first;
        int vertice = now.second;
        if(weight>d[vertice]) continue;

        //Vejo todos os caminhos que esse vertice pode levar
        for(int i =0; i<adj[vertice].size(); i++){
            ii aux = adj[vertice][i];
            //Caso o caminho passando por ele seja menor do que o ja calculado antes
            if(d[aux.second] > d[vertice] + aux.first){
                //Atualizo o melhor caminho ate agora
                d[aux.second] = d[vertice] + aux.first;

                //Coloco o novo valor da distancia na heap
                ii put = make_pair(d[aux.second], aux.second)
                heap.push(put);
            }
        }
    }

}

/*Eu sempre pego o menor da distancias ate agora pois, por indução(tendo em vista que nao podem
haver arestas com peso negativo), sabemos que não há caminho melhor para este vértice!
