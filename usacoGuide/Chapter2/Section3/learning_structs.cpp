/*
ID: 06jajun
TASK: prefix
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <string>

using namespace std;

#define MXN 1e3+1;
#define INF 1e9;

int n, m;
string code;
vector<string> primitives;
ifstream fin ("prefix.in");
ofstream fout ("prefix.out");

struct Node {
  bool operator<(Node other) const {
    return this->letter < other.letter;
  }
  set<int> children;
  char letter;
};

int main() {
  // Get inputs
  string ne;
  fin >> ne;
  while (ne != ".") {
    primitives.push_back(ne);
    fin >> ne;
  }
  fin >> code;

  // Create trie
  Node root;
  root.letter = '.';
  root.children.insert(1);
  root.children.insert(2);
  root.children.insert(3);
  root.children.insert(2);
  for (auto ne : root.children) cout << ne << ' ';
  // for (auto prim : primitives) {
  //   int i=0;
  //   Node tip = root;
  //   while (tip.children.find(prim[i]) != tip.children.end()) {
  //     i += 1;
  //     tip = *tip.children.find(prim[i]);
  //   }
  //   while (i < prim.length()) {
  //     i += 1;
  //     Node ne;
  //     ne.letter = prim[i];
  //     tip.children.insert(ne);
  //     tip = ne;
  //   }
  // }
  // for (Node ne : root.children) {
  //   cout << ne.letter << ' ';
  // }
}
