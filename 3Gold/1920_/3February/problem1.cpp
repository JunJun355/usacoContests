/*
ID: 06jajun
TASK: timeline
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

const string NAME = "timeline";

const int MXN = 1e5+1;
const int INF = 1e9;

int n, m, c;
int s[MXN], ini[MXN];
vector<pair<int, int>> edges[MXN];
queue<int> q;

ifstream fin (NAME + ".in");
ofstream fout (NAME + ".out");

int main() {
    fin >> n >> m >> c;
    for (int i=1; i<=n; i++) {
        fin >> s[i];
    }
    for (int i=0; i<c; i++) {
        int a, b, d;
        fin >> a >> b >> d;
        edges[a].push_back({b, d});
        ini[b]++;
    }
    for (int i=1; i<=n; i++) if (ini[i] == 0) q.push(i);
    while (q.size() > 0) {
        int curr = q.front(); q.pop();
        for (pair<int, int> ne : edges[curr]) {
            s[ne.first] = max(s[ne.first], s[curr] + ne.second);
            ini[ne.first]--;
            if (ini[ne.first] == 0) q.push(ne.first);
        }
    }

    for (int i=1; i<=n; i++) {
        fout << s[i] << endl;
    }
}
