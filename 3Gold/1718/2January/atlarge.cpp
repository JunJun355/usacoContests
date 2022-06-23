/*
ID: 06jajun
TASK: atlarge
LANG: C++17
*/

// * ->

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define MXN 100001
#define INF 1000000000

int N,K;
vector<int> edges[MXN];
vector<int> trace;
bool check[MXN] = {false};
int ans;


void search(int barn) {
  trace.push_back(barn);
  // for (auto x: trace) {
  //   cout << x << ' ';
  // }
  cout << endl;
  bool t=false;
  for (int nbarn : edges[barn]) {
    if (nbarn == trace[trace.size() - 2]) continue;
    search(nbarn);
    trace.pop_back();
    t = true;
  }
  if (!t) {
    check[trace[(trace.size()) / 2]]=true;
  }
}

void fsearch(int barn) {
  trace.push_back(barn);
  // cout << barn << ' ';
  if (check[barn]) {
    ans++;
    return;
  }
  for (int nbarn : edges[barn]) {
    if (nbarn == trace[trace.size() - 2]) continue;
    fsearch(nbarn);
    trace.pop_back();
  }
}


int main()
{
  ifstream fin ("atlarge.in");
  ofstream fout ("atlarge.out");

  fin >> N >> K;
  for (int i=0, a=0, b=0; i < N - 1; i++) {
    fin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  search(K);
  trace.clear();
  fsearch(K);
  fout << ans;
}
