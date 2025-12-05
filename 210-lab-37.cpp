// COMSC-210 | Lab 37 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
using namespace std;

// sum_ascii() receives a single string and returns the sum of that string's characters' ASCII values
// arguments: a string
// returns: an int sum of the string's characters' ASCII values
int sum_ascii(string);

int main() {
	char a = 'A';
	string a_string = "A";
	string test1 = "CAT";
	string test2 = "apple";
	int test1_calc = 0;
	int test2_calc = 0;
	int test1_actual = sum_ascii(test1);
	int test2_actual = sum_ascii(test2);

	cout << test1 << ": " << test1_calc << " = " << test1_actual << endl;

	cout << a << endl;
	cout << (int) a << endl;
	cout << sum_ascii(a_string) << endl;
	int b = 66;
	cout << b << endl;
	cout << (char) b << endl;

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