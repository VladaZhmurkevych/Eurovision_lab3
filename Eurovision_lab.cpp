//Eurovision_lab.cpp: определяет точку входа для консольного приложения.

#include <iostream>
#include  <iomanip>
#include  <cstdlib>
#include  <cstring>
#include <string>
#include  <fstream>

#include <stdio.h>
using namespace std;

int main() {
    ifstream fin("/Users/buyappleus/Projects/Eurovision/Eurovision/eurovision.csv");
    if (!fin.good()) {
        cerr << "Can't open input file" << endl;
        exit(1);
    } else {
        cerr << "File is opened" << endl;
    }
    char *arr[21][21];
    string s;
    for(int i = 0; i < 21; i++){
        getline(fin, s);
        char arr1[1000];
        strcpy(arr1, s.c_str() );
        int k = 0;
        char * pch = strtok(arr1, ",");
        while (pch != NULL)
        {
            arr[i][k] = pch;
            pch = strtok(NULL, ",");
            cout << arr[i][k] << ", ";
            k++;
        }
        cout << endl;
    }
    
    fin.close();
}

