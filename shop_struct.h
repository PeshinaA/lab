#include <iostream>
#include <fstream>
#include <string>
#include <new>
#include <cstdlib>
using namespace std;
class cosmetic{
public:
//	cosmetic();
	int place;
	int price;
	string type;
	string color;
};
void menu(char * name, cosmetic mass[], int size);
int add(char * name, cosmetic mass[], int size);
int pprint(char * name);
void clear(char * name);
int rremove(char * name, cosmetic mass[], int size);
int find(char * name);

