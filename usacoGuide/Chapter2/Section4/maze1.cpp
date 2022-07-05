/*
ID: 06jajun
TASK: maze1
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <deque>

using namespace std;

#define MXW 38
#define MXH 100
#define INF 1e9

struct State {
  int x, y, i;
};

int w, h, W, H;
char maze[2*MXH+1][2*MXW+1];
fstream f;
ifstream fin ("maze1.in");
ofstream fout ("maze1.out");

int dfs() {
  int ans = 0;
  deque<State> to_search;
  set<pair<int, int>> searched;
  // Find entrances
  for (int i=1; i<2*h+1; i+=2) {
    // cout << maze[i][0] << endl;
    if (maze[i][0] == ' ') {
      State ne; ne.x=1; ne.y=i; ne.i=1;
      to_search.push_back(ne); searched.insert(make_pair(ne.x, ne.y));
    }
    // cout << maze[i][2*w] << endl;
    if (maze[i][2*w] == ' ') {
      State ne; ne.x=2*w-1; ne.y=i; ne.i=1;
      to_search.push_back(ne); searched.insert(make_pair(ne.x, ne.y));
    }
  }
  for (int j=1; j<2*w+1; j+=2) {
    // cout << maze[0][j] << endl;
    if (maze[0][j] == ' ') {
      State ne; ne.x=j; ne.y=1; ne.i=1;
      to_search.push_back(ne); searched.insert(make_pair(ne.x, ne.y));
    }
    // cout << maze[2*h][j] << endl;
    if (maze[2*h][j] == ' ') {
      State ne; ne.x=j; ne.y=2*h-1; ne.i=1;
      to_search.push_back(ne); searched.insert(make_pair(ne.x, ne.y));
    }
  }
  // cout << to_search.empty();
  // Start dfs
  while (!to_search.empty()) {
    State curr = to_search.front(); to_search.pop_front();
    ans = max(ans, curr.i);
    cout << curr.x << ' ' << curr.y << ' ' << curr.i << endl;
    // Find neighbors
      // N
        if (curr.y > 2 && maze[curr.y-1][curr.x] == ' ' && searched.find(make_pair(curr.x, curr.y-2)) == searched.end()) {
          State ne; ne.x=curr.x; ne.y=curr.y-2; ne.i=curr.i+1;
          to_search.push_back(ne);
          searched.insert(make_pair(ne.x, ne.y));
        }
      // E
        if (curr.x < 2*w-2 && maze[curr.y][curr.x+1] == ' ' && searched.find(make_pair(curr.x+2, curr.y)) == searched.end()) {
          State ne; ne.x=curr.x+2; ne.y=curr.y; ne.i=curr.i+1;
          to_search.push_back(ne);
          searched.insert(make_pair(ne.x, ne.y));
        }
      // S
        if (curr.y < 2*h-2 && maze[curr.y+1][curr.x] == ' ' && searched.find(make_pair(curr.x, curr.y + 2)) == searched.end()) {
          State ne; ne.x=curr.x; ne.y=curr.y+2; ne.i=curr.i+1;
          to_search.push_back(ne);
          searched.insert(make_pair(ne.x, ne.y));
        }
      // W
        if (curr.x > 2 && maze[curr.y][curr.x-1] == ' ' && searched.find(make_pair(curr.x-2, curr.y)) == searched.end()) {
          State ne; ne.x=curr.x-2; ne.y=curr.y; ne.i=curr.i+1;
          to_search.push_back(ne);
          searched.insert(make_pair(ne.x, ne.y));
        }

  }
  return ans;
}
int main() {
  fin >> w >> h;
  fin.close();
  f.open("maze1.in", ios::in);
  string scrap_line;
  getline(f, scrap_line);
  W = 2*w+1;
  H = 2*h+1;
  for (int i=0; i<H; i++) {
    string ne;
    getline(f, ne);
    for (int j=0; j<W; j++) {
      maze[i][j] = ne[j];
    }
  }
  // for (int i=0; i<H; i++) {
  //   for (int j=0; j<W; j++) {
  //     cout << maze[i][j] << ' ';
  //   }
  //   cout << endl;
  // }fout << 0;
  fout << dfs() << endl;
}
