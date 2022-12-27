/*
	ID: 06jajun
	TASK: balance
	LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

#define LLINF 1000000000000
#define MXN 100000

long long n, best;
bool arr1[MXN], arr2[MXN];
ifstream fin ("balance.in");
ofstream fout ("balance.out");

void get_inputs() {
	fin >> n;
 	for (int i=0; i<n; i++) fin >> (arr1[i] == 1);
  	for (int j=0; j<n; j++) fin >> (arr2[j] == 1);
}

int inv(bool arr) {
	int ones = 0; int tot = 0;
	for (int i=0; i<n; i++) {
		if (arr[i]) ones += 1;
		else tot += ones;
	}
	return tot;
}

long long abs(long long a) {
	if (a < 0) return -a;
	return a;
}

void solve(bool yuh, int sign) {
	int invs1 = inv(arr1); int invs2 = inv(arr2);
	int dif = invs2 - invs1;

	int yuhs1 = 0; int yuhs2 = 0;
	for (int i=0; i<n; i++) if (arr1[i] == yuh) yuhs1++;
	for (int i=0; i<n; i++) if (arr2[i] != yuh) yuhs2++;

	int inter_moves = 0;
	int j = 0;
	for (int i=n-1; i>=0; i--) {
		if (arr1[i] == yuh) {
			inter_moves += (n - 1 - i);
			while (arr2[j] == yuh)
				j++;
			inter_moves += j;
			dif -= (n - 1 - i); dif -= j;
			dif -=
			best = min(best, inter_moves + dif);
		}
	}
}

int main() {
 	get_inputs();

	best = LLINF;

	solve(true, 1);

	solve(false, -1);

	fout << best << endl;
}
