#include "party.h"

int Party::next_party = 1;

Party::Party() : party_name(""), member_count(0), number(next_party++), character_info(nullptr)
{
}

Party::Party(string party_name, int member_count) : party_name(party_name), member_count(member_count), number(next_party++), character_info(nullptr) {

}

void Party::display_info() {
	cout << "Party ID: " << number << "  Name: " << party_name << " Members: " << member_count << endl;
	if (leader) {
		character_info->display_info();
	}
}

void Party::add_leader() {
	character_info = make_shared<Character>();
	character_info->initialize();
	leader = true;
}

int Party::get_number() {
	return number;
}

void Party::alter_member_count(int number) {
	member_count += number;
}

int Party::get_member_count() {
	return member_count;
}

void Party::set_member_count(int count) {
	member_count = floor(count);
}


