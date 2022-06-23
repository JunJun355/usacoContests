/*
ID: 06jajun
TASK: sort3
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 1000
#define INF 1000000000

int n;
ifstream fin ("sort3.in");
ofstream fout ("sort3.out");
int initial[MXN];


int main() {
  fin >> n;
  int nums[3] = {0, 0, 0};
  for (int i=0; i < n; i++) {
    fin >> initial[i];
    nums[initial[i] - 1]++;
  }
  int dist[3][3];
  for (int i=0; i<3; i++) for (int j=0; j < 3; j++) dist[i][j] = 0;
  for (int i=0; i < nums[0]; i++) {
    dist[0][initial[i] - 1] ++;
  }
  for (int i=nums[0]; i < nums[0] + nums[1]; i++) {
    dist[1][initial[i] - 1] ++;
  }
  for (int i=nums[0] + nums[1]; i < n; i++) {
    dist[2][initial[i] - 1] ++;
  }
  int ans = 0;
  int m;
  // for (int i=0; i < 3; i++){ for (int j=0; j < 3; j++) {
  //   cout << dist[i][j] << ' ';} cout << endl;
  // }
  for (int i=1; i < 3; i++) for (int j=0; j < i; j++) {
    m = min(dist[i][j], dist[j][i]);
    ans += m;
    dist[i][j] -= m;
    dist[j][i] -= m;
  }
  ans += (dist[0][1] + dist[0][2]) * 2;
  fout << ans << endl;
}
