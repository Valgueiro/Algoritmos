#include <bits/stdc++.h>

using namespace std;

void Quick(int* arr, int inicio, int fim){
   
	int pivo, aux, i, j, meio;
	   
	i = inicio;
	j = fim;
	   
	meio = (int) ((i + j) / 2);
	pivo = arr[meio];
	   
	do{
		while (arr[i] < pivo) i = i + 1;
	    while (arr[j] > pivo) j = j - 1;
	      
	    if(i <= j){
	        aux = arr[i];
	        arr[i] = arr[j];
	        arr[j] = aux;
	        
	        i = i + 1;
	        j = j - 1;
	    }
	}while(j > i);
	   
	if(inicio < j) Quick(arr, inicio, j);
	if(i < fim) Quick(arr, i, fim);   

}
