/*
	Mateus Valgueiro Teixeira
 Graduando em Engenharia da Computação - CIn/UFPE
             mvt@cin.ufpe.br
*/

#include <bits/stdc++.h>

using namespace std;

void place(int* arr, int start, int middle, int end){
	int i = start;
	int j = middle+1;
	int aux[100];
	int here = start;
	while(i<=middle && j<=end){
		if(arr[i]<arr[j]){
			aux[here] = arr[i];
			here++;
			i++;
		}else{
			aux[here] = arr[j];
			here++;
			j++;
		}
	}
	while(i<=middle){
		aux[here] = arr[i];
		here++;
		i++;
	}
	while(j<=end){
		aux[here] = arr[j];
		here++;
		j++;
	}

	for(int cont = start; cont<=end; cont++){
		arr[cont] = aux[cont];
	}
}

void merge(int* arr, int start, int end){
	if(start<end){
		int middle = (start+end)/2;
		merge(arr, start, middle);
		merge(arr, middle+1, end);
		place(arr, start, middle, end);
	}
}
