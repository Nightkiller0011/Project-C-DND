
#include "character.h"


#pragma once
class Party
{
protected:
	int number;
	string party_name;
	int member_count;
	static int next_party;
	shared_ptr<Character> character_info;
	bool leader = false;

public:
	Party();

	Party(string party_name, int member_count);

	void display_info();
	void add_leader();
	int get_number();
	void alter_member_count(int number);
	int get_member_count();
	void set_member_count(int count);
};

