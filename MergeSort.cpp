


#include <iostream>
#include <cstdlib>

using namespace std;

void merge(int v[], int aux[], int begin1, int begin2, int end2){
	
	int end1 = begin2-1;
	
	int i, beginTmp1 = begin1;
	int index = 0;
	
	while(beginTmp1<=end1 && begin2<=end2){
		
		if(v[beginTmp1]<v[begin2]){
			
			aux[index++] = v[beginTmp1++];
			
		}
		else{
			
			aux[index++] = v[begin2++];
			
		}
		
	}
	
	while(beginTmp1<=end1){
		
		aux[index++] = v[beginTmp1++];
		
	}
	
	while(begin2<=end2){
		
		aux[index++] = v[begin2++];
		
	}
	
	for(i=0; i<index; i++){
		
		v[i+begin1] = aux[i];
		
	}
	
}

void mergeSort(int *v, int *aux, int left, int rigth){
	
	int half = (left+rigth)/2;
	
	if(v==NULL)
		return;
		
	if(left<rigth){
		
		mergeSort(v, aux, left, half);
		mergeSort(v, aux, half+1, rigth);
		
		merge(v, aux, left, half+1, rigth);
		
	}
	
}

int main(){
	
	int v[] = {3, 1, 7, 2, 4};
	int aux[5], i;
	
	mergeSort(v, aux, 0, 4);
	
	for(i=0; i<5; i++){
		cout << v[i] << endl;
	}
	
	system("pause");
	
	return 0;
}
