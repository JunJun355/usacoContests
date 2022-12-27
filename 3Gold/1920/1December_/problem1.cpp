/*
ID: 06jajun
TASK: pump
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

#define MXN 1001
#define MULT 1000000
#define INF 1000000000

int n, m, ans = INF;
map<int, vector<int>> nbrs;
map<pair<int, int>, double> edgecost;
map<pair<int, int>, double> edgeflow;
vector<int> flows;

ifstream fin ("pump.in");
ofstream fout ("pump.out");

double dijkstra(int mini) {
    int dist[MXN];
    set<int> to_search;
    for (int i=0; i<MXN; i++) dist[i] = INF;
    dist[1] = 0;
    to_search.insert(1);
    while (!to_search.empty()) {
        int curr = *to_search.begin();
        to_search.erase(to_search.begin());
        if (curr == n) return dist[n];
        for (int j : nbrs[curr]) {
            if (edgeflow[make_pair(curr, j)] < mini) continue;
            if (dist[j] > dist[curr] + edgecost[make_pair(curr, j)]) {
                dist[j] = dist[curr] + edgecost[make_pair(curr, j)];
                to_search.insert(j);
            }
        }
    }
    return -1;
}

int main() {
    fin >> n >> m;
    int a, b, c, d;
    for (int i = 0; i < m; i++) {
        fin >> a >> b >> c >> d;
        flows.push_back(d);
        nbrs[a].push_back(b);
        nbrs[b].push_back(a);
        edgecost[make_pair(a, b)] = edgecost[make_pair(b, a)] = c;
        edgeflow[make_pair(a, b)] = edgeflow[make_pair(b, a)] = d;
    }
    long long best_num = 0, best_den = 1, cur_num, cur_den;
    for (int f : flows) {
        cur_num = f;
        cur_den = dijkstra(f);
        if (cur_den != -1) {
            if (cur_num * best_den > best_num * cur_den) {
                best_num = cur_num; best_den = cur_den;
            }
        }
    }
    fout << best_num * 1000000LL / best_den << endl;
}
