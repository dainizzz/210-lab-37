// COMSC-210 | Lab 37 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

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
			if (search != hash_table.end()) { // if it does,
				// add the new temp value to the front of the linked list
				search->second.push_front(temp);
			} else { // if key does not exist,
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

	// DISPLAYING FIRST 100 MAP ENTRIES
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
