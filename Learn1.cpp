

#include <iostream>

using namespace std;

int main(){
	
	int i;
	
	for(i=0; i<1000; i++){
		
		if(i==100){
			
			break;
			continue;
			
		}
		
	}
	
	// What's is the value of i?
	cout << "Value of i: " << i << endl;
	
	for(i=0; i<1000; i++){
		
		if(i==100){
			
			continue;
			break;
			
		}
		
	}
	
	// What's is the value of i?
	cout << "Value of i: " << i << endl;
	
	return 0;
	
}
