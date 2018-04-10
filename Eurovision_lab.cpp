//Eurovision_lab.cpp: определяет точку входа для консольного приложения.

#include <iostream>
#include  <iomanip>
#include  <cstdlib>
#include  <cstring>
#include <string>
#include  <fstream>
#include <stdio.h>

using namespace std;

void fill_an_array(string str, string arr[20][21]){
    
    unsigned long len = str.length();
    string s = "";
    int cnt = 0;
    int count = 0;
    
    for(int i = 3; i < len; i++){
        if(str[i] == '!'){
            do{
                i++;
                s += str[i];
            }
            while(str[i] != '!');
            s.pop_back();
            arr[cnt][count] = s;
            count++;
            s = "";
        }
        else if(str[i] == ','){
            arr[cnt][count] = s;
            count++;
            s = "";
            continue;
        }
        else if(str[i] == '\n') {
            arr[cnt][count] = s;
            cnt++;
            count = 0;
            s = "";
            continue;
        }
        s += str[i];
    }
}

void sort(string arr[20][21], int k){
    for(int i = 0; i < 20; i++){
        for(int j = 19; j > 0; j--){
            long n = strtol(arr[j][k].c_str(), nullptr, 10);
            long g = strtol(arr[j - 1][k].c_str(), nullptr, 10);
            if(g < n) {
                for(int f = 0; f < 21; f++){
                    string temp = arr[j][f];
                    arr[j][f] = arr[j - 1][f];
                    arr[j - 1][f] = temp;
                }
            }
        }
    }
}

void get_marcs(string arr[20][21], string arr2[20], int k){
    for(int l = 0; l < 20; l++){
        arr[l][k] = arr2[l];
    }
}

void sum_marks(long arr1[20], string arr[20][21], string arr3[20], int sum){
    for(int i = 0; i < 20; i++){
        arr3[i] = arr[i][0];
        for (int t = 1; t < 21; t++){
            long g = strtol(arr[i][t].c_str(), nullptr, 10);
            sum += g;
        }
        arr1[i] = sum;
        sum = 0;
    }
}

void sort_by_marks(long arr1[20], string arr3[20]){
    for(int r = 0; r < 20; r++){
        for(int o = 0; o < 19; o++){
            if(arr1[o] < arr1[o + 1]){
                long temp = arr1[o];
                arr1[o] = arr1[o + 1];
                arr1[o + 1] = temp;
                string tempp = arr3[o];
                arr3[o] = arr3[o + 1];
                arr3[o + 1] = tempp;
            }
        }
    }
}

int main() {
    string arr2[20] = {"12", "10", "8", "7", "6", "5", "4", "3", "2", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
    long arr1[20];
    string arr3[20];
    int sum = 0;
    ifstream fin("/Users/buyappleus/Projects/Eurovision/Eurovision/eurovision.csv");
    char ch;
    string str = "";
    while((ch = fin.get()) != EOF){
        str += ch;
    }
    string arr[20][21];
    fill_an_array(str, arr);
    for(int k = 1; k < 21; k++){
        sort(arr, k);
        get_marcs(arr, arr2, k);
    }
    sum_marks(arr1, arr, arr3, sum);
    sort_by_marks(arr1, arr3);
    fin.close();
    ofstream fout("/Users/buyappleus/Desktop/Учеба/labsPB/ResultsLab3.csv");
    for (int k = 0; k < 10; k++) {
        fout << arr3[k] << ",";
        fout << arr1[k] << endl;
    }
    fout.close();
}


