

#include <iostream>
#include <string.h>

using namespace std;

// People is a abstract class!

class People{
	
	public:
	
		int getAge();
		
		void setAge(int age2);
		
		void getName(char name2[]);
		
		void setName(char name2[]);
		
		int age;
		char name[30];
	
};

class Fisic: People{
	
	public:
		
		int getAge(){
			return age;
		}
		
		int setAge(int age2){
			age = age2;
		}
		
		void getName(char name2[]){
			strcpy(name2, name);
		}
		
		void setName(char name2[]){
			strcpy(name, name2);
		}
		
		int getCpf(){
			return cpf;
		}
		
		void setCpf(int cpf2){
			cpf = cpf2;
		}
		
		void show(){
			
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "CPF: " << cpf << endl;
		}
		
	private:
		
		int cpf;	
	
};

int main(){
	
	Fisic f1;
	
	f1.setAge(17);
	
	f1.setCpf(19889);
	
	f1.setName("Rodrigo");
	
	f1.show();
	
	return 0;
}
