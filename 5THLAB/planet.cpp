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
	cin >> diam;
	cout << "Масса: ";
	cin >> mass;
	cout << "Дистанция: ";
	cin >> distance;
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

	
}
string Planet::getname()
{
	return name;
}
