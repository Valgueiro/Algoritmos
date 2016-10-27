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

void bfs(int v){//i'll always mark a vertice in the shortest path
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


void dfs(int v){//better to Edge classification, find cycles and Topological sort
    mkd[v] = 1;
    node* aux = adj[v];
    while(aux!=NULL){
        if(!mkd[aux->value]){
            dfs(aux->value);
        }else{
            //Aresta de retorno[Backward edge] -> means we have a cycle
        }
        aux = aux->next;
    }
}

/*Topological Sort:
    We use dfs and output the REVERSE of finishing times(when aux==NULL) of vertices
obs: It only works with Directed Acyclic Graphs[DAG] (we can prove cycle with the same dfs);
*/

//how to do an Adjacency list:
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
