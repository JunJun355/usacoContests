/*
ID: 06jajun
TASK: template
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define MXN 200005
#define INF 2e9
#define ll long long

long long L, R, num;
char froms[MXN];
string tos[MXN];
char ans[MXN];
vector<pair<pair<long long, int>, char>> mapi[MXN];

void process() {
    map<char, pair<long long, int>> temp;
    for (int i=num - 1; i>=0; i--) {
        char from = froms[i];
        string to = tos[i];
        long long len = 0;
        for (char c : to) {
            if (temp.find(c) == temp.end()) {
                mapi[i].push_back(make_pair(make_pair(1, -1), c));
                len++;
            }
            else {
                mapi[i].push_back(make_pair(temp[c], c));
                len += temp[c].first;
            }
        }
        temp[from] = make_pair(len, i);
    }
    /*int count=0;
    for (vector<pair<pair<long long, int>, char>> v : mapi) {
        count++;
        if (count == 10) break;
        for (pair<pair<long long, int>, char> p : v) cout << p.first.first << '-' << p.first.second << '-' << p.second << ' ';
        cout << endl;
    }*/
}

void find(long long nstart, long long l, long long r, int i, char ch) {
    // cout << nstart << ' ' << l << ' ' << r << ' ' << i << ' ' << ch << endl;
    if (i == -1) {
        // ans[start - L] = ch;
        cout << ch;
        return;
    }
    // long long nstart = start;
    for (auto s : mapi[i]) {
        long long length = s.first.first;
        int ind = s.first.second;
        char c = s.second;
        long long top = nstart + length - 1;
        if ((l <= top) && (nstart <= r)) {
            // cout << nstart << top << endl;
            find(nstart, max(l, nstart), min(r, top), ind, c);
        }

        nstart += length;
    }
}

int main() {
    cin >> L >> R >> num;
    for (int i=0; i<num; i++) cin >> froms[i] >> tos[i];

    process();

    int starting_index = 0;
    while (froms[starting_index] != 'a') starting_index++;
    find(1, L, R, starting_index, 'a');

    // for (int i=0; i<R-L+1; i++) {
    //     cout << ans[i];
    // }
    cout << endl;
}
