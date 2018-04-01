#include "stdafx.h"
#include <iostream>
#include  <iomanip>
#include  <cstdlib>
#include  <cstring>
#include <string>
#include  <fstream>
#include <stdio.h>
using namespace std;


int main() {
	string arr2[20] = { "12", "10", "8", "7", "6", "5", "4", "3", "2", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0" };
	int arr1[20];
	string arr3[20];
	ifstream fin("/Users/buyappleus/Projects/Eurovision/Eurovision/eurovision.csv");
	if (!fin.good()) {
		cerr << "Can't open input file" << endl;
		exit(1);
	}
	else {
		cerr << "File is opened" << endl;
	}
	char ch;
	string str = "";
	while ((ch = fin.get()) != EOF) {
		str += ch;
	}
	int len = str.length();
	string s = "";
	int cnt = 0;
	int count = 0;
	string arr[20][21];
	for (int i = 3; i < len; i++) {
		if (str[i] == ',') {
			arr[cnt][count] = s;
			count++;
			s = "";
			continue;
		}
		else if (str[i] == '\n') {
			arr[cnt][count] = s;
			cnt++;
			count = 0;
			s = "";
			continue;
		}
		s += str[i];
	}

	for (int k = 1; k < 21; k++) {
		for (int i = 0; i < 20; i++) {
			for (int j = 20; j > 0; j--) {
				int n = atoi(arr[j][k].c_str());
				int g = atoi(arr[j - 1][k].c_str());
				if (g < n) {
					for (int f = 0; f < 21; f++) {
						string temp = arr[j][f];
						arr[j][f] = arr[j - 1][f];
						arr[j - 1][f] = temp;
					}
				}
			}
		}
		for (int l = 0; l < 20; l++) {
			arr[l][k] = arr2[l];
		}
	}
	int sum = 0;
	for (int i = 0; i < 20; i++) {
		arr3[i] = arr[i][0];
		for (int t = 1; t < 21; t++) {
			int g = atoi(arr[i][t].c_str());
			sum += g;
		}
		arr1[i] = sum;
		sum = 0;
	}
	for (int r = 0; r < 20; r++) {
		for (int o = 0; o < 19; o++) {
			if (arr1[o] < arr1[o + 1]) {
				int temp = arr1[o];
				arr1[o] = arr1[o + 1];
				arr1[o + 1] = temp;
				string tempp = arr3[o];
				arr3[o] = arr3[o + 1];
				arr3[o + 1] = tempp;

			}
		}
	}
	for (int k = 0; k < 10; k++) {
		cout << arr3[k] << ": ";
		cout << arr1[k] << endl;
	}
	fin.close();
	ofstream fout;
	fout.open("/Users/buyappleus/Desktop/ResultsLab3.txt");
	for (int k = 0; k < 10; k++) {
		fout << arr3[k] << ": ";
		fout << arr1[k] << endl;
	}
	fout.close();
}