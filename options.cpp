#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "class.h"
#include <fstream>
using namespace std;

void create(int &n, list arr[])
{
    char ref[1];
    cout << "Введите количество инвентаря: ";
    n = CorInput(20);
        for (int i = 0; i < n; i++)
            {
                cin.getline(ref, 1);
                cout << "Введите категорию: ";
                cin.getline(arr[i].category, 20);
                cout << "Введите инвентарь: ";
                cin.getline(arr[i].inventory, 20);
                cout << "Введите количество в прокате: ";
                cin >> arr[i].onhand;
                cout << "Введите количество на складе: ";
                cin >> arr[i].store;
            }
    ofstream f("baza.txt");
        for (int i = 0; i < n; i++)
            {
                f << arr[i].category;
                f << arr[i].inventory;
                f << arr[i].onhand;
                f << arr[i].store;
            }
    f.close();
    menu(n, arr);
}



void show(int &n, list arr[])
{
    ifstream f("baza.txt");
        for (int i = 0; i < n; i++)
            {
                cout << "Категория: " << arr[i].category << endl;
                cout << "Инвентарь: " << arr[i].inventory << endl;
                cout << "В прокате: " << arr[i].onhand << endl;
                cout << "На складе: " << arr[i].store << endl << endl;
            }
    menu(n, arr);
}



void showpart(int &n, list arr[])
{
    char ref[1];
    char last[20];
    cin.getline(ref, 1);
    cout << "Введите категорию: ";
    cin.getline(last, 20);
    ifstream f("baza.txt");
        for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].category, last) == 0)
                    {
                        cout << "Категория: " << arr[i].category << endl;
                        cout << "Инвентарь: " << arr[i].inventory << endl;
                        cout << "В прокате: " << arr[i].onhand << endl;
                        cout << "На складе: " << arr[i].store << endl << endl;
                    }
            }
    menu(n, arr);
}



void add(int &n, list arr[])
{
    int j;
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите количество инвентаря для добавления: ";
    j = CorInput(20);
    ofstream f("baza.txt", ios::app);
        for (int i = n; i < n + j; i++)
            {
                cin.getline(ref, 1);
                cout << "Введите категорию: ";
                cin.getline(arr[i].category, 20);
                cout << "Введите инвентарь: ";
                cin.getline(arr[i].inventory, 20);
                cout << "Введите количество в прокате: ";
                arr[i].onhand = CorInput(1000);
                cout << "Введите количество на складе: ";
                arr[i].store = CorInput(1000);
            }
        for (int i = n; i < n + j; i++)
            {
                f << arr[i].category;
                f << arr[i].inventory;
                f << arr[i].onhand;
                f << arr[i].store;
            }
    f.close();
    n += j;
    menu(n, arr);
}



void take(int &n, list arr[])
{
    int o;
    char last[20];
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите инвентарь: ";
    cin.getline(last, 20);
    cout << "Введите количество инвентаря: ";
    o = CorInput(20);
    ofstream f("baza.txt", ios::trunc);
        for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].inventory, last) == 0)
                    {
                        if (arr[i].store < o)
                            {
                            cout << "Недостаточно товара на складе. Ошибка операции \n";
                            break;
                            }
                        arr[i].onhand += o;
                        arr[i].store -= o;
                        f << arr[i].category;
                        f << arr[i].inventory;
                        f << arr[i].onhand;
                        f << arr[i].store;
                    }
                else
                    {
                        f << arr[i].category;
                        f << arr[i].inventory;
                        f << arr[i].onhand;
                        f << arr[i].store;
                    }
            }
    f.close();
    menu(n, arr);
}
    
    
    
void back(int &n, list arr[])
{
    int o;
    char last[20];
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите инвентарь: ";
    cin.getline(last, 20);
    cout << "Введите количество инвентаря: ";
    o = CorInput(20);
    ofstream f("baza.txt", ios::trunc);
        for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].inventory, last) == 0)
                    {
                        if (arr[i].onhand < o)
                            {
                                cout << "В прокате нет такого количества инвентаря. Ошибка операции: \n";
                                break;
                            }
                        arr[i].onhand -= o;
                        arr[i].store += o;
                        f << arr[i].category;
                        f << arr[i].inventory;
                        f << arr[i].onhand;
                        f << arr[i].store;
                    }
                else
                    {
                        f << arr[i].category;
                        f << arr[i].inventory;
                        f << arr[i].onhand;
                        f << arr[i].store;
                    }
            }
    f.close();
    menu(n, arr);
}




void find(int &n, list arr[])
{
    char last[20];
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите инвентарь: ";
    cin.getline(last, 20);
    ifstream f("baza.txt");
        for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].inventory, last) == 0)
                    {
                        cout << "Категория: " << arr[i].category << endl;
                        cout << "Инвентарь: " << arr[i].inventory << endl;
                        cout << "В прокате: " << arr[i].onhand << endl;
                        cout << "На складе: " << arr[i].store << endl << endl;
                        break;
                    }
            }
    menu(n, arr);
}




void del(int &n, list arr[])
{
    char last[20];
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите инвентарь: ";
    cin.getline(last, 20);
    ofstream f("baza.txt", ios::trunc);
        for (int z = 0; z < n; z++)
            {
                if (strcmp(arr[z].inventory, last) == 0)
                    {
                        for (int y = z+1; y < n+1; y++)
                            {
                                *arr[y-1].category = *arr[y].category;
                                *arr[y-1].inventory = *arr[y].inventory;
                                arr[y-1].onhand = arr[y].onhand;
                                arr[y-1].store = arr[y].store;
                            }
                        *arr[n].category =0;
                        *arr[n].inventory =0;
                        arr[n].onhand = 0;
                        arr[n].store = 0;
                        n--;
                    }
            }
        for (int y = 0; y < n+1; y++)
            {
                f << arr[y].category;
                f << arr[y].inventory;
                f << arr[y].onhand;
                f << arr[y].store;
            }
    f.close();
    menu(n, arr);
}

int StrToInt(char* str){
int i=0;
int flag=0;
if(strlen(str)>6)
return 0;
while(str[i]!=0){
if(str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'||str[i]=='0')
i++;
else{
flag=1;
break;
}
}
if(flag==0)
return atoi(str);
else
return 0;
}


int CorInput(int max){
char str[100];
int inp;
while(1){
scanf("%s",str);
inp=StrToInt(str);
if((inp!=0)&&(inp<=max)&&(inp>0))
break;
cout <<"Введено некорректное значение. Повторите попытку: \n";
}
return inp;
}