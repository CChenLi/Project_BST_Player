#include <iostream>
#include "utility.h"
using namespace std;

card::card(string input){
	name = input;
	char s = input[0];
	if(s == 'c') {
		suit = 0;
	} else if (s == 'd'){
		suit = 1;
	} else if (s == 's'){
		suit = 2;
	} else if (s == 'h'){
		suit = 3;
	}
	string v = input.substr(2);
	if(v == "10"){
		value = 10;
	} else if(v == "j"){
		value = 11;
	} else if(v == "q"){
		value = 12;
	} else if(v == "k"){
		value = 13;
	} else if(v == "a"){
		value = 1;
	} else{
		value = stoi(v);
	}
	parent = 0;
	left = 0;
	right = 0;
}

card& card::operator=(const card& c){
	suit = c.suit;
	value = c.value;
	name = c.name;
	return *this;
}

bool operator==(const card& c1, const card& c2){
	return (c1.suit==c2.suit && c1.value==c2.value);
}

bool operator<(const card& c1, const card& c2){
	if(c1.suit==c2.suit){return c1.value<c2.value;
	} else{return c1.suit<c2.suit;}
}

bool operator>(const card& c1, const card& c2){
	return !(c1<c2) && !(c1==c2);
}

ostream& operator<<(ostream& out, const card& c){
	out<<c.name;
	return out;
}