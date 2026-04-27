#include <iostream>
using namespace std;

int main () {
	
	int edad;
	
	while (true){
	}
	
	cout<<"Ingrese su edad: ";
		cin>>edad;
	
	if (edad >=60) {
		
		cout<<"Usted es adulto mayor";
	}
	else if(edad >= 18) {
		cout<<"usted es adulto";
	}
		else if(edad >= 13) {
		cout<<"usted es adolescente";
	}
		else {
		cout<<"usted es un niño";
	}
	
	return 0;
}
	
	
