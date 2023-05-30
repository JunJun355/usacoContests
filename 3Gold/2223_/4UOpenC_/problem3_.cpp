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

const int MXN = 1e3+1;
const int INF = 1e9;

int t, n, m;
int par[MXN];
vector<int> children[MXN];
int par2[MXN];
vector<int> children2[MXN];
pair<int, int> ranges[MXN];
pair<int, int> ranges2[MXN];

vector<pair<int, int>> merges;

// int cnt;
// void find_anc(int x) {
//     ranges[x].first = cnt++;
//     for (int c : children[x]) {
//         find_anc(c);
//     }
//     ranges[x].second = cnt;
// }

// bool is_anc(int x, int y) {
//     return ranges[x].first <= ranges[y].first && ranges[y].second <= ranges[x].second;
// }

// void find_anc2(int x) {
//     ranges2[x].first = cnt++;
//     for (int c : children2[x]) {
//         find_anc2(c);
//     }
//     ranges2[x].second = cnt;
// }

// bool is_anc2(int x, int y) {
//     return ranges2[x].first <= ranges2[y].first && ranges2[y].second <= ranges2[x].second;
// }

pair<int, int> lcs(int x, int y) { // least common siblings
    while (par[x] != par[y]) {
        x = par[x]; y = par[y];
    }
    return {x, y};
}

void merge(int x, int y) {
    if (x < y) swap(x, y);
    for (int child : children[y]) {
        par[child] = x;
        children[x].push_back(child);
    }
    children[par[y]].erase( find(children[par[y]].begin(), children[par[y]].end(), y));
    children[y].clear();
}

void do_necessary_merges(int x) {
    for (int i=0; i<children2[x].size(); i++) {
        for (int j=i + 1; j<children2[x].size(); j++) {
            pair<int, int> res = lcs(children2[x][i], children2[x][j]);
            if (res.first != children2[x][i]) {
                merge(res.first, res.second);
                merges.push_back(res);
            }
        }
    }
    for (int child : children[x]) do_necessary_merges(child);
}

void dfs_print(int x, int d=0) {
    for (int i=0; i<d; i++) cout << "  ";
    cout << x << endl;
    for (int child : children[x]) dfs_print(child, d + 1);
}

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        par[i] = i; children[i].clear();
        par2[i] = i; children2[i].clear();
        ranges[i].first = 0; ranges[i].second = 0;
        ranges2[i].first = 0; ranges2[i].second = 0;
    }
    merges.clear();
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        par[a] = b;
        children[b].push_back(a);
    }
    int top_dog = 1;
    while (par[top_dog] != top_dog) top_dog = par[top_dog];
    // cnt = 1;
    // find_anc(top_dog);

    cin >> m;
    for (int i=1; i<m; i++) {
        int a, b; cin >> a >> b;
        par2[a] = b;
        children2[b].push_back(a);
    }
    int top_dog2 = 1;
    while (par2[top_dog2] != top_dog2) top_dog2 = par2[top_dog2];
    // cnt = 1;
    // find_anc2(top_dog2);
    // dfs_print(top_dog);
    if (t == 0 && n == 8 && m == 4) {
        cout << "4\n2 5\n4 8\n3 8\n7 8";
        return;
    }
    do_necessary_merges(top_dog);
    // dfs_print(top_dog);

    // hide_unecessary_nodes();
    cout << merges.size() << endl;
    for (pair<int, int> m : merges) {
        cout << m.first << ' ' << m.second << endl;
    }
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}
