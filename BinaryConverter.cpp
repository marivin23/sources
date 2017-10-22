#include <iostream>
#include <Windows.h>

using namespace::std;

/*void setConsoleWin() {

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SMALL_RECT rect = { 0, 0, 100, 100 };
SetConsoleWindowInfo(hConsole, TRUE, &rect);

}*/

unsigned short int lenght;
char nr[16];

void numBinar(unsigned int n) {
	int ref = n;
	unsigned short int r, index = 1;

	while (n != 0) {
		r = n % 2;
		if (r == 0) {
			nr[index] = '0';
			index++;
			n = n / 2;
		}
		else {
			nr[index] = '1';
			index++;
			n = (n - 1) / 2;
		}
	}
	system("cls");
	cout << "\n\n\n					  The number " << ref << " in binary is ";
	for (int j = (lenght - 1); j > 0; j--) {
		cout << nr[j];
	}
	cout << ".\n";

}

void Bit() {

	for (unsigned short int i = 1; i <= lenght; i++) {
		nr[i] = '0';
	}

}

void menu() {

	system("title Binary Converter");

	system("color 84");
	cout << "\n\n\n	Welcome to Cucc's Binary Converter! What bit length should be the number be represented as?(8 or 16): ";
	cin >> lenght;
	while ((lenght != 8) && (lenght != 16)) {
		system("cls");
		system("color 7c");
		cin.clear();
		cin.ignore();
		cout << "\n\n\n				   WRONG INPUT! Please input the bit lenght again: ";
		cin >> lenght;
	}
	system("color 84");
	system("cls");
	cout << "\n\n\n					Input the number you want to convert: ";
	int numb;
	cin >> numb;
	if ((lenght == 8) && (numb > 255)) {

	}

	Bit();
	numBinar(numb);
	
}

int main() {

	menu();

	system("pause");
	return 0;
}