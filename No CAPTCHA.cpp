#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>

using namespace::std;

string s1, s2;

void comparare() {

	unsigned short mistake = 0;
	bool comp = TRUE;
	string acc = "CEFKOPSTUVWXYZ";
	string acc2 = "Il";
	
	if (size(s1) == size(s2)) {

		for (unsigned int index = 0; index <= size(s1); index++) {
			if (toupper(s1[index]) != toupper(s2[index])) {
				comp = FALSE;
			}
		}

		if (comp == TRUE) {

				for (unsigned int i = 0; i < size(s1); i++) {
					if (s1[i] != s2[i]) {
						for (unsigned int j = 0; j < size(acc); j++) {
							if (((toupper(s2[i]) == toupper(acc[j])) && s1[i] == toupper(acc[j]))) {
								comp = TRUE;
								break;
							}
							else {
								/*if (((s2[i] == acc2[1]) && (s1[i] == acc2[0])) || ((s1[i] == acc2[1]) && (s2[i] == acc2[0])))) { //verifica daca s1[i] = l/I si s2[i] = I/l(not working yet)
									comp = TRUE;
									break;
								}*/
								if (size(s1) > 5 && mistake == 0) {
									comp = TRUE;
									mistake = 1;
									break;
								} else comp = FALSE;
							}
						}
					if (comp == FALSE) break;
				}
			}
		
		}

	}
	else comp = FALSE;

	if (comp == TRUE) cout << "true\n";
	else cout << "false\n";

}

void citire(string path) {

	ifstream inFile;
	inFile.open(path);

	while (inFile >> s1) {

		inFile >> s2;
		comparare();

	}
	inFile.close();

}

int main() {

	string path1;
	//cin >> path1;

	citire("C:\\Users\\miv\\Desktop\\inf.txt");

	system("pause");
	return 0;
}