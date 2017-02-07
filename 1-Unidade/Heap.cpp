/*
	Mateus Valgueiro Teixeira
 Graduando em Engenharia da Computação - CIn/UFPE
             mvt@cin.ufpe.br
*/

#include <bits/stdc++.h>

using namespace std;

int heap[501];
int size;

int dad(int i){
	return (i/2);
}

int left(int i){
	return (2*i);
}

int right(int i){
	return (2*i+1);
}

void print(){
	for(int i=1; i<size; i++){
		printf(" %d |", heap[i]);
	}
	printf(" %d", heap[size]);
}

void heapify(int i){
	if(size>=left(i)){
		if(heap[left(i)]>heap[right(i)]){
			if(heap[left(i)]>heap[i]){
				int aux = heap[i];
				heap[i] = heap[left(i)];
				heap[left(i)] = aux;
				heapify(left(i));
			}
		}else{
			if(heap[right(i)]>heap[i]){
				int aux = heap[i];
				heap[i] = heap[right(i)];
				heap[right(i)] = aux;
				heapify(right(i));
			}
		}
	}

	
}

int main(){
	int i;
	for(i = 1; scanf("%d", &heap[i])==1; i++);
	i--;
	size = i;
	
	printf("Estado inicial:");
	print();
	
	for(i = (size/2); i>0; i--){
		heapify(i);
		printf("\nEstado Atual:");
		print();
	}
	
	printf("\nResultado Final:");
	print();
	return 0;
}
