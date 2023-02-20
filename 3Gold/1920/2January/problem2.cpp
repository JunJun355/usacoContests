/*
ID: 06jajun
TASK: threesum
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define MXN 5000
#define MXA 1000001
#define INF 1000000000

int n, q;
int a[MXN];
int counter[2*MXA];
long long prefix[MXN][MXN];
ifstream fin ("threesum.in");
ofstream fout ("threesum.out");

int main() {
    fin >> n >> q;
    for (int i=0; i<n; i++) fin >> a[i];

    // memset(prefix, 0, sizeof(prefix));
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (abs(a[i] + a[j]) < MXA) prefix[i][j] = counter[MXA - a[i] - a[j]];
            counter[MXA + a[j]]++;
            // cout << prefix[i][j] << ' ';
        }
        for (int j=i+1; j<n; j++) {
            counter[MXA + a[j]]--;
        }
        // cout << endl;
    }

    for (int i=n - 1; i>=0; i--) {
        for (int j=i+1; j<n; j++) {
            prefix[i][j] += prefix[i][j - 1] + prefix[i + 1][j] - prefix[i + 1][j - 1];
            // cout << prefix[i][j] << ' ';
        }
        // cout << endl;
    }

    for (int i=0; i<q; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        fout << prefix[a][b] << endl;
    }
}
