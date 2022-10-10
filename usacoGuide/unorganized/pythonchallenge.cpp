#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin ("pythonchallenge.in");
char arr[1252][82];
map<char, int> num;

bool isup(char c) {
    // cout << c << (c < 'a');
    return (c < 'a');
}

int main() {
    for (int i=0; i<1252; i++) for (int j=0; j<82; j++) arr[i][j] = 'a';

    for (int i=1; i<1251; i++) {
        string s;
        fin >> s;
        for (int j=0; j<80; j++) {
            arr[i][j+1] = s[j];
        }
    }
    // for (int i=1; i<1251; i++) for (int j=1; j<81; j++) {
    //     int n=0;
    //     for (int x=-1; x < 2; x++) for (int y=-1; y<2; y++) {
    //         if (isup(arr[i+x][j+y])) n++;
    //     }
    //     if (n == 8) {
    //         num[arr[i][j]] ++;
    //         // cout << i << ' ' << j << ' ' << arr[i][j] << '-';
    //     }
    // }
    for (int i=4; i<1248; i++) for (int j=1; j<81; j++) {
        int n=0;
        for (int x=-3; x < 4; x++) {
            if (isup(arr[i][j+x])) n++;
        }
        if (n == 6 && !isup(arr[i][j-4]) && !isup(arr[i][j+4]) && !isup(arr[i][j])) {
            num[arr[i][j]] ++;
            cout << i << ' ' << j << ' ' << arr[i][j] << '-';
        }
    }
    for (auto x : num) cout << x.first << ' ' << x.second << endl;


    // string s = "http://www.pythonchallenge.com/pc/def/map.html";
    // string ns = "";
    // for (char x : s) {
    //     if (96 < x && x < 123) ns += (x - 97 + 2) % 26 + 97;
    //     else (ns += x);
    // }
    // cout << ns << endl;
    return 0;
}
