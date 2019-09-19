#ifndef Planet_H
#define Planet_H 
#include <string> 
#include <fstream>
using namespace std;
class Planet
{
private:
	string name;
	float diam;
	float mass;
	float distance;
public:
	Planet();
	Planet(string name, float diam, float mass, float distance);
	~Planet();
	void input();
	void output();
	float getdistance();
	void moddistance();
	void diskOut(ofstream& fout);
	void diskIn(ifstream& fin);
	string getname();
};
#endif // Planet_H