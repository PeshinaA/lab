#include "shop_struct.h"

int main(int argc, char* argv[]){
	cout<<" Welcome to the cosmetic shop!"<<endl;
//	cout<<" >Enter file name: "<<endl;

	char *name = argv[1];
	int size = 0;
	ifstream f(name);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	cosmetic c;
	while(f.read((char *)&c, sizeof(cosmetic))){
		size++;
	}
	f.close();

	cosmetic * mass = new cosmetic[size];

	int number;
	do{
		menu(name, mass, size);
	} while (number !=6);
	
	delete [] mass;

	return 0;
}
