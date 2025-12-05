// COMSC-210 | Lab 37 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <fstream>
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
	/* MILESTONE 1
	char a = 'A';
	string a_string = "A";
	string test1 = "CAT";
	string test2 = "apple";
	int test1_calc = 216;
	int test2_calc = 530;
	int test1_actual = sum_ascii(test1);
	int test2_actual = sum_ascii(test2);

	cout << test1 << ": " << test1_calc << " = " << test1_actual << endl;
	cout << test2 << ": " << test2_calc << " = " << test2_actual << endl;

	cout << a << endl;
	cout << (int) a << endl;
	cout << sum_ascii(a_string) << endl;
	int b = 66;
	cout << b << endl;
	cout << (char) b << endl;
	*/

	// MILESTONE 2
	int sum = 0;
	int count = 0;
	int target_sum = 69893419;
	string temp;
	ifstream infile;

	infile.open("lab-37-data.txt");

	if (infile.good()) {
		while (infile >> temp) {
			sum += sum_ascii(temp);
			count++;
		}
	} else {
		cout << "Error opening file";
		exit(2);
	}

	if (sum == target_sum)
		cout << "The sum matches the target sum.";
	else
		cout << "The sums do not match. The target sum was " << target_sum << " and the actual sum was " << sum;

	cout << sum / count << endl;

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
	for (char letter : str) {
		sum += (int) letter;
	}

	return sum;
}

int gen_hash_index(string str) {
	int sum = sum_ascii(str);

	return sum % 97;
}