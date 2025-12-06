// COMSC-210 | Lab 37 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// sum_ascii() receives a single string and returns the sum of that string's characters' ASCII values
// arguments: a string
// returns: an int sum of the string's characters' ASCII values
int sum_ascii(string);

// gen_hash_index() receives a string and returns the hash index for that string.
// arguments: a string
// returns: an int hash index
int gen_hash_index(string);

int main() {
	string temp;
	ifstream infile;
	// KEY: hash index	VALUE: linked list of codes from file at that hash index
	map<int, std::list<string> > hash_table;

	infile.open("lab-37-data.txt");

	if (infile.good()) {
		while (infile >> temp) {
			int hashIndex = gen_hash_index(temp);

			// check if key exists
			auto search = hash_table.find(hashIndex);
			if (search != hash_table.end()) {
				// if it does, use iter->second to access the linked list
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
	int counter = 0;
	auto it = hash_table.begin();
	while (counter < 100) {
		++it;
		cout << it->first << ": \t";
		for (auto item: it->second) {
			cout << item << " ";
		}
		cout << endl << endl;

		counter++;
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

int sum_ascii(string str) {
	int sum = 0;
	for (char letter: str) {
		sum += (int) letter;
	}

	return sum;
}

int gen_hash_index(string str) {
	int sum = sum_ascii(str);

	// This number was chosen for this hash function because the average summed ASCII value for the strings was 697,
	// and 2^9 = 512 & 2^10 = 1024.
	return sum % 761;
}
