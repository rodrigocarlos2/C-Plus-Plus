

#include <iostream>

// Author: Rodrigo Carlos.
// Date: 2016-05-13.

using namespace std;

void read(int *n, int *d){
	
	cout << "Write the value of n: ";
	cin >> *n;
	
	cout << "Write the value of d: ";
	cin >> *d;
	
}

int calc(int n, int d){
	
	int result;
	
	try{
		
		if(d==0){
			throw "Divided by 0";
		}
		
		result = n/d;
		
	}
	catch(const char *msg){
		cout << "Exception: " << msg << endl;
		result = n+d;
	}
	
	return result;
	
}

void show(int result){
	
	cout << "Result: " << result << endl;
	
}

void pause(){
	
	getchar();getchar();
	
}

void clear(){
	
	system("cls");
	
}

int main(){
	
	int n, d, result;
	
	read(&n, &d);
	
	result = calc(n, d);
	
	show(result);
	
	pause();
	
	clear();
	
	return 0;
	
}
