

#include <iostream>
#include <string.h>

using namespace std;

class Pokemon{
	
	public:
		
		// Attributes
		char name[20];
		
		void getName(char name2[]);
		
		void setName(char name2[]);
	
};

class Pikachu: Pokemon{
	
	public:
		
		void getName(char name2[]){
			strcpy(name2, name);
		}
		
		void setName(char name2[]){
			strcpy(name, name2);
		}
		
		float getHeigth(){
			return heigth;
		}
		
		void setHeigth(float heigth2){
			heigth = heigth2;
		}
		
		void show(){
			
			cout << "Name: " << name << endl;
			cout << "Heigt: " << heigth << endl;
		}
		
	private:
		
		float heigth;
	
};

int main(){
	
	Pikachu *p = new Pikachu;
	
	p->setName("Paco");
	p->setHeigth(1.90);
	
	p->show();
	
	delete p;
	
	return 0;
}
