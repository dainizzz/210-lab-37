// COMSC-210 | Lab 38 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <limits>
using namespace std;

// gen_hash_index() receives a string and returns the hash index for that string.
// arguments: a string
// returns: an int hash index
int gen_hash_index(string);

// menu() displays the menu options for printing the first 100 entries, searching for a key, adding a key, removing a
// key, modifying a key, and exiting the program. It validates the user's input and returns the user's choice as an int.
// arguments: none
// returns: an int value representing the user's menu choice
int menu();

// print_first_100_entries() prints the first 100 entries (i.e. keys in the std::map) in the hash table along with the
// values stored at those hash indexes
// arguments: a hash table of type map<int, list<string>>
// returns: nothing
void print_first_100_entries(map<int, list<string> > &);

// search_for_key() prompts the user for a key, searches the hash table for the provided key, and outputs a message
// saying whether the key was found or not.
// arguments: a hash table of type map<int, list<string>> to be searched
// returns: nothing
void search_for_key(map<int, list<string> > &);

// find_key() searches the hash table for the provided key and returns a bool value signifying whether the key was found
// arguments: the string key being searched for, a hash table of type map<int, list<string>> to be searched
// returns: a bool value signifying whether the string was found
bool find_key(string, map<int, list<string> > &);

// add_key() adds a key to the hash table
// arguments: the string key being added, a hash table of type map<int, list<string>> the key is being added to
// returns: nothing
void add_key(string, map<int, list<string> > &);

// remove_key() removes a key from the hash table
// arguments: the string key being removed, a hash table of type map<int, list<string>> the key is being removed from
// returns: nothing
void remove_key(string, map<int, list<string> > &);

// modify_key() modifies a key in the hash table
// arguments: the string key being modified, a hash table of type map<int, list<string>> the modified key is in
// returns: nothing
void modify_key(string, map<int, list<string> > &);

int main() {
	string temp;
	ifstream infile;
	// KEY: hash index	VALUE: linked list of codes from file at that hash index
	map<int, list<string> > hash_table;

	infile.open("lab-37-data.txt");

	if (infile.good()) {
		while (infile >> temp) {
			int hashIndex = gen_hash_index(temp);

			// check if key exists
			auto search = hash_table.find(hashIndex);
			if (search != hash_table.end()) {
				// if it does,
				// add the new temp value to the front of the linked list
				search->second.push_front(temp);
			} else {
				// if key does not exist,
				// make a new linked list and have temp as the head
				list<string> newList(1, temp);
				// make_pair() of hash index + temp value and insert()
				hash_table.insert(make_pair(hashIndex, newList));
			}
		}
	} else {
		cout << "Error opening file";
		exit(2);
	}

	// TESTING
	// print_first_100_entries(hash_table);
	// string test = "536B9DFC93AF";
	// bool search_test = search_for_key(test, hash_table);
	// if (search_test) {
	// 	cout << "The search function works." << endl;
	// }

	bool displayMenu = true;
	while (displayMenu) {
		int choice = menu();
		switch (choice) {
			case 1:
				print_first_100_entries(hash_table);
				break;
			case 2:
				search_for_key(hash_table);
				break;
			case 3:
				// add
				break;
			case 4:
				// remove
				break;
			case 5:
				// modify
				break;
			case 6:
				displayMenu = false;
				break;
			// Default case will not occur since the menu() function validates user input
			default:
				break;
		}
	}

	return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int gen_hash_index(string str) {
	int sum = 0;
	for (char letter: str) {
		sum += (int) letter;
	}

	// This number was chosen for this hash function because the average summed ASCII value for the strings was 697,
	// and 2^9 = 512 & 2^10 = 1024. I also did some testing with other prime numbers between 617-971 and this seemed
	// to have the best distribution (i.e. smaller "buckets") compared to the other numbers used for testing.
	return sum % 761;
}

int menu() {
	int choice;

	cout << "Please make a selection:" << endl;
	cout << "\t1. Print the first 100 entries" << endl;
	cout << "\t2. Search for a key" << endl;
	cout << "\t3. Add a key" << endl;
	cout << "\t4. Remove a key" << endl;
	cout << "\t5. Modify a key" << endl;
	cout << "\t6. Exit" << endl;
	while (!(cin >> choice) || choice < 1 || choice > 6) {
		cout << "Invalid input. Please enter a number between 1 and 6." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return choice;
}

void print_first_100_entries(map<int, list<string> > &hash_table) {
	int counter = 0;
	auto it = hash_table.begin();
	while (counter < 100) {
		cout << "HASH INDEX " << it->first << ':' << endl;
		for (auto item: it->second) {
			cout << item << " ";
		}
		cout << endl << endl;

		++it;
		counter++;
	}
}

void search_for_key(map<int, list<string> > &hash_table) {
	string search_key;
	cout << "Enter search key: ";
	cin >> search_key;

	bool found = find_key(search_key, hash_table);
	cout << "Key \"" << search_key << "\"";
	if (found)
		cout << " found in hash table." << endl;
	else
		cout << " not found." << endl;
}

// Since several functions need to know whether a key exists or not, this helper function handles that logic.
bool find_key(string key, map<int, list<string> > &hash_table) {
	int hashIndex = gen_hash_index(key);
	auto search = hash_table.find(hashIndex);
	if (search != hash_table.end()) {
		for (auto item: search->second) {
			if (key == item) {
				// If key == item, that means the key was found in the hash table
				return true;
			}
		}
	}

	// If the hash index wasn't already in the map, or if the index was in the map and none of the keys matched the
	// string being searched, the key does not exist in the map.
	return false;
}

void add_key(string key, map<int, list<string> > &hash_table) {
}

void remove_key(string key, map<int, list<string> > &hash_table) {
}

void modify_key(string key, map<int, list<string> > &hash_table) {
}
