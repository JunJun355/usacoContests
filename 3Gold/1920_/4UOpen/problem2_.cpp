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
vector<int> admires[MXN];
int union_sets[MXN], depth_sets[MXN];

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
    if (depth_sets[a] > depth_sets[b]) swap(a, b);
    union_sets[a] = b;
    depth_sets[b]++;
}

int main() {
    // inputs
    fin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        fin >> a >> b;
        admired_by[a].push_back(b);
        admires[b].push_back(a);
    }
    // priming
    queue<int> q;
    for (int i=1; i<=n; i++) {
        union_sets[i] = i;
        depth_sets[i] = 1;
        q.push(i);
    }

    while (!q.empty()) {
        int c = q.front(); q.pop();
        cout << c << '=' << admired_by[c].size() << ' ';
        while (admired_by[c].size() > 1) {
            uni(admired_by[c].front(), admired_by[c].back());
            admired_by[c].pop_back();
        }
        while (admires[c].size() > 1) {
            uni(admires[c].front(), admires[c].back());
            admires[c].pop_back();
        }
    }

    cout << endl;
    for (int i=1; i<=n; i++) {
        cout << i << ' ' << find(i) << endl;
    }
}
