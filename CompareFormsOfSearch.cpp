

// Let go compare the cost of a search binary and a sequential in C++

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void seqSearch(int v[], int tam, int value){
	
	int i;
	int countLoops=0, countComparations=0;
	
	for(i=0; i<tam; i++){
		
		countLoops++;
		
		if(v[i]==value){
			countComparations++;
			break;
		}
		else{
			countComparations++;
		}
		
	}
	
	cout << "Total Cost in Worse Case - Sequential Search\n" << endl;
	cout << "Need be in order: NO\n" << endl;
	cout << "Size of Vector: " << tam << endl;
	cout << "Value found: " << value << endl;
	cout << "Quantity of Loops: " << countLoops << endl;
	cout << "Quantity of Comparations: " << countComparations << endl;
}

void binSearch(int v[], int tam, int value){
	
	int rigth, left, half;
	
	int countLoop = 0;
	int countComparations = 0;
	
	left = 0;
	rigth = tam-1;
	
	while(left<=rigth){
		
		countLoop++;
		
		half = (left+rigth)/2;
		
		if(v[half]==value){
			countComparations++;
			break;
		}
		
		else if(value>v[half]){
			left = half+1;
			countComparations += 2;
		}
		
		else{
			rigth = half-1;
			countComparations += 2;
		}
		
	}
	
	cout << "Total Cost in Worse Case - Binary Search\n" << endl;
	cout << "Need be in order: YES\n" << endl;
	cout << "Size of Vector: " << tam << endl;
	cout << "Value found: " << value << endl;
	cout << "Quantity of Loops: " << countLoop << endl;
	cout << "Quantity of Comparations: " << countComparations << endl;
	
}

int pot(int b, int e){
	
	if(e<2){
		return b;
	}
	else
		return b*pot(b, e-1);
	
}

void insertRange(int *min, int *max){
	
	cout << "Write the minimum length of list: " << endl;
	cin >> *min;
	cout << "Write the maximun length of list: " << endl;
	cin >> *max;
	
}

void complete(int v[], int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		v[i] = i+1;
		
	}
	
}

void show(int v[], int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		cout << v[i];
		
	}
	
	cout << endl;
}

int main(){
	
	int i=0, min, max;
	int *v, value;
	
	insertRange(&min, &max);
	
	for(i=min;  i<=max; i++){
		
		v = (int *)malloc(i*sizeof(int));
		
		if(v==NULL){
			cout << "Program interrupted!\n" << endl;
			exit(1);
		}
		
		complete(v, i);
		
		value = i;
		
		cout << endl;
		show(v, i);
		cout << endl;
		
		cout << endl;
		
		seqSearch(v, i, value);
		
		cout << endl;
		
		binSearch(v, i, value);
		
		free(v);
		
	}
	
	cout << "End of software!\n";
	
	system("pause");
	
}
