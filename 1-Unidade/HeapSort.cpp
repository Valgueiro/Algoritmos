/*
	Mateus Valgueiro Teixeira
 Graduando em Engenharia da Computação - CIn/UFPE
             mvt@cin.ufpe.br
*/

#include <bits/stdc++.h>

using namespace std;

int heap[501] = {};
int size;
int sizefull;

int dad(int i){
	return (i/2);
}

int left(int i){
	return (2*i);
}

int right(int i){
	return (2*i+1);
}

void print(int num){
	for(int i=1; i<num; i++){
		printf(" %d |", heap[i]);
	}
	printf(" %d", heap[num]);
}

void heapify(int i){
	if(size>=left(i)){
		if(size>=right(i)){
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
		}else{
			if(heap[left(i)]>heap[i]){
				int aux = heap[i];
				heap[i] = heap[left(i)];
				heap[left(i)] = aux;
				heapify(left(i));
			}
		}
		
	}
}

void heapsort(){
	while(size>1){
		int max = heap[1];
		heap[1] = heap[size];
		heap[size] = max;
		size--;
		heapify(1);
	}	

}
