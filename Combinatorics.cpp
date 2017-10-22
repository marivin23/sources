#include <iostream>
#include <Windows.h>

using namespace::std;

/*void setConsoleWin() {

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SMALL_RECT rect = { 0, 0, 100, 100 };
SetConsoleWindowInfo(hConsole, TRUE, &rect);

}*/

int factorial(int j) {

	if (j <= 1) {
		return 1;
	}
	else {
		return j*factorial(j - 1);
	}

}

int combinations(int j, int k) {

	return factorial(j) / (factorial(k)*factorial(j - k));

}

int permutations(int j) {
	return factorial(j);
}

int arangements(int j, int k) {
	return factorial(j) / factorial(j - k);
}

void menu(){
	
	int choice, n, k;

	cout << "Welcome to CombCalculator! For combinations press '1', for arangements press '2', for permutations press '3': ";
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "Wrong input, please input your choice again: ";
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		cout << "COMBINATIONS of N taken by K. Input N: "; cin >> n;
		cout << "Input K: "; cin >> k;
		while (n < k) {
			cout << "N has to be greater than K! Try again: ";
			cout << "Input N: "; cin >> n;
			cout << "Input K: "; cin >> k;
		}
		cout << combinations(n, k) << endl;
		break;
	case 2:
		cout << "Arangements of N taken by K. Input N: "; cin >> n;
		cout << "Input K: "; cin >> k;
		while (n < k) {
			cout << "N has to be greater than K! Try again: ";
			cout << "Input N: "; cin >> n;
			cout << "Input K: "; cin >> k;
		}
		cout << arangements(n, k) << endl;
		break;
	case 3:
		cout << "Permutations of N. Input N: "; cin >> n;
		cout << permutations(n) << endl;
	}


}

int main() {

	menu();

	system("pause");
	return 0;
}