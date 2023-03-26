/*
ID: 06jajun
TASK: fcolor
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const string NAME = "fcolor";

const int MXN = 2e5+5;
const int INF = 1e9;

int n, m;
vector<int> admired_by[MXN];
int union_sets[MXN];
int col[MXN];
queue<int> q;

ifstream fin (NAME + ".in");
ofstream fout (NAME + ".out");

int find(int a) {
    if (union_sets[a] == a) return a;
    int res = find(union_sets[a]);
    union_sets[a] = res;
    return res;
}

void uni(int a, int b) {
    a = find(a), b = find(b);
    if (admired_by[a].size() > admired_by[b].size()) swap(a, b);
    union_sets[a] = b;
    for (int t : admired_by[a]) admired_by[b].push_back(t);
    admired_by[a].clear();
    if (admired_by[b].size() > 1) q.push(b);
}

int main() {
    // inputs
    fin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        fin >> a >> b;
        admired_by[a].push_back(b);
    }
    // priming
    for (int i=1; i<=n; i++) {
        union_sets[i] = i;
        q.push(i);
    }

    while (!q.empty()) {
        int c = find(q.front()); q.pop();
        // cout << c << '=' << admired_by[c].size() << ' ';
        for (int i=admired_by[c].size() - 1; i > 0; i--) {
            if (find(admired_by[c].front()) == find(admired_by[c][i])) {
                continue;
            }
            uni(admired_by[c].front(), admired_by[c][i]);
        }
    }

    // cout << endl;
    // for (int i=1; i<=n; i++) {
    //     cout << i << ' ' << find(i) << endl;
    // }
    int available = 1;
    for (int i=1; i<=n; i++) {
        if (col[find(i)] == 0) {
            col[find(i)] = available++;
        }
        fout << col[find(i)] << endl;
    }
}
