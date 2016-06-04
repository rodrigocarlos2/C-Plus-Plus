

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

void merge(int v[], int aid[], int begin1, int begin2, int end2){
	
	int end1 = begin2-1;
	int position = 0, i;
	
	int beginTmp1 =  begin1;
	
 	while(beginTmp1<=end1 && begin2<=end2){
		
		if(v[beginTmp1]<v[begin2]){
			
			aid[position] = v[beginTmp1];
			beginTmp1++;
			position++;
			
		}
		
		else{
			aid[position] = v[begin2];
			position++;
			begin2++;
		}
		
	}
	
	while(beginTmp1<=end1){
		
		aid[position] = v[beginTmp1];
		position++;
		beginTmp1++;
		
	}
	
	while(begin2<=end2){
		
		aid[position] = v[begin2];
		position++;
		begin2++;
		
	}
	
	for(i=0; i<position; i++){
		v[i+begin1] = aid[i];
	}
	
}

void mergeSort(int *v, int aid[], int left, int rigth){
	
	int half, index;
	
	if(v==NULL)
		return;
	
	if(left<rigth){
		
		half = (left+rigth)/2;
		
		mergeSort(v, aid, left, half);
		mergeSort(v, aid, half+1, rigth);
		
		merge(v, aid, left, half+1, rigth);
		
	}
	
}

int pot(int b, int e){
	
	if(e<2){
		return b;
	}
	else{
		return b*pot(b, e-1);
	}
	
}

int numberRandom(){
	
	srand(time(NULL));
	
	return rand()%200;
	
}

void completeRandom(int v[], int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		v[i] = numberRandom()+tam-i;
		
	}
	
}

void setLanguage(){
	
	setlocale(LC_ALL, "Portuguese");
	
}

void show(int v[], int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		printf("%d position: %d\n", i+1, v[i]);
	}
	
}

int main(){
	
	float begin, end;
	float timeComplet;
	int *v;
	
	int e = 3;
	// Expoente
	int b = 2;
	// Base
	
	setLanguage();
	
	while(e<=20){
		
		int *v2;
		
		int result = pot(b, e);
		
		v = (int *)malloc(result*sizeof(int));
		v2 = (int *)malloc(result*sizeof(int));
		
		if(v==NULL || v2==NULL){
			printf("Stack overflow!\n");
			exit(1);
		}
		
		completeRandom(v, result);
		
		//show(v, result);
		
		printf("Ordenando %d numeros\n", result);
		
		printf("Pode-se começar? [ENTER]\n");
		
		getchar();
		
		begin = GetTickCount();
		
		mergeSort(v, v2, 0, result-1);
		
		end = GetTickCount();
		
		printf("Tempo de execução (millisegundos) : %.4f\n", end-begin);
		
		e++;
		
		free(v);
		free(v2);
		
		getchar();
		
	}
	
	system("pause");
	
	return 0;
	
}
