#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define N 15919

ifstream fin ("word_list.txt");
string words[N];
int n=0;

struct Node {
  map<char, Node*> children;
  char letter;
};

Node root;
bool nope[27];
char s[30];

int ctoi(char a) {
  return max(0, a - 'a' + 1);
}

void dfs(int d=0, Node* tip=&root) {
  n++;
  if (n % 10000000 == 0) cout << n / 10000000;
  s[d] = tip->letter;
  // for (int i=0; i<d+1; i++) cout << s[i];
  // cout << endl;

  // cout << '-' << d;
  // for (auto x:s) cout << x;
  // cout << ' ';
  // for (auto x:nope) cout << x;
  // cout << endl;
  if (d == 29) {
    for (int i=0; i<30; i++) {
      cout << s[i];
    }
    cout << endl;
    return;
  }
  if (d % 6 != 5 && d % 6 != 0) {
    for (auto x : tip->children) {
      if (nope[ctoi(x.first)]) {
        continue;
      }
      // cout << nope[ctoi(x.first)]<<x.first<<ctoi(x.first);
      nope[ctoi(x.second->letter)] = true;
      dfs(d+1, x.second);
      nope[ctoi(x.second->letter)] = false;
    }
  } else if (d % 6 == 0) {
    for (auto x : tip->children) {
      if (nope[ctoi(x.first)] || (d != 0 && x.first < s[d - 5])) {
        continue;
      }
      // cout << nope[ctoi(x.first)]<<x.first<<ctoi(x.first);
      nope[ctoi(x.second->letter)] = true;
      dfs(d+1, x.second);
      nope[ctoi(x.second->letter)] = false;
    }
  } else {
    dfs(d+1);
  }
}

int main() {
  for (int i=0; i<N; i++) {
    fin >> words[i];
  }
  for (int i=0; i<27; i++) nope[i] = false;
  nope[0] = true;
  root.letter = ' ';
  for (string word : words) {
    Node *tip = &root;
    int i=0;
    // First letter of word
    char le = word[i];
    int n = word.length();
    // skip populated chars
    while (tip->children.find(le) != tip->children.end()) {
      tip = tip->children[le];
      i += 1;
      if (i==n) break;
      le = word[i];
    }
    // populate remaining chars
    while (i < n) {
      Node* ne = new Node();
      ne->letter = le;
      tip->children[le] = ne;
      tip = tip->children[le];
      i += 1;
      if (i==n) break;
      le = word[i];
    }
    tip->children[' '] = &root;
  }
  // cout << root.children.size() <<endl;
  // cout << root.children['z']->children.size() << endl;

  dfs();
  // nope[1] = true;
  // cout << 'a' << nope[ctoi('a')] << endl;
}
