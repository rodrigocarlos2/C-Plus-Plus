

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct lista{
	int info;
	struct lista *next;
};

typedef struct lista Lista;

Lista* begin(){
	
	return NULL;
	
}

Lista* insert(Lista *root, int info){
	
	Lista *newRoot = (Lista *)malloc(sizeof(Lista));
	
	newRoot->info = info;
	newRoot->next = root;
	
	return newRoot;
	
}

void liberation(Lista *root){
	
	Lista *aid = root;
	
	while(aid!=NULL){
		
		Lista *tmp = aid->next;
		
		free(aid);
		
		aid = tmp;
		
	}
	
}

void show(Lista *root){
	
	Lista *aid = root;
	
	while(aid!=NULL){
		
		cout << "Information: " << aid->info << endl;
		
		aid = aid->next;
		
	}
	
}

Lista* remove(Lista *root, int info){
	
	Lista *ant = root;
	
	Lista *aid = root->next;
	
	while(ant!=NULL){
		
		if(ant->info==info){
			
			Lista *newRoot = aid;
			
			return newRoot;
			
		}
		
		else if(aid->info==info){
			
			ant->next = aid->next;
			
			return root;
			
		}
		
		ant = aid;
		aid = aid->next;
		
	}
	
	return root;
	
}

int main(){
	
	
	Lista *root;
	
	root = begin();
	
	root = insert(root, 4);
	
	root = insert(root, 6);
	
	root = insert(root, 8);
	
	show(root);
	
	root = remove(root, 8);
	
	cout << endl;
	
	show(root);
	
	liberation(root);
	
	return 0;
	
}
