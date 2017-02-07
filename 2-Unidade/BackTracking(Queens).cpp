/*
	Mateus Valgueiro Teixeira
 Graduando em Engenharia da Computação - CIn/UFPE
             mvt@cin.ufpe.br
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

stack<int> pos[10][10];

int put(int line, int col){/*Marcar todos os espaços que a rainha atual marca*/
	int j, i;
	for(j=1; j<n+1; j++){
		if(j!=col) pos[line][j].push(col);
	}

	for(i=1; i<n+1; i++){
		for(j=1; j<n+1; j++){
			if(i-j == line - col){
				pos[i][j].push(col);
			}
			if((i+j) == (line+col) && line!=i){
				pos[i][j].push(col);
			}
		}
	}
}

int clear(int line, int col){/*Retirar todos os espaços marcados pelo atual*/
	int j, i;
	
	for(j=1; j<n+1; j++){
		if(j!=col) pos[line][j].pop();
	}

	for(i=1; i<n+1; i++){
		for(j=1; j<n+1; j++){
			if(i-j == line - col){
				pos[i][j].pop();
			}
			if((i+j) == (line+col) && line!=i){
				pos[i][j].pop();
			}
		}
	}
}

int backtrack(int line, int column){
	int i, j;
	bool could = false;
	
	if(column == n+1){
		/*Achei uma Solução*/
 		return 1;
	}	

	for(i=line; i<n+1; i++){
		if(pos[i][column].empty()){
			/*Achei um local possível*/
			results[column] = i;
			put(i, column);
			could = true;
			break;
		}
	}

	if(could){
		/*Caso eu tenha conseguido colocar esta e a proxima não, tenho que mudar a posição desta*/
		if(!backtrack(1, column+1)){
			//Limpando tudo feito nesta passada
			clear(i, column);
			//E voltando para o backtrack na coluna após esta
			return backtrack(i+1, column);
		}
	}else{
		/*Deu merda*/
		return 0;
	}
	
}

