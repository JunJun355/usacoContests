/*
ID: 06jajun
TASK: contact
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <string>

using namespace std;

#define MXN 50
#define INF 1e9
struct Node {
  Node* left=nullptr;
  Node* right=nullptr;
  int count=0;
};

int a, b, n;
Node* to_search[13];
Node* root = new Node();
string code;
map<int, vector<string>, greater<int>> counts;
ifstream fin ("contact.in");
ofstream fout ("contact.out");

bool cmp(string a, string b) {
  if (a.length() == b.length()) return a<b;
  return a.length() < b.length();
}

void recurse(Node* curr=root, string currstr="") {
  if (currstr.length() > b) return;
  if (curr->left != nullptr) {
    recurse(curr->left, currstr+"0");
  }
  if (curr->right != nullptr) {
    recurse(curr->right, currstr+"1");
  }
  if (currstr.length() < a) return;
  if (counts.find(curr->count) == counts.end()) {
    counts[curr->count] = vector<string>();
  }
  counts[curr->count].push_back(currstr);
}

int main() {
  // Get inputs
  fin >> a >> b >> n;
  string ne;
  fin >> ne;
  while (!fin.eof()) {
    code += ne;
    fin >> ne;
  }

  // Create counting trie
  for (int i=1; i<13; i++) to_search[i] = nullptr;
  to_search[0] = root;
  for (int i=0; i<code.length(); i++) {
    char curr = code[i];
    if (curr == '0') {
      // cout << 0 << endl;
      for (int j=min(i, b-1); j>=0; j--) {
        if (to_search[j]->left == nullptr) {
          Node* ne = new Node();
          to_search[j]->left = ne;
        }
        to_search[j]->left->count++;
        to_search[j+1] = to_search[j]->left;
      }
    } else if (curr == '1') {
      // cout << 1 << endl;
      for (int j=min(i, b-1); j>=0; j--) {
        if (to_search[j]->right == nullptr) {
          Node* ne = new Node();
          to_search[j]->right = ne;
        }
        to_search[j]->right->count++;
        to_search[j+1] = to_search[j]->right;
      }
    } else return 1;
  }

  // Add trie counts to map
  recurse();

  // Fout
  auto itr1 = counts.begin();
  for (int i=0; i<n; i++) {
    fout << itr1->first << endl;
    sort(itr1->second.begin(), itr1->second.end(), cmp);
    // for (auto itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++) {
    //   if (itr2 != itr1->second.begin()) fout << ' ';
    //   fout << *itr2;
    // }
    for (int i=0; i<itr1->second.size(); i++) {
      if (i % 6 != 0) fout << ' ';
      else if (i != 0) fout << endl;
      fout << itr1->second[i];
    }
    fout << endl;
    itr1++;
    if (itr1 == counts.end()) return 0;
  }
}
