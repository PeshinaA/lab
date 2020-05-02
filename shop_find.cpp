#include "shop_struct.h"

int find(char * name, cosmetic mass[], int size){
	int n;
	string s;
	int p;
	int k = 0;
	cout<<"[1]Find by type."<<endl;
	cout<<"[2]Find by color"<<endl;
	cout<<"[3]Find by price."<<endl;
	cout<<"[4]Find by place."<<endl;
	cout<<" >Enter the number: ";
	cosmetic c1;
	cin>>n;
	
	if (n == 1){
		cout<<"\n >Enter type: ";
		getline(cin, s);
		for(int i =0; i<size; i++){
			if (s==mass[i].type) {
				k++;
				cout<<"Type: "<<mass[i].type<<"Color: "<<mass[i].color<<"Price: "<<mass[i].price<<"Place: "<<mass[i].place<<endl;
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 2){
		cout<<"\n >Enter color: ";
		getline(cin, s);
		for(int i =0; i<size; i++){
			if (s==c1.color) {
				k++;
				cout<<"Type: "<<mass[i].type<<"Color: "<<mass[i].color<<"Price: "<<mass[i].price<<"Place: "<<mass[i].place<<endl;
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 3){
		cout<<"\n >Enter price: ";
		cin>>p;
		for(int i =0; i<size; i++){
			if (mass[i].price == p) {
				k++;
				cout<<"Type: "<<mass[i].type<<"Color: "<<mass[i].color<<"Price: "<<mass[i].price<<"Place: "<<mass[i].place<<endl;
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 4){
		cout<<"\n >Enter place: ";
		cin>>p;
		for(int i =0; i<size; i++){
			if (mass[i].place == p) {
				k++;
				cout<<"Type: "<<mass[i].type<<"Color: "<<mass[i].color<<"Price: "<<mass[i].price<<"Place: "<<mass[i].place<<endl;
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else {
		cout<<"  Please, enter a number from 1 to 4."<<endl;
		cin>>n;
	}
	f.close();
	menu(name, mass, size);
}
