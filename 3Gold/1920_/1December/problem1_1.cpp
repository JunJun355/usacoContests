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
#include <tuple>
#include <set>
#include <map>

using namespace std;

#define MXN 1001
#define INF 1000000000

using tii = tuple<int, int, int, int>;
using ti = tuple<int, int, int>;


int n, m;
vector<ti> edges;
vector<ti> adj[MXN];
ifstream fin ("pump.in");
ofstream fout ("pump.out");

int dist[MXN];
int bfs() {
    for (int i=0; i<MXN; i++) dist[i] = INF;
    priority_queue<ti> q;
    q.push({1, 0, 0});
    while (!q.empty()) {
        ti cur = q.front(), q.pop();
        int ne = cur.get(0), co = cur.get(1), fl = cur.get(2);

    }
}

int main() {
    fin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c, f;
        fin >> a >> b >> c >> f;
        edges.push_back({a, b, c, f});
    }
    sort (edges.begin(), edges.end(),
        [](ti a, ti b) {
            return a.get(2) < b.get(2);
        }
    );
    int i=0, ans=0;
    for (int flow=0; flow < 1000; flow++) {
        while (edges[i].get(2) <= flow) {
            adj[edges[i].get(0)].push_back({edges[i].get(1), edges[i].get(2), edges[i].get(3)});
            adj[edges[i].get(1)].push_back({edges[i].get(0), edges[i].get(2), edges[i].get(3)});
        }


    }
}
