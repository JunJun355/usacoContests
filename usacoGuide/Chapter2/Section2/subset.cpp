/*
ID: 06jajun
TASK: subset
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 40
#define SUM 780
#define INF 1000000000

int n;
long long grid[MXN][SUM];
ifstream fin ("subset.in");
ofstream fout ("subset.out");

int main() {
  fin >> n;
  if (n % 4 == 1 || n % 4 == 2) {
    fout << 0 << endl;
    return 0;
  }
  for (int i=0; i <=n; i++) for (int j=0; j <= n * (n + 1) / 2; j++) grid[i][j] = 0;
  for (int i=1; i <= n; i++) {
    grid[i][i]++;
    for (int j=0; j <= n * (n + 1) / 2; j++) {
      grid[i][j] += grid[i - 1][j];
      if (j >= i) grid[i][j] += grid[i - 1][j - i];
    }
  }
  fout << grid[n][n * (n + 1) / 4] / 2 << endl;
}
