#include "shop_struct.h"

int rremove(char * name, cosmetic mass[], int size){

	cout<<" >Enter product: "<<endl;
	string type, color;
	int price, place;
	cout<<"Type: ";
	getline(cin, type);
	cout<<"Color: ";
	getline(cin, color);
	cout<<"Price: ";
	cin>>price;
	cout<<"Place: ";
	cin>>place;
	int i;
	
	ifstream f(name);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}

	int rm_i, k = 0;
	for(i = size-1; i >= 0; i--){
		if ((type==mass[i].type) && (color==mass[i].color) && (price == mass[i].price) && (place == mass[i].place)){
			rm_i = i;
			k++;
		}
	}
	if(k != 0){
		ofstream newf(name, ios::trunc);
		if (!f.is_open()){
			cout<<"Cannot open file."<<endl;
			return 1;
		}
		
		for(i = 0; i<(size-1); i++){
			if (i != rm_i)
				newf<<mass[i].type;
				newf<<mass[i].color;
				newf<<mass[i].price;
				newf<<mass[i].place;
			}
		newf.close();
		size--;
		cout<<" Product removed."<<endl;
	}else
		cout<<" Product not found."<<endl;
	menu(name, mass, size);
}
