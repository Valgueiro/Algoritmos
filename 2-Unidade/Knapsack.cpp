/*
	Mateus Valgueiro Teixeira
 Graduando em Engenharia da Computação - CIn/UFPE
             mvt@cin.ufpe.br
*/

#include <bits/stdc++.h>
#define weight first
#define value second

using namespace std;

typedef pair <int, int > ii;
typedef vector < ii > vii;

int k, qtd;
vii itens;

int max(int a, int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
}

int knapsack(){
	int i, j;

	vector<vector<int > > mat;

	mat.resize(qtd+1);
	for(i = 0; i<=qtd; i++){
		mat[i].resize(k+1);
	}

	for(i = 0; i<=k; i++){
		mat[0][i] = 0;
	}

	for(i=1; i<=qtd; i++){
		for(j=0; j<=k; j++){
			ii aux = itens[i-1];
			if(j<aux.weight){
				mat[i][j] = mat[i-1][j];
			}else{
				mat[i][j] = max((mat[i-1][j-aux.weight] + aux.value), mat[i-1][j]); 
			}
		}
		
	}

}

