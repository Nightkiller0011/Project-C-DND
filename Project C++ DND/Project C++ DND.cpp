
#include "party.h"
#include <iostream>

void display_menu();
void display_parties(list<Party>& parties);
void add_party(list<Party>& parties);
void remove_party(list<Party>& parties);
void add_members(list<Party>& parties);
void remove_members(list<Party>& parties);
void find_id(list<Party>& parties);
void total_members(list<Party>& parties);
void recruit_members(list<Party>& parties);
void add_party_leader(list<Party>& parties);

list<Party>::iterator find_by_id(list<Party>& parties, int id);


int main()
{
	int menu_item = 1;
	list<Party> parties;
	while (menu_item != 0)
	{
		display_menu();
		cin >> menu_item;
		if (menu_item == 1)
		{
			display_parties(parties);
		}
		else if (menu_item == 2)
		{
			add_members(parties);
		}
		else if (menu_item == 3)
		{
			remove_members(parties);
		}
		else if (menu_item == 4)
		{
			add_party(parties);
		}
		else if (menu_item == 5)
		{
			find_id(parties);
		}
		else if (menu_item == 6)
		{
			remove_party(parties);
		}
		else if (menu_item == 7)
		{
			total_members(parties);
		}
		else if (menu_item == 8)
		{
			recruit_members(parties);
		}
		else if (menu_item == 9)
		{
			add_party_leader(parties);
		}
	}
}

void display_menu() {
	cout << "\nParty Menu:\n0. Quit Program\n1. Display Party Information" <<
		"\n2. Add members to a Party\n3. Disband Members from a Party\n4. Add new Party\n" <<
		"5. Find Party by ID\n6. Remove Party\n7. Show total members in all parties\n" <<
		"8. Recruit a few party members\n9. Add Leader to a Party\n" << "Your Choice : ";
}

void display_parties(list<Party>& parties) {
	for_each(parties.begin(), parties.end(), [](auto& parties) {
		parties.display_info();
		});
}

void add_party(list<Party>& parties) {
	string name;
	int amount;
	cout << "Enter Party Name: ";
	cin >> name;
	cout << "Enter Party member count: ";
	cin >> amount;
	Party party{ name, amount };
	parties.push_back(party);
}

void remove_party(list<Party>& parties) {
	int id;
	cout << "Enter party ID to remove: ";
	cin >> id;
	list<Party>::iterator it;
	it = find_by_id(parties, id);
	if (it != parties.end())
	{
		cout << "Party Found, Disbanding..." << endl;
		auto new_end = remove_if(parties.begin(), parties.end(), [id](auto& party) {
			return party.get_number() == id;
			});
		parties.erase(new_end, parties.end());
	}
	else
	{
		cout << "That ID was not found." << endl;
	}

}
list<Party>::iterator find_by_id(list<Party>& parties, int id) {
	list<Party>::iterator it;
	for (it = parties.begin(); it != parties.end(); it++)
	{
		if (it->get_number() == id)
		{
			return it;
		}
	}
	return it;
}

void add_members(list<Party>& parties) {
	int id;
	int amount;
	cout << "Enter the ID for the party to add members into: ";
	cin >> id;
	list<Party>::iterator it;
	it = find_by_id(parties, id);
	if (it != parties.end())
	{
		cout << "Party Found" << endl << "Amount of new members: ";
		cin >> amount;
		it->alter_member_count(amount);
	}
	else
	{
		cout << "That ID was not found." << endl;
	}

}

void remove_members(list<Party>& parties) {
	int id;
	int amount;
	cout << "Enter the ID for the party to disband members from: ";
	cin >> id;
	list<Party>::iterator it;
	it = find_by_id(parties, id);
	if (it != parties.end())
	{
		cout << "Party Found" << endl << "Amount of disbanded members: ";
		cin >> amount;
		it->alter_member_count(-(amount));
	}
	else
	{
		cout << "That ID was not found." << endl;
	}

}

void find_id(list<Party>& parties) {
	int id;
	cout << "Enter the ID of the Party to find: ";
	cin >> id;
	list<Party>::iterator it;
	it = find_by_id(parties, id);

	if (it != parties.end())
	{
		cout << "Party Found." << endl;
		it->display_info();
	}
	else
	{
		cout << "That ID was not found." << endl;
	}

}

void total_members(list<Party>& parties) {
	float total = accumulate(parties.begin(), parties.end(), 0.0f, [](auto accumulator, auto& parties) {
		return accumulator + parties.get_member_count();
		});
	cout << "Total number of Party members: " << total << endl;
}

void recruit_members(list<Party>& parties) {
	float purge;
	cout << "What percentage of members will be recruited: ";
	cin >> purge;
	float purged = purge * .01;
	transform(parties.begin(), parties.end(), parties.begin(), [purge, purged](auto& party) {
		party.set_member_count(party.get_member_count() + (party.get_member_count() * purged));
		return party;
			});
}

void add_party_leader(list<Party>& parties) {
	int id;
	cout << "Enter the ID of the Party: ";
	cin >> id;
	list<Party>::iterator it;
	it = find_by_id(parties, id);

	if (it != parties.end())
	{
		it->add_leader();
	}
	else
	{
		cout << "That ID was not found." << endl;
	}

}