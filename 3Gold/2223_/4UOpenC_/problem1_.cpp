

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

const int MXN = 1e5+5;
const int INF = 1e9;

int t, n, m;
int room_color[MXN];
int room_need[MXN];
int room_start[MXN];
vector<int> edges[MXN];
queue<int> to_check[MXN];
bool key[MXN], room[MXN];

int dependents[MXN];
int self_dependents[MXN];
queue<int> blocked[MXN];

void process(int x) {
    room[x] = true;
    key[room_start[x]] = true;
    while (to_check[room_start[x]].size()) {
        int ne = to_check[room_start[x]].front();
        to_check[room_start[x]].pop();
        process(ne);
    }
    for (int child : edges[x]) if (!room[child]) {
        if (key[room_color[child]]) {
            process(child);
        }
        else {
            to_check[room_color[child]].push(child);
        }
    }
}

void process2() {
    for (int i=2; i<=n; i++) {
        if (room[i]) {
            dependents[room_color[i]]++;
            if (room_color[i] == room_need[i]) self_dependents[room_color[i]]++;
            // cout << i << ' ' << room_need[i] << ' ' << room_color[i] << ' ';
            blocked[room_need[i]].push(i);
        }
    }
    // cout << endl;
}

void process3(int x) {
    dependents[room_color[x]] = max(0, dependents[room_color[x]] - 1);
    if (dependents[room_color[x]] == self_dependents[room_color[x]]) {
        while (blocked[room_color[x]].size()) {
            int ne = blocked[room_color[x]].front();
            blocked[room_color[x]].pop();
            process3(ne);
        }
    }
}

bool search() {
    process(1);
    for (int i=1; i<=n; i++) {
        if (room_start[i] == room_need[i] || room[i]) continue;
        return false;
    }

    process2();

    for (int i=1; i<=n; i++) {
        if (dependents[i] == self_dependents[i]) {
            while (blocked[i].size()) {
                int ne = blocked[i].front();
                blocked[i].pop();
                cout << ne << 'n';
                process3(ne);
            }
        }
        else cout << i << ' ' << dependents[i] << ' ' << self_dependents[i] << "  ";
    }
    // cout << endl;
    // for (int i=1; i<=n; i++) {
    //     if (room_color[i] == room_need[i]) color[room_color[i]] = max(0, color[room_color[i]] - 1);
    // }
    for (int i=1; i<=n; i++) {
        // cout << color[i] << ' ';
        if (dependents[i] != self_dependents[i]) {
            // cout << endl;
            return false;
        }
    }
    // cout << endl;
    return true;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) cin >> room_color[i];
        for (int i=1; i<=n; i++) cin >> room_start[i];
        for (int i=1; i<=n; i++) cin >> room_need[i];
        for (int i=1; i<=n; i++) edges[i].clear();
        for (int i=0; i<m; i++) {
            int a, b; cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        for (int i=0; i<MXN; i++) key[i] = 0, room[i] = 0;
        cout << (search() ? "YES" : "NO") << endl;
    }
}
