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

const int MXN = 2e5;
const int INF = 1e9;

int n, m = 6;
int costs[MXN];
string inp;
string match = "bessie";
vector<int> indices_to_check;
int dp[6][MXN];

int main() {
    cin >> inp;
    n = inp.length();
    for (int i=0; i<n; i++) cin >> costs[i];

    int ans = 0;
    int j = 0;
    for (int i=0; i<n; i++) {
        if (inp[i] == match[j]) {
            j = (j + 1) % m;
            if (j == 0) {
                ans++;
                indices_to_check.push_back(i);
            }
        }
    }
    cout << ans;
}
