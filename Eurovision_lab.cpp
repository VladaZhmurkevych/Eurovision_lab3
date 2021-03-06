#include "stdafx.h"
#include <iostream>
#include  <iomanip>
#include  <cstdlib>
#include  <cstring>
#include <string>
#include  <fstream>
#include <stdio.h>

using namespace std;

void fill_an_array(string strFromFile, string arrOfScore[20][21]);
void sort(string arrOfScore[20][21], int a);
void get_marks(string arrOfScore[20][21], string arrOfMarks[20], int k);
void sum_marks(long arrResultScore[20], string arrOfScore[20][21], string arrResultCountry[20], int sum);
void sort_by_marks(long arr1[20], string arr3[20]);


int main() {
	string arrOfMarks[20] = { "12", "10", "8", "7", "6", "5", "4", "3", "2", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0" };
	long arrResultScore[20];
	string arrResultCountry[20];
	int sum = 0;
	ifstream fin("E:/eurovision_lab.csv");
	char ch;
	string strFromFile = "";
	while ((ch = fin.get()) != EOF) {
		strFromFile += ch;
	}
	string arrOfScore[20][21];
	fill_an_array(strFromFile, arrOfScore);
	for (int i = 1; i < 21; i++) {
		sort(arrOfScore, i);
		get_marks(arrOfScore, arrOfMarks, i);
	}
	sum_marks(arrResultScore, arrOfScore, arrResultCountry, sum);
	sort_by_marks(arrResultScore, arrResultCountry);
	fin.close();
	ofstream fout("E:/ResultsLab4.csv");
	for (int i = 0; i < 10; i++) {
		fout << arrResultCountry[i] << ",";
		fout << arrResultScore[i] << endl;
	}
	fout.close();
	system("pause");
}

void fill_an_array(string strFromFile, string arrOfScore[20][21]) {

	unsigned long len = strFromFile.length();
	string str = "";
	int row = 0;
	int column = 0;

	for (int i = 3; i < len; i++) {
		if (strFromFile[i] == '!') {
			do {
				i++;
				str += strFromFile[i];
			} while (strFromFile[i] != '!');
			str.pop_back();
			arrOfScore[row][column] = str;
			column++;
			str = "";
		}
		else if (strFromFile[i] == ',') {
			arrOfScore[row][column] = str;
			column++;
			str = "";
			continue;
		}
		else if (strFromFile[i] == '\n') {
			arrOfScore[row][column] = str;
			row++;
			column = 0;
			str = "";
			continue;
		}
		str += strFromFile[i];
	}
}

void sort(string arrOfScore[20][21], int a) {
	for (int i = 0; i < 20; i++) {
		for (int j = 19; j > 0; j--) {
			
				long firstNumber = strtol(arrOfScore[j][a].c_str(), nullptr, 10);
				long secondNumber = strtol(arrOfScore[j - 1][a].c_str(), nullptr, 10);
			}
			/*long firstNumber = strtol(arrOfScore[j][a].c_str(), nullptr, 10);
			long secondNumber = strtol(arrOfScore[j - 1][a].c_str(), nullptr, 10);*/
			if (secondNumber < firstNumber) {
				for (int k = 0; k < 21; k++) {
					string temp = arrOfScore[j][k];
					arrOfScore[j][k] = arrOfScore[j - 1][k];
					arrOfScore[j - 1][k] = temp;
				}
			}
		}
	}
}

void get_marks(string arrOfScore[20][21], string arrOfMarks[20], int k) {
	for (int i = 0; i < 20; i++) {
		arrOfScore[i][k] = arrOfMarks[i];
	}
}

void sum_marks(long arrResultScore[20], string arrOfScore[20][21], string arrResultCountry[20], int sum) {
	for (int i = 0; i < 20; i++) {
		arrResultCountry[i] = arrOfScore[i][0];
		for (int j = 1; j < 21; j++) {
			long mark = strtol(arrOfScore[i][j].c_str(), nullptr, 10);
			sum += mark;
		}
		arrResultScore[i] = sum;
		sum = 0;
	}
}

void sort_by_marks(long arrResultScore[20], string arrResultCountry[20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 19; j++) {
			if (arrResultScore[j] < arrResultScore[j + 1]) {
				long tempScore = arrResultScore[j];
				arrResultScore[j] = arrResultScore[j + 1];
				arrResultScore[j + 1] = tempScore;
				string tempCountry = arrResultCountry[j];
				arrResultCountry[j] = arrResultCountry[j + 1];
				arrResultCountry[j + 1] = tempCountry;
			}
		}
	}
}
