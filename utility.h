

#ifndef ULTILITY_H
#define ULTILITY_H
#include <iostream>
using namespace std;

class card{
public:
	string name;
	int suit;
	int value;
	card* parent;
	card* left;
	card* right;
	card(string input); //constructor
	card& operator=(const card& c);
	friend bool operator==(const card& c1, const card& c2);
	friend bool operator<(const card& c1, const card& c2);
	friend bool operator>(const card& c1, const card& c2);
	friend ostream& operator<<(ostream& out, const card& c);
};

#endif