#include "shop_struct.h"

int find(char * name){
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
	
	ifstream f(name);
	if (!f.is_open()){
		cout<<"Cannot open file."<<endl;
		return 1;
	}
	
	if (n == 1){
		cout<<"\n >Enter type: ";
		getline(cin, s);
		while(f.read((char *)&c1, sizeof(cosmetic))){
			if (s==c1.type) {
				k++;
				cout<<"Type: "<<c1.type<<"Color: "<<c1.color<<"Price: "<<c1.price<<"Place: "<<c1.place<<endl;
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 2){
		cout<<"\n >Enter color: ";
		getline(cin, s);
		while(f.read((char *)&c1, sizeof(cosmetic))){
			if (s==c1.color) {
				k++;
				cout<<"Type: "<<c1.type<<"Color: "<<c1.color<<"Price: "<<c1.price<<"Place: "<<c1.place<<endl;
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 3){
		cout<<"\n >Enter price: ";
		cin>>p;
		while(f.read((char *)&c1, sizeof(cosmetic))){
			if (c1.price == p) {
				k++;
				cout<<"Type: "<<c1.type<<"Color: "<<c1.color<<"Price: "<<c1.price<<"Place: "<<c1.place<<endl;
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else if (n == 4){
		cout<<"\n >Enter place: ";
		cin>>p;
		while(f.read((char *)&c1, sizeof(cosmetic))){
			if (c1.place == p) {
				k++;
				cout<<"Type: "<<c1.type<<"Color: "<<c1.color<<"Price: "<<c1.price<<"Place: "<<c1.place<<endl;
			}
		}
		if (k == 0)
			cout<<"  No products found."<<endl;
	}else {
		cout<<"  Please, enter a number from 1 to 4."<<endl;
		cin>>n;
	}
	f.close();
}
