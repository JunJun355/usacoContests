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

const int N = (int)1e5;

int weights[N], places[N];
int order[N];

int t, n, k;

int main() {
    cin >> t >> n >> k;

    for (int i=0; i<n; i++) {
        order[i] = i;
        cin >> places[i] >> weights[i];
    }
    sort(order, order + n, [](int a, int b) {
        if (places[a] == places[b]) return a < b;
        return places[a] < places[b];
    });

    // for (int i=0; i<n; i++) {
    //     cout << order[i] << ' ';
    // }cout << endl;


}