#include <iostream>
#include  <iomanip>
#include  <cstdlib>
#include  <cstring>
#include <string>
#include  <fstream>

#include <stdio.h>
using namespace std;


int main() {
    int arr2[20] = {12, 10, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ifstream fin("/Users/buyappleus/Projects/Eurovision/Eurovision/eurovision.csv");
    //    if (!fin.good()) {
    //        cerr << "Can't open input file" << endl;
    //        exit(1);
    //    } else {
    //        cerr << "File is opened" << endl;
    //    }
    char ch;
    string str = "";
    while((ch = fin.get()) != EOF){
        str += ch;
    }
    int len = str.length();
    string s = "";
    int cnt = 0;
    int count = 0;
    string arr[20][21];
    for(int i = 3; i < len; i++){
        if(str[i] == ','){
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
    for(int k = 0; k < 20; k++){
        for(int y = 0; y < 21; y++){
            cout << arr[k][y] << ", ";
        }
        cout << endl;
    }
    
    //    for(int k = 0; k < 21; k++){
    ////        for(int i = 1; i < 22; i++){
    ////            for(int j = 21; j > 0; j--){
    ////                if(arr[j - 1][k] < arr[j][k]) {
    ////
    ////                }
    ////            }
    ////        }
    //        for(int j = 0; j < 21; j++){
    //////            arr[k][j] = atoi(arr[k][j]);
    //////            arr[k][j] = arr2[j];
    //            cout << arr[k][j] << ", ";
    //        }
    ////        cout << endl;
    //    }
    
    fin.close();
}
