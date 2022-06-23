/*
ID: 06jajun
TASK: pprime
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

#define MXN 100001
#define INF 1000000000

int a, b;
vector<int> ans;
ifstream fin ("pprime.in");
ofstream fout ("pprime.out");

bool is_prime(int x) {
  if (x % 2 == 0) return false;
  for (int i=3; i*i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

void reflect_n_check(string base, int dep) {
  // reflect
  string rev="";
  for (int i=dep - 1; i >= 0; i--) rev.push_back(base[i]);
  int c;
  if (dep != 0) {
    c = stoi(base + rev);
    if (c > b) return ;
    if (c >= a && is_prime(c)) ans.push_back(c);
  }

  for (char ch=48; ch!=':'; ch++) {
    c = stoi(base + ch + rev);
    if (c < a) continue;
    if (c > b) return ;
    if (is_prime(c)) ans.push_back(c);
  }
  return ;
}

void recurse(string base="", int dep=0) {
  if (dep == 4) return;
  reflect_n_check(base, dep);
  for (char c=48; c != ':'; c++) {
    base.push_back(c);
    recurse(base, dep + 1);
    base.pop_back();
  }
  return;
}

int main() {
  fin >> a >> b;
  recurse();
  sort(ans.begin(), ans.end());
  for (int a : ans) {
    fout << a << endl;
  }
}


// int a, b;
// vector<int> primes = {2};
//
// bool is_prime(int x) {
//   for (int i: primes)
//     if (x % i == 0)
//       return false;
//   return true;
// }
//
// bool is_palindrome(int p) {
//   string s = to_string(p);
//   // cout << s;
//   for (auto itr1=s.begin(), itr2=s.end(); itr1 != itr2; ) {
//     itr2--;
//
//     // cout << ' ' << *itr1 << ' ' << *itr2 << endl;
//     if (*itr1 != *itr2) return false;
//
//     if (itr1 == itr2) break;
//     itr1++;
//   }
//   return true;
// }
//
// int main()
// {
//   ifstream fin ("pprime.in");
//   ofstream fout ("pprime.out");
//
//   fin >> a >> b;
//   for (int i=3; i<=b; i+=2)
//     if (is_prime(i))
//       primes.push_back(i);
//   // for (int x: primes) cout << x << ' ';
//   // cout << endl;
//   for (int prime: primes) {
//     if (prime < a) continue;
//     if (is_palindrome(prime)) fout << prime << endl;
//   }
// }
