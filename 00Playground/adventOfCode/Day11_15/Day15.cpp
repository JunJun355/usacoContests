#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("Day15.in");

int main() {
  vector<vector<int>> coor;
  for (int i = 0; i < 23; i++) {
    vector<int> ne;
    for (int i = 0; i < 4; i++) {
      int a;
      fin >> a;
      // cout << a << ' ';
      ne.push_back(a);
    }
    // cout << endl;
    coor.push_back(ne);
  }
  int i;
  for (i = 0; i < 4000000; i++) {
    vector<pair<int, int>> covered;
    for (int j = 0; j < 23; j++) {
      vector<int> curr = coor[j];
      int manhattan_dist = abs(curr[2] - curr[0]) + abs(curr[3] - curr[1]);
      int start = curr[0] - (manhattan_dist - abs(i - curr[1]));
      int end = curr[0] + (manhattan_dist - abs(i - curr[1]));
      if (start <= end)
        covered.push_back(make_pair(start, end));
    }
    sort(covered.begin(), covered.end());
    int end = covered[0].first;
    for (pair<int, int> x : covered) {
      if (end < x.first) {
        cout << i << ' ' << end << ' ' << x.first << endl;
        return 0;
      }
      if (end > 4000000) break;
      end = max(end, x.second);
      // cout << x.first << ' ' << x.second << ' ' << end << endl;
    }
  }
  cout << i << endl;
}
