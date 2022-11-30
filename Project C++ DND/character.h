#include <iostream>
#include <iomanip>
#include <locale>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;
#pragma once
class Character
{
protected:
	string leader_name;
	string leader_class;
	string leader_race;

public:
	Character() : leader_name(""), leader_class(""), leader_race("") {};

	string get_leader_name();
	void set_leader_name(string name);
	string get_leader_class();
	void set_leader_class(string classx);
	string get_leader_race();
	void set_leader_race(string race);

	void display_info();
	void initialize();

};

