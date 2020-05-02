#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "class.h"
using namespace std;


int main()
{
    cout << "Добро пожаловать в компанию 'ФырФырФыр'!" << endl;
    cout << "Мы предоставляем услуги по выдаче в аренду спортивного инвентаря" << endl;
    int n;
    int k = 100;
    list *arr;
    arr = new list[k];
    menu(n, arr);
    return 0;
}

void menu(int &n, list arr[])
{
    int number;
    cout << "[1] Создать файл " << endl;
    cout << "[2] Просмотреть весь инвентарь на складе и их наличие" << endl;
    cout << "[3] Просмотр инвентаря для выбранной категории" << endl;
    cout << "[4] Добавить вид инвентаря" << endl;
    cout << "[5] Удалить вид инвентаря" << endl;
    cout << "[6] Выдать в прокат" << endl;
    cout << "[7] Вернуть на склад" << endl;
    cout << "[8] Найти инвентарь и вывести информацию о нем" << endl;
    cout << "[9] Выход" << endl;
    cout << "Введите свой выбор:" << endl;
    cin >> number;
        if(number<1||number>9)
            {
                cout << "Некорректный ввод. Попробуйте еще раз: \n";
                menu(n,arr);
            }
        else 
        {
            switch (number)
                {
                case 1:
                    {
                        create(n, arr);
                        break;
                    }
                case 2:
                    {
                        show(n, arr);
                        break;
                    }
                case 3:
                    {
                        showpart(n, arr);
                        break;
                    }
                case 4:
                    {
                        add(n, arr);
                        break;
                    }
                case 5:
                    {
                        del(n, arr);
                        break;
                    }
                case 6:
                    {
                        take(n, arr);
                        break;
                    }
                case 7:
                    {
                        back(n, arr);
                        break;
                    }
                case 8:
                    {
                        find(n, arr);
                        break;
                    }
                case 9:
                    {
                    delete[] arr;
                    exit(0);
                    }
        }
    }
}