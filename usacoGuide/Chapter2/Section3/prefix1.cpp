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

// struct Node;
//
// struct cmpA {
//   bool operator()(Node a, Node b) const {
//     return a.letter < b.letter;
//   }
// };

struct Node {
  set<Node> children;
  char letter;

  bool operator<(Node other) const {
    return this->letter < other.letter;
  }
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
  // Node * tip = &root;
  // root.letter = 'x';
  // cout << tip->letter;
  // tip -> letter = 's';
  // cout << root.letter;
  for (auto prim : primitives) {
    cout << "------" << prim << endl;
    int i=0;
    Node *tip = &root;
    Node le;
    le.letter = prim[i];
    // set<Node>::iterator itr;
    while (tip->children.find(le) != tip->children.end()) {
      tip = const_cast<Node*>(&*(tip->children.find(le)));
      i += 1;
      if (i >= prim.length()) break;
      le.letter = prim[i];
    }
    // cout << i << endl;
    while (i < prim.length()) {
      Node ne;
      ne.letter = prim[i];
      tip->children.insert(ne);
      tip = &ne;
      cout << tip-> letter << tip << endl;
      cout << tip -> children.size() << endl;
      if (!(tip->children.empty())) {
        for (auto x : tip->children)
          cout << x.letter << ' ';
        cout << endl;
      }

      i += 1;
    }
    cout << tip->letter << tip << endl;
    cout << root.letter << endl;
    cout << tip->children.size() << endl;
    tip->children.insert(root);
  }
  for (Node ne : root.children) {
    cout << ne.letter << ' ';
  }
}
