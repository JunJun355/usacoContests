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
vector<int> admired_by[MXN], reverse_uni[MXN];
int union_sets[MXN];
int col[MXN];
queue<int> q;


ifstream fin (NAME + ".in");
ofstream fout (NAME + ".out");

void uni(int a, int b) {
    a = union_sets[a]; b = union_sets[b];
    if (reverse_uni[a].size() > reverse_uni[b].size()) swap(a, b);
    for (int t : reverse_uni[a]) {
        reverse_uni[b].push_back(t);
        union_sets[t] = b;
    }
    // reverse_uni[a].clear();
    admired_by[b].insert(end(admired_by[b]),begin(admired_by[a]),end(admired_by[a])); 
    admired_by[a].clear();
    if (admired_by[b].size() > 1) q.push(b);
}

// void uni(int a, int b) {
//     a = union_sets[a], b = union_sets[b]; 
// 	if (reverse_uni[a].size() < reverse_uni[b].size()) swap(a,b);
// 	for (int t: reverse_uni[b]) { union_sets[t] = a; reverse_uni[a].push_back(t); }
// 	admired_by[a].insert(end(admired_by[a]),begin(admired_by[b]),end(admired_by[b])); 
// 	admired_by[b].clear();
// 	if (admired_by[a].size() > 1) q.push(a);
// }

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
        reverse_uni[i].push_back(i);
        if (admired_by[i].size() > 1) q.push(i);
    }

    // while (!q.empty()) {
    //     int i = q.front(); q.pop();
    //     // cout << c << '=' << admired_by[c].size() << ' ';
    //     while (admired_by[i].size() > 1) {
    //         if (union_sets[admired_by[i].front()] == union_sets[admired_by[i].back()]) {
    //             admired_by[i].pop_back(); continue;
    //         }
    //         uni(admired_by[i].front(), admired_by[i].back());
    //         admired_by[i].pop_back();
    //     }
    // }
    while (!q.empty()) {
        int x = q.front();
        if (admired_by[x].size() <= 1) {
            q.pop(); continue;
        }
        int c = admired_by[x].back(); admired_by[x].pop_back();
        if (union_sets[admired_by[x].back()] == union_sets[c]) continue;
        uni(admired_by[x].back(), c);
    }

    // cout << endl;
    // for (int i=1; i<=n; i++) {
    //     cout << i << ' ' << find(i) << endl;
    // }
    int available = 1;
    for (int i=1; i<=n; i++) {
        if (col[union_sets[i]] == 0) {
            col[union_sets[i]] = available++;
        }
        fout << col[union_sets[i]] << endl;
    }
}
