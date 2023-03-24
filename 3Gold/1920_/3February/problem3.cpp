/*
ID: 06jajun
TASK: deleg
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

const string NAME = "deleg";

const int MXN = 1e5+5;
const int INF = 1e9;

ifstream fin (NAME + ".in");
ofstream fout (NAME + ".out");

int n, sub[MXN];
vector<int> edges[MXN];
vector<int> size_sub_trees[MXN];

int dfs(int cur, int par) {
    int siz = 1;
    for (int chi : edges[cur]) if (chi != par) {
        int ne = dfs(chi, cur);
        siz += ne;
        size_sub_trees[cur].push_back(ne);
    }
    if (cur != 1) size_sub_trees[cur].push_back(n - siz);
    return siz;
}

int yn[MXN];
bool yea_no(int k) {
    if ((n - 1) % k != 0) return false;
    for (int i=0; i<n; i++) yn[i] = 0;
    for (int i=0; i<n; i++) {
        int free = 0;
        for (int siz : size_sub_trees[i]) {
            if (siz % k == 0) continue;
            siz = siz % k;
            if (yn[k - siz]) {
                yn[k - siz]--; free--;
            }
            else {
                yn[siz]++;
                free++;
            }
        }
        if (free) return false;
    }
    return true;
}

int main() {
    fin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        fin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 0);

    for (int i=1; i<n; i++) {
        fout << (yea_no(i) ? 1 : 0);
    }
    fout << endl;
}
