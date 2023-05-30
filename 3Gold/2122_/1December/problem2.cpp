/*
ID: 06jajun
TASK: template
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MXN = 2e5;
const int INF = 1e9;

int n;
int guesses[MXN];
vector<int> highs, lows;

ifstream fin ("f.in");
ofstream fout ("f.out");

int main() {
    fin >> n;
    for (int i=0; i<n; i++) {
        fin >> guesses[i];
    }
    for (int i=0; i<n; i++) {
        if (highs.empty() || guesses[highs.back()] > guesses[i]) highs.push_back(i);
    }
    for (int x=1; x<=n; x++) {
        cout << '-' << endl;
        while (lows.size() && lows.back() > highs.back()) lows.pop_back();
        lows.push_back(highs.back());
        highs.pop_back();
        int i = lows.back()+1;
        while (i < n && (highs.empty() || guesses[highs.back()] != x+1)) {
            if ((highs.empty() && guesses[i] > x) || guesses[highs.back()] > guesses[i]) highs.push_back(i);
            i++;
        }
        for (int temp : highs) cout << guesses[temp] << ' '; cout << endl;
        for (int temp : lows) cout << guesses[temp] << ' '; cout << endl;

    }
}
