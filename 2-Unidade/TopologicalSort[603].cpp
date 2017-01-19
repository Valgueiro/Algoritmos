#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct node{
	int value;
	node* next;
};


node* adj[201];
vi mkd;
char nomes[30][16];
int qtd, cont, top[30];
bool ciclo;

int num(char str[]){
    for(int i=0; i<qtd; i++){
        if(!strcmp(str, nomes[i])){
            return i;
        }
    }
}

int insertEdge(int end, int begin){
    node* aux = adj[begin];
    if(aux==NULL){
        adj[begin] = new node();
        adj[begin]->value = end;
        adj[begin]->next = NULL;
    }else{
        while(aux->next!=NULL){
            aux = aux->next;
        }
        aux->next = new node();
        aux = aux->next;
        aux->value = end;
        aux->next = NULL;
    }

}

void dfsVisit(int v){
    mkd[v] = 2;//Marked temporary
    node* aux = adj[v];
	while(aux!=NULL){
        if(mkd[aux->value] == 0){
            dfsVisit(aux->value);
        }else if(mkd[aux->value] == 2){//catched a temporary marked node
			ciclo = true;
        }
		aux = aux->next;
    }
	mkd[v] = 1;
	top[cont] = v;
    cont++;

}

void dfs(){
    for(int i=0; i<qtd; i++){
		if(mkd[i]==0){
            dfsVisit(i);
        }
    }

}
int main(){
    int test = 1, i, j, aux, neigh;
    char str[16], v1[16];
    while(scanf("%d", &qtd)!=EOF && qtd!=0){
		mkd.clear();
		ciclo = false;
        cont = 0;
        printf("Teste %d\n", test);
        test++;

		for(i=0; i<qtd; i++){
		    scanf(" %s", nomes[i]);
			mkd.push_back(0);
			adj[i] = NULL;
		}

        for(i=0; i<qtd; i++){
            scanf(" %s", str);
            scanf("%d", &neigh);
            for(j=0; j<neigh; j++){
                scanf(" %s", v1);
                insertEdge(num(str), num(v1));
            }
        }



        dfs();

		if(ciclo){
            printf("impossivel\n");
        }else{
            for(i=cont-1; i>=0; i--){
                printf("%s ", nomes[top[i]]);
            }
			printf("\n");
        }
		printf("\n");

    }

    return 0;
}
