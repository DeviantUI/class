#include "pch.h"
#include "Planet.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;
	/*Класс Planet содержит информацию о планете солнечной системы.
	Поля класса: название, диаметр, масса и расстояние от Солнца в тысячах километров.
	Метод возвращает расстояние от Солнца в милях.
	Найти планету, которая имеет максимальное расстояние от Солнца в милях.*/

int compare(const void* s1, const void* s2) {
	if (((Planet*)s1)->getname() < ((Planet*)s2)->getname())
		return -1;
	else if (((Planet*)s1)->getname() > ((Planet*)s2)->getname())
		return 1;
	else return 0;
}
int main()
{    
	setlocale(LC_ALL,"RUS");
	int n; int p;
	Planet* st = NULL;
		cout << "Введите кол-во планет: ";
		cin >> n;
		st = new Planet[n];
		cout << "Введите информацию о планетах:\n ";
		for (int i = 0; i < n; i++)
			st[i].input();
		qsort(st, n, sizeof(Planet), compare);
		cout << "Список планет: \n";
		cout << left << setw(15) << "Название" << setw(15) << "Диаметр" << setw(10) << "Масса" << setw(10) << "Дистанция" << endl;
		for (int i = 0; i < n; i++)
		{
			st[i].moddistance();
			st[i].output();
		}
		delete [] st;
	cout << "\n";
	system("pause");
}
