

#include <iostream>
#include <stdlib.h>

using namespace std;

// Sequential search

int searchSeq(int vector[], int length, int key){
	
	int i, pos=-1;
	int numberOfConsults=0;
	
	// If pos==-1, so value not exist!
	
	for(i=0; i<length; i++){
		
		numberOfConsults++;
		
		if(vector[i]==key){
			
			pos = i;
			break;
			
		}
		
	}
	
	cout << "Number of Consults: " << numberOfConsults << endl;
	
	return pos;
	
}

int searchBin(int vector[], int length, int key){
	
	int half, rigth, left;
	int pos = -1;
	int numberOfConsults=0;
	
	rigth = length-1;
	left = 0;
	
	while(left<=rigth){
		
		numberOfConsults++;
		
		half = (left+rigth)/2;
		
		if(vector[half]==key){
			
			pos = half;
			break;
			
		}
		
		else if(key>vector[half]){
			
			left = half+1;
			
		}
		
		else{
			
			rigth = half-1;
			
		}
		
	}
	
	cout << "Number of Consults: " << numberOfConsults << endl;
	
	return pos;
	
}

int main(){
	
	
	int vector[] = {1, 2, 3, 4, 5, 6, 7, 8};
	
	int tam = 8;
	
	int keyToFind = 4, pos;
	
	pos = searchSeq(vector, tam, keyToFind);
	
	if(pos!=-1){
		
		cout << "Value found!" << endl;
		cout << "Position " << pos << " : " << vector[pos] << endl;
		
	}
	
	else{
		
		cout << "Value not found!" << endl;
		
	}
	
	pos = searchBin(vector, tam, keyToFind);
	// Only for ordered vector!
	
	if(pos!=-1){
		
		cout << "Value found!" << endl;
		cout << "Position " << pos << " : " << vector[pos] << endl;
		
	}
	
	else{
		
		cout << "Value not found!" << endl;
		
	}
	
	system("pause");
	
	return 0;
	
}
