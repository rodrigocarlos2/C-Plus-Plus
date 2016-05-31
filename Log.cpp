

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void read(float *base, float *argument){
	
	cout << "Write the base: " << endl;
	
	cin >> *base;
	
	cout << "Write the argument: " << endl;
	
	cin >> *argument;
	
}

float calc(float b, float a){
	
	return log10(a) / log10(b);
	
}

int menu(){
	
	int r;
	
	printf("1. Calc\n");
	printf("2. Exit\n");
	
	scanf("%d", &r);
	
	return r;
	
}

void clear(){
	
	#ifdef LINUX
	system("clear");
	
	#elsif defined WIN32 || defined (_WIN32) || defined win32
	system("cls");
	
	#else
	system("cls");
	
	#endif
	
}

int main(){
	
	int op;
	float a, b, result;
	
	do{
		
		op = menu();
		
		switch(op){
			
			case 1:
				
				read(&b, &a);
				
				result = calc(b, a);
				
				printf("Result: %.4f\n", result);
				
				break;
			
		}
		
		getchar();getchar();
		clear();
		
	}while(op!=2);
	
	system("pause");
	
	return 0;
	
}
