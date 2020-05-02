#include "shop_struct.h"

int main(int argc, char* argv[]){
	cout<<" Welcome to the cosmetic shop!"<<endl;

	char *name = argv[1];
	int size = 0;
/*	ifstream f(name);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	cosmetic c;
	while(f.read((char *)&c, sizeof(cosmetic))){
		size++;
	}
	f.close();
*/
	cosmetic * mass = new cosmetic[size];

	menu(name, mass, size);
	

	return 0;
}
