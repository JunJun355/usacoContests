/*
ID: 06jajun
TASK: haircut
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

const string NAME = "haircut";

const int MXN = 1e5+5;
const int INF = 1e9;

using ll = long long;

int n;
int as[MXN];
int fenwick[MXN];
int greater_and_before[MXN];
vector<int> sorted;

void add(int x) { for (x++; x<=n; x += (x&-x)) fenwick[x]++; }
int sum(int x) { int s=0; for (x++; x>0; x -= (x&-x)) s+=fenwick[x]; return s; }

ifstream fin (NAME + ".in");
ofstream fout (NAME + ".out");

int main() {
    fin >> n;
    for (int i=0; i<n; i++) {
        fin >> as[i];
        greater_and_before[i] = i - sum(as[i]);
        add(as[i]);
    }

    for (int i=0; i<n; i++) sorted.push_back(i);
    sort(sorted.begin(), sorted.end(), 
        [](int& a, int& b) {
            return as[a] < as[b];
        }
    );
    // for (int i : sorted) cout << i << '=' << as[i] << ' '; cout << endl;

    int i=0;
    ll ans=0;
    for (int j=0; j<n ; j++) {
        while (i < n && as[sorted[i]] < j) {
            ans += greater_and_before[sorted[i]];
            i++;
        }
        fout << ans << endl;
    }
}
