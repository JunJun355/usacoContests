/*
ID: 06jajun
TASK: sort
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <set>

using namespace std;

#define MXN 100000
#define INF 1000000000

int n;
pair<int, int> arr[MXN];
// map<int, int> ids;
set<int> le;
ifstream fin ("sort.in");
ofstream fout ("sort.out");

// struct cmpA {
//   bool operator()(int a, int b) const {
//     if (ids[a] == ids[b]) return a < b;
//     return ids[a] < ids[b];
//   }
// };

int main() {
  // Get inputs
  fin >> n;
  for (int i=0; i<n; i++) {
    int ne;
    fin >> ne;
    arr[i] = {ne, i};
  }
  sort(arr, arr+n);
  // for (int i=0; i<n; i++) cout << arr[i] << ' ';

  int ans = 0;
  int curr = -1;
  for (int i=0; i<n-ans; i++) {
    // if (arr[i] > i) {
    //   curr++;
    // } else if (arr[i] < i) {
    //   curr--;
    // }
    le.insert(arr[i].second);
    if (*(le.begin()) <= i) {
      curr++;
      le.erase(le.begin());
    }
    // cout << endl << curr;
    ans = max(ans, i - curr);
  }

  fout << max(ans, 1) << endl;
}
