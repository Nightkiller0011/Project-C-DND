#include "character.h"

string Character::get_leader_name() {
	return leader_name;
}
void Character::set_leader_name(string name) {
	leader_name = name;
}
string Character::get_leader_class() {
	return leader_class;
}
void Character::set_leader_class(string classx) {
	leader_class = classx;
}
string Character::get_leader_race() {
	return leader_race;
}
void Character::set_leader_race(string race) {
	leader_race = race;
}

void Character::display_info() {
	cout << "+ Leader Info: Name: " << leader_name << " Class: " << leader_class << " Race: " << leader_race << endl;
}
void Character::initialize() {
	cout << "Leader Name: ";
	cin >> leader_name;
	cout << "Leader Class: ";
	cin >> leader_class;
	cout << "Leader Race: ";
	cin >> leader_race;
}
