/*
	Mateus Valgueiro Teixeira
 Graduando em Engenharia da Computação - CIn/UFPE
             mvt@cin.ufpe.br
*/

#include <bits/stdc++.h>

using namespace std;

struct node{
	int value;
	node* left;
	node* right;
	int balance;
};

node* root = new node;
bool heightchange = false;
bool printei = false;
bool troquei = false;

void printar(node* aux){
	printf(" %d ", aux->value, aux->balance);
	printf(" (");
	if(aux->left!=NULL){
		printar(aux->left);
	}
	printf(") ");
	printf(" (");
	if(aux->right!=NULL){
		printar(aux->right);
	}
	printf(") ");
}

void simpleRR(node*& a, node*& b){
	node* aux = a;
	
	if(a==root){
		root = b;
	}

	a = b;
	node* res = b->left;
	b->left = aux;
	aux->right = res;
}

void simpleLL(node*& a, node*& b){
	node* aux = a;
	
	if(a==root){
		root = b;
	}

	a = b;
	node* res = b->right;
	b->right = aux;
	aux->left = res;
}

int balance(node* aux){
	if(aux->left==NULL && aux->right!=NULL){
		return 1;
	}else if(aux->left!=NULL && aux->right==NULL){
		return -1;
	}else{
		return 0;
	}
}

bool verifyAVL(node*& now, node*& last){
	if(now->balance>1){
		if(now->right->balance>-1){//Right right -> simples direita
			now->balance = 0;
			now->right->balance = 0;
			simpleRR(now, now->right);

		}else{//Right left -> Dupla
			simpleLL(now->right, now->right->left);
			simpleRR(now, now->right);

			now->balance = balance(now);
			now->left->balance = balance(now->left);
			now->right->balance = balance(now->right);
		}
	}else if(now->balance<-1){
		if(now->left->balance<1){//left left -> simples direita
			now->balance = 0;
			now->left->balance = 0;
			simpleLL(now, now->left);
		
		}else{//left right -> Dupla
			simpleRR(now->left, now->left->right);
			simpleLL(now, now->left);

			now->balance = balance(now);
			now->left->balance = balance(now->left);
			now->right->balance = balance(now->right);
		}
	}
	
	
}

void insertNode(node*& aux, node*& now, node*& last){
	if(now == NULL){
		now = aux;
		now->left = NULL;
		now->right = NULL;
		if(last->right==NULL || last->left==NULL){
			heightchange = true;
		}else{
			last->balance = 0;
		}
	}else if(aux->value < now->value){//esquerda
		insertNode(aux, now->left, now);
		if(heightchange && !troquei){
			now->balance--;
		}
		if(now->balance==0){
			heightchange = false;
		}
	}else{
		insertNode(aux, now->right, now);
		if(heightchange && !troquei){
			now->balance++;
		}
		if(now->balance==0){
			heightchange = false;
		}

	}

	verifyAVL(now, last);
		
}

int main(){
	int num;
	scanf("%d", &num);
	
	root->value = num;
	root->left = NULL;
	root->right = NULL;
	root->balance = 0;

	while(scanf("%d", &num)!=EOF){
		heightchange = false;

		node* now = root;

		node* aux = new node;
		aux->value = num;
		aux->balance = 0;
		
		insertNode(aux, now, root);
	}

	return 0;
}
