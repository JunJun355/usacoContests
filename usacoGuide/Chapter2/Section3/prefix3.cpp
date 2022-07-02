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
#include <tuple>

using namespace std;

#define MXN 1e3+1;
#define INF 1e9;

struct Node {
  map<char, Node*> children;
  char letter;
};

struct State {
  int i;
  vector<int> path;
};

int m;
Node root;
string code="";
map<int, int> dfs_cache;
vector<string> primitives;
ifstream fin ("prefix.in");
ofstream fout ("prefix.out");

int non_recursive_dfs() {
  vector<State> stack;
  State start; start.i = 0;
  stack.push_back(start);
  while (!stack.empty()) {
    State curr = stack.back(); stack.pop_back();
    // for (int x : curr.path) cout << x << ' ';
    // cout << endl;
    if (dfs_cache.find(curr.i) != dfs_cache.end()) continue;
    Node* tip = &root;
    State ne;
    ne.i = curr.i; ne.path = curr.path;
    ne.path.push_back(curr.i);
    while (tip->children.find(code[ne.i]) != tip->children.end()) {
      tip = tip->children[code[ne.i]];
      ne.i += 1;
      if (tip->children.find('.') != tip->children.end()) {
        stack.push_back(ne);
      }
    }
    if (tip->children.find('.') != tip->children.end()) {
      stack.push_back(ne);
    }
    else {
      for (vector<int>::iterator itr=ne.path.begin(); itr!=ne.path.end(); itr++) {
        dfs_cache[*itr] = max(curr.i, dfs_cache[*itr]);
      }
    }
  }
  return dfs_cache[0];
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
  root.letter = '.';
  for (string primitive : primitives) {
    Node* tip = &root;
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

  // for (auto x: root.children) cout << x.first << ' ' ;
  // cout << endl;

  // dfs
  fout << non_recursive_dfs() << endl;
  return 0;
}
