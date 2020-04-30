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
			size++;
			break;
		case 2:
			pprint(name);
			break;
		case 3:
			rremove(name, mass, size);
			break;
		case 4:
			find(name);
			break;
		case 5:
			clear(name);
			break;
		case 6:
			cout<<"  Goodbye."<<endl;
			exit(0);

		default:
			cout<<"  Please, enter the number for 1 to 5."<<endl;
			break;
	}
}

void clear(char * name){
	ofstream f(name, ios_base::trunc);
	f.close();
}

int add(char * name, cosmetic mass[], int size){
	cout<<"   Please enter information."<<endl;
	cosmetic c;
        cout<<"Type: ";
	getline(cin, c.type);
	cout<<"Color: ";
	getline(cin, c.color);
	cout<<"Price: ";
	cin>>c.price;
	cout<<"Place: ";
	cin>>c.place;

	mass[size] = c;
	ofstream f(name);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	f.write((char *)&mass[size], sizeof(cosmetic));
	f.close();
	cout<<"  Product added."<<endl;
}

int pprint(char * name){
	cosmetic c2;
	ifstream f(name);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	while(f.read((char *)&c2, sizeof(cosmetic))){
		cout<<"Type: "<<c2.type<<"Color: "<<c2.color<<"Price: "<<c2.price<<"Place: "<<c2.place<<endl;
	}
	f.close();
}
