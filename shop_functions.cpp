#include "shop_struct.h"

void menu(char * name, cosmetic mass[], int size){

	cout<<"  What do you want to do?"<<endl;
	cout<<"[1] Add product."<<endl;
	cout<<"[2] Print all products."<<endl;
	cout<<"[3] Remove product."<<endl;
	cout<<"[4] Find product."<<endl;
	cout<<"[5] Clear file."<<endl;
	cout<<"[6] Exit."<<endl;
	cout<<" >Enter the number: ";
	
	int number;
	cin>>number;
	switch(number){
		case 1:
			add(name, mass, size);
			break;
		case 2:
			pprint(name, mass, size);
			break;
		case 3:
			rremove(name, mass, size);
			break;
		case 4:
			find(name, mass, size);
			break;
		case 5:
			clear(name, mass, size);
			break;
		case 6:
			delete [] mass;
			cout<<"  Goodbye."<<endl;
			exit(0);

		default:
			cout<<"  Please, enter the number for 1 to 5."<<endl;
			break;
	}
}

void clear(char * name, cosmetic mass[], int size){
	ofstream f(name, ios_base::trunc);
	f.close();
	menu(name, mass, size);
}

int add(char * name, cosmetic mass[], int size){
	cout<<"   How many: ";
	int n;
	cin>>n;
	cout<<"   Please enter information."<<endl;
	
	for(int i = 0; i<n; i++){
        	cout<<"Type: ";
		getline(cin, mass[i].type);
		cout<<"Color: ";
		getline(cin, mass[i].color);
		cout<<"Price: ";
		cin>>mass[i].price;
		cout<<"Place: ";
		cin>>mass[i].place;
		size++;
	}
	
	ofstream f(name);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	for(int i = 0; i<n; i++){
		f<<mass[i].type;
		f<<mass[i].color;
		f<<mass[i].price;
		f<<mass[i].place;
	}
	
	f.close();
	cout<<"  Product added."<<endl;
	menu(name, mass, size);
}

int pprint(char * name, cosmetic mass[], int size){
	ifstream f(name);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	for(int i = 0; i<size; i++){
		cout<<"Type: "<<mass[i].type<<"Color: "<<mass[i].color<<"Price: "<<mass[i].price<<"Place: "<<mass[i].place<<endl;
	}
	f.close();
	menu(name, mass, size);
}
