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

#define MXN 200000
#define INF 1e9

struct Node {
  map<char, Node*> children;
  char letter;
};

int m, ans;
bool dp[MXN];
Node root;
string code="";
vector<string> primitives;
ifstream fin ("prefix.in");
ofstream fout ("prefix.out");

int dpf() {
  for (int i=0; i<m; i++) dp[i] = false;
  dp[0] = true;
  for (int i=0; i<m; i++) {
    int j=0;
    if (not dp[i]) continue;
    // cout << i << endl;
    Node* tip = &root;
    while (i+j < m && tip->children.find(code[i+j]) != tip->children.end()) {
      // cout << i+j+1 << ' ';
      if (tip->children[code[i+j]]->children.find('.') != tip->children[code[i+j]]->children.end()) {
        dp[i+j+1] = true;
        ans = max(ans, i+j+1);
        // cout << "--";
      }
      tip = tip->children[code[i+j]];
      j++;
    }
    // cout << endl;
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
  m = code.length();

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
  fout << dpf() << endl;
  return 0;
}
