#include <iostream>
#include <Windows.h>

using namespace::std;

float a, b, c, x1, x2, delta;

void input() {

	cout << "Input a: ";
	cin >> a;
	fflush(stdin);
	cout << "Input b: ";
	cin >> b;
	fflush(stdin);
	cout << "Input c: ";
	cin >> c;
	fflush(stdin);

}

void calc() {

	input();
	delta = ((b * b) - (4 * a * c));
	if (delta < 0) {
		cout << "X1/X2 are complex numbers" << endl;
	}
	else {
		if (delta == 0) {
			x1 = -b / (2 * a);
			cout << x1 << endl;
		}
		else {
			cout << delta << endl;
			x1 = (-b - sqrt(delta)) / (2 * a);
			x2 = (-b + sqrt(delta)) / (2 * a);
			cout << "X1 = " << x1 << endl;
			cout << "X2 = " << x2 << endl;
		}
	}
	system("pause");
}

int main() {

	calc();

	return 0;
}