/*
ID: 06jajun
TASK: help
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

const string NAME = "help";

const int MXN = 1e5+1;
// const int INF = 1e9;
const int MOD = 1e9 + 7;

#define f first
#define s second

int n;
pair<int, int> segs[MXN];
int powers_of_two[MXN];
int prefs[2*MXN];
ifstream fin (NAME + ".in");
ofstream fout (NAME + ".out");

int main() {
    fin >> n;
    // cout << n;
    for (int i=0; i<n; i++) {
        int a, b;
        fin >> a >> b;
        segs[i] = make_pair(a, b);
    }

    for (int i=0; i<n; i++) {
        prefs[segs[i].f]++; prefs[segs[i].s]--;
    }
    for (int i=1; i<2*n; i++) {
        prefs[i] += prefs[i - 1];
    }

    powers_of_two[0] = 1;
    for (int i=1; i<MXN; i++) powers_of_two[i] = powers_of_two[i - 1] * 2 % MOD;

    int ans = 0;
    for (int i=0; i<n; i++) {
        // cout << seg.f << ' ' << seg.s << endl;
        ans += powers_of_two[n - 1 - prefs[segs[i].f - 1]];
        ans %= MOD;
    }
    fout << ans << endl;
}
