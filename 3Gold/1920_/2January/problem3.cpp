/*
ID: 06jajun
TASK: boards
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

const string NAME = "boards";

const int MXN = 1e9;
const int MXP = 1e5;
const int INF = 1e9;

int n, p;
int ans[MXP];
map<int,int> m;
ifstream fin (NAME + ".in");
ofstream fout (NAME + ".out");

void ins(int y, int v) {
	auto itr = prev(m.upper_bound(y));
	if (itr->second <= v) return;
	itr ++;
	while (itr != end(m) && itr->second > v) m.erase(itr++);
	m[y] = v;
}

int main() {
	fin >> n >> p;
    m[0] = 0;
	vector<pair<pair<int,int>,pair<int,bool>>> ev;
	for (int i = 0; i < p; i++) {
		pair<int,int> a,b;
		fin >> a.first >> a.second >> b.first >> b.second;
		ev.push_back({a,{i,true}}); // start point
		ev.push_back({b,{i,false}}); // end point
	}
	sort(begin(ev),end(ev));
	for (auto t: ev) {
		if (t.second.second) {
			ans[t.second.first] = t.first.first+t.first.second+prev(m.upper_bound(t.first.second))->second;
		} else {
			ins(t.first.second,ans[t.second.first]-t.first.first-t.first.second);
		}
	}
	fout << m.rbegin()->second+2*n;
}
