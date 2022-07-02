/*
ID: 06jajun
TASK: prefix
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <string>

using namespace std;

#define MXN 1e3+1
#define INF 1e9

int m;
string code="";
map<int, int> dfs_cache;
vector<string> primitives;
ifstream fin ("prefix.in");
ofstream fout ("prefix.out");

struct Node {
  map<char, Node*> children;
  char letter;

};

int dfs(int i, char le, Node* tip, int farthest=0) {
  // cout << i << ' ' << le << ' ' << code[i + 1] << endl;
  int ans = farthest;
  // If the current tip is the root, indicates end of previous primitive and moving on to the next
  // cout << 1 << endl;
  if (tip->letter == '.') {
    if (dfs_cache.find(i) != dfs_cache.end()) {
      return dfs_cache[i];
    }
    ans = i;
    if (tip->children.find(le) != tip->children.end()) {
      ans = dfs(i + 1, code[i + 1], tip->children[le], ans);
    }
    dfs_cache[i] = ans;
    return ans;
  }
  if (tip->children.find('.') != tip->children.end()) {
    ans = max(dfs(i, le, tip->children['.'], ans), ans);
  }
  if (tip->children.find(le) != tip->children.end()) {
    ans = max(dfs(i + 1, code[i + 1], tip->children[le], ans), ans);
  }
  return ans;
}

int main() {
  // Get primitives
  string ne;
  fin >> ne;
  while (ne != ".") {
    primitives.push_back(ne);
    fin >> ne;
  }
  // Get string code
  fin >> ne;
  while (not fin.eof()) {
    code += ne;
    fin >> ne;
  }
  code += "-";

  // Create trie
  Node root;
  root.letter = '.';
  for (string primitive : primitives) {
    Node *tip = &root;
    int i=0;
    // First letter of primitive
    char le = primitive[i];
    int n = primitive.length();
    // skip populated chars
    while (tip->children.find(le) != tip->children.end()) {
      tip = tip->children[le];
      i += 1;
      if (i==n) break;
      le = primitive[i];
    }
    // populate remaining chars
    while (i < n) {
      Node* ne = new Node();
      ne->letter = le;
      tip->children[le] = ne;
      tip = tip->children[le];
      i += 1;
      if (i==n) break;
      le = primitive[i];
    }
    tip->children['.'] = &root;
  }

  // dfs
  int i=0;
  char le=code[i];
  Node* tip = &root;
  fout << dfs(i, le, tip) << endl;
  return 0;
}
