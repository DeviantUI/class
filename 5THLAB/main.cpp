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
	int n; int p; bool fl = true;
	Planet* st = NULL;
	try
	{
		do
		{
			cout << "Введите 1 или 2: ";
			cout << "\n1 - Ввод списка планет и запись в файл";
			cout << "\n2 - Чтение списка планет из файла";
			cout << "\n>";
			cin >> p;
			cin.get();
			if (p == NULL)
			{
				throw "\nОшибка формата!";
			}
			if (p == 1)
			{
				fl = false;
				cout << "Введите кол-во планет: ";
				cin >> n;
				if (n == NULL)
				{
					throw "\nОшибка формата!";
				}
				st = new Planet[n];
				cout << "Введите информацию о планетах:\n ";
				for (int i = 0; i < n; i++)
					st[i].input();
				ofstream fout("D:\\Planet.txt");
				fout << n << endl;
				for (int i = 0; i < n; i++)
					st[i].diskOut(fout);
				fout.close();
			}
			if (p == 2)
			{
				fl = false;
				char file_name[10];
				cout << "Введите имя файла: ";
				ifstream fin("D:\\Planet.txt");
				if (!fin)
					throw "\nОшибка: Файл не найден!";
				else {
					fin >> n;
					if (n == NULL)
					{
						throw "\nОшибка в файле: Ошибка формата!";
					}
					st = new Planet[n];
					for (int i = 0; i < n; i++)
						st[i].diskIn(fin);
					fin.close();
				}
			}
		} while (fl);
		qsort(st, n, sizeof(Planet), compare);
		cout << "Список планет: \n";
		cout << left << setw(15) << "Название" << setw(15) << "Диаметр" << setw(10) << "Масса" << setw(10) << "Дистанция" << endl;
		for (int i = 0; i < n; i++)
		{
			st[i].moddistance();
			st[i].output();
		}
		float max = st[0].getdistance();
		for(int i = 0; i < n; i++)
			if (st[i].getdistance() > max)
				max = st[i].getdistance();
		cout << "Максимально удаленная планета: \n";
		for(int i = 0; i<n; i++)
			if (st[i].getdistance() == max) {
				st[i].output();
			}
		delete [] st;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "\n";
	system("pause");
}
