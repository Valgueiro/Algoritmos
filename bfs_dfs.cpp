#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct node{
	int adj;
	node* next;
};
node* adj[201];
vi mkd;

void bfs(int v){
    queue<int> q;
    mkd[v] = 1;
    q.push(v);
    while(!q.empty()){
        node* now = adj[q.front()];
        q.pop();
        while(now!=NULL){
            if(!mkd[now->value]){
                q.push(now->value);
                mkd[now->value] = 1;
            }
            now = now->next;
        }
    }
}

void dfs(int v){
    mkd[v] = 1;
    node* aux = adj[v];
    while(aux!=NULL){
        if(!mkd[aux->value]){
            dfs(aux->value);
        }else{
            //Aresta de retorno
        }
        aux = aux->next;
    }
}

//Fazer a matriz de adjacencias
void insert(int v1, int v2){
	aux = adj[v1];
	if(aux!=NULL){
		while(aux->next!=NULL){
			aux = aux->next;
		}
		aux->next = new node;
		aux = aux->next;
		aux->adj = v2;
		aux->next=NULL;
	}else{
		vertice[v1] = new node;
		vertice[v1]->adj = v2;
		vertice[v1]->next=NULL;
	}

}
