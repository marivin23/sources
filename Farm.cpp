#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int n, h, w;

int calculare(int i, int j){

    while((j>=0)&&(i>=0)){
    return i*j + calculare(i-1,j-1);
    }

}

void citire(){

    fstream inFile;
    inFile.open("c:\\Users\\mariu\\Desktop\\input.txt");
    if(inFile.is_open()){
        inFile >> n;
        while(!inFile.eof()){
            inFile >> w;
            inFile >> h;
            cout << calculare(w, h) << endl;
        }
    }
    inFile.close();
}

int main()
{
    citire();

    return 0;
}
