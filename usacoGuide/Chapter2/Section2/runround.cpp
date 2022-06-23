/*
ID: 06jajun
TASK: runround
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <string>

using namespace std;

#define INF 1000000000

int m;
int best = INF;
bool digs[9];
string nums;
ifstream fin ("runround.in");
ofstream fout ("runround.out");

bool check() {
  int curr = 0;
  unordered_set<int> s;
  int n = nums.size();
  for (int i=0; i < n; i++) {
    curr = (curr + nums[curr]-48) % n;
    s.insert(curr);
  }
  if (s.size() == n) return true;
  return false;
}

void recurse() {
  if (nums.size() == 0) {
    for (int i=49; i < 58; i++) {
      nums.push_back(i);
      digs[i - 49] = true;
      recurse();
      digs[i - 49] = false;
      nums.pop_back();
    }
    return;
  }
  int numi = stoi(nums);
  if (numi > best) return;
  if ((numi > m) && (check())) best = numi;

  for (int i=49; i < 58; i++) {
    if (digs[i - 49]) continue;
    nums.push_back(i);
    digs[i - 49] = true;
    recurse();
    digs[i - 49] = false;
    nums.pop_back();
  }
}

int main() {
  fin >> m;
  for (int i=0; i < 9; i++) digs[i] = false;
  recurse();
  fout << best << endl;
  return 0;
}
