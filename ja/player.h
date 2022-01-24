#pragma once
#include "j.h"
class player
{	
public:
	
	player( string n,string s) :name(n),s(stoi(s)){
		
	}
	player(string n, int s) :name(n), s(s) {

	}
	int gets() { return s; }
	bool comp(player a);
	string getn() { return name; }
private:
	string name;
	int s;
};

