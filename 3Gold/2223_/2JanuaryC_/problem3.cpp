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

#define MXN 21
#define MOD 1000000007
#define ll long long
#define ull unsigned long long

int n;
int a[MXN];

int nCr(int n, int k) {
    if (k > n) return 0;
    if (2 * k > n) k = n - k;
    ull result = 1;
    for (int i=1; i<=k; i++) {
        result = (result * (n - i + 1) / i) % MOD;
    }
    return (int)result;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] % 2 != 0) return 1;
        a[i] = a[i] / 2;
    }
    if (n == 2) {
        int stars = abs(a[0] - a[1]), bars = min(a[0], a[1]) - 1;
        cout << nCr(stars + bars, bars) << endl;
    }
}
