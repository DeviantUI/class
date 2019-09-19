#include "pch.h"
#include "Planet.h"
#include <iostream>
#include <iomanip>
using namespace std;
Planet::Planet()
{
	this->name = "noname";
	this->diam = 11;
	this->mass = 11;
	this->distance = 11;
}
Planet::Planet(string name, float diam, float mass, float distance)
{
	this->name = name;
	this->diam = diam;
	this->mass = mass;
	this->distance = distance;
}
Planet::~Planet(){}
void Planet::input()
{
	cin.get();
	cout << "\nНазвание: ";
	getline(cin, name);
	cout << "Диаметр: ";
	bool fl = true; cin.get();
	do
	{
		cin >> diam;
		if (diam >= 0)
			fl = false;
		else cout << "Диаметр должна быть не отрицательной \nПовторите ввод диаметра:\n";
	} while (fl);
	if (diam == NULL)
	{
		throw "\nОшибка формата!";
	}
	cout << "Масса: ";
	fl = true; cin.get();
	do
	{
		cin >> mass;
		if (mass >= 0)
			fl = false;
		else cout << "Масса должна быть не отрицательной \nПовторите ввод массы:\n";
	} while (fl);
	if (mass == NULL)
	{
		throw "\nОшибка формата!";
	}
	cout << "Дистанция: ";
	fl = true; cin.get();
	do
	{
		cin >> distance;
		if (distance >= 0)
			fl = false;
		else cout << "Расстояние должна быть не отрицательной \nПовторите ввод дистаниции:\n";
	} while (fl);
	if (distance == NULL)
	{
		throw "\nОшибка формата!";
	}
	
}
void Planet::output()
{
	cout << left << setw(15) << name;
	cout << setw(15) << diam;
	cout << setw(10) << mass;
	cout << setw(10) << distance;
	cout << endl;
}
void Planet::moddistance()
{
	distance = distance / 1.6f / 1000;
}
float Planet::getdistance()
{
	return distance;
}
void Planet::diskOut(ofstream& fout)
{
	fout << name << endl;
	fout << diam << endl;
	fout << mass << endl;
	fout << distance << endl;
} void Planet::diskIn(ifstream & fin)
{
	fin.get();
	getline(fin, name);
	fin.get();
	fin >> diam;
	if (diam < 0)
		throw "Ошибка в содержимом файла: Диаметр не может быть отрицательной";
	if (diam == NULL)
	{
		throw "\nОшибка в файле: Ошибка формата!";
	}
	fin.get();
	fin >> mass;
	if (mass < 0)
		throw "Ошибка в содержимом файла: Масса не может быть отрицательной";
	if (mass == NULL)
	{
		throw "\nОшибка в файле: Ошибка формата!";
	}
	fin.get();
	fin >> distance;
	if (distance < 0)
		throw "Ошибка в содержимом файла: Расстояние не может быть отрицательной";
	if (distance == NULL)
	{
		throw "\nОшибка в файле: Ошибка формата!";
	}
	
}
string Planet::getname()
{
	return name;
}