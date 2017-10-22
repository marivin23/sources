#include <iostream>
#include <Windows.h>

using namespace::std;

unsigned int n, index, i, j, prime;

/*void setConsoleWin() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { 0, 0, 100, 100 };
	SetConsoleWindowInfo(hConsole, TRUE, &rect);

}*/

void searchPrime() {

	cout << "Input the number of the prime number you'd like to be found: ";
	cin >> n;

	while (index < n) {
		for (i = 2; i < 10000; i++) {
			for (j = 2; j < i; j++) {
				if (i%j == 0) {
					break;
				}
			}
			if (j == i) {
				prime = j;
				index++;
				if (index == n)
					break;
			}
		}
	}
	cout << "The prime number you wanted to find is: " << prime << endl;
	
}

void testPrime() {

	cout << "Inout the number you'd like to be tested for prime: ";
	cin >> n;

	for (i = 2; i < n; i++) {
		if (n%i == 0) {
			cout << n << " is not a prime number." << endl;
			break;
		}
	}
	if (i == n) {
		cout << n << " is a prime number." << endl;
	}

}

void menu() {

	unsigned int choice;
	cout << "Welcome to PrimeCheck. Input 1 for searching a prime or 2 for testing a number if prime: ";
	cin >> choice;
	if (choice != 1 && choice != 2) {
		system("color 4");
		while (choice != 1 && choice != 2) {
			cout << "Wrong input. Please input your choice again: ";
			cin >> choice;
		}
	}
	if (choice == 1) {
		system("cls");
		system("color 3");
		searchPrime();
	}
	else if (choice == 2) {
		system("cls");
		system("color 2");
		testPrime();
	}

}

int main() {

	menu();

	system("pause");
	return 0;
}