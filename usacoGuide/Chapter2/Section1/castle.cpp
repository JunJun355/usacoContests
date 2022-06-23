/*
ID: 06jajun
TASK: castle
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 50
#define INF 1000000000

int n, m;
ifstream fin ("castle.in");
ofstream fout ("castle.out");

int castle[MXN][MXN];
int rooms[MXN][MXN];
bool searched[MXN][MXN];

int main() {
  // set-up
  fin >> m >> n;
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      fin >> castle[i][j];
  unordered_map<int, int> room_sizes;

  // number of rooms + largest room
  int curr = 0;
  for (int i=0; i<n; i++) for (int j=0; j < m; j++) {
    if (searched[i][j]) continue;
    searched[i][j] = true;
    vector<pair<int, int>> to_search;
    int tot = 1;
    to_search.push_back({i, j});
    while (!to_search.empty()) {
      pair<int, int> ne = to_search.back();
      to_search.pop_back();
      rooms[ne.first][ne.second] = curr;
      int val = castle[ne.first][ne.second];
      if (val % 2 == 0 && !searched[ne.first][ne.second - 1]){
        to_search.push_back({ne.first, ne.second - 1});
        tot += 1;
        searched[ne.first][ne.second - 1] = true;
      }
      val /= 2;
      if (val % 2 == 0 && !searched[ne.first - 1][ne.second]){
        to_search.push_back({ne.first - 1, ne.second});
        tot += 1;
        searched[ne.first - 1][ne.second] = true;
      }
      val /= 2;
      if (val % 2 == 0 && !searched[ne.first][ne.second + 1]){
        to_search.push_back({ne.first, ne.second + 1});
        tot += 1;
        searched[ne.first][ne.second + 1] = true;
      }
      val /= 2;
      if (val % 2 == 0 && !searched[ne.first + 1][ne.second]){
        to_search.push_back({ne.first + 1, ne.second});
        tot += 1;
        searched[ne.first + 1][ne.second] = true;
      }
    }
    room_sizes[curr] = tot;
    curr += 1;
  }
  int ma=0;
  for (int i=0; i<curr; i++) {
    ma = max(ma, room_sizes[i]);
  }
  fout << curr << endl << ma << endl;


  ma=0;
  string ret = "";
  // largest possible room + wall to remove
  for (int j=0; j < m; j++) {
    for (int i=n - 1; i >= 0; i--) {
      int room = rooms[i][j];
      // check north
      if (i != 0) {
        int new_room = rooms[i - 1][j];
        if (new_room != room) {
          if (ma < room_sizes[new_room] + room_sizes[room]) {
            ma = room_sizes[new_room] + room_sizes[room];
            ret = to_string(i + 1) + ' ' + to_string(j + 1) + ' ' + 'N';
          }
        }
      }
      // check east
      if (j != m - 1) {
        int new_room = rooms[i][j + 1];
        if (new_room != room) {
          if (ma < room_sizes[new_room] + room_sizes[room]) {
            ma = room_sizes[new_room] + room_sizes[room];
            ret = to_string(i + 1) + ' ' + to_string(j + 1) + ' ' + 'E';
          }
        }
      }
    }
  }
  fout << ma << endl << ret << endl;
}
