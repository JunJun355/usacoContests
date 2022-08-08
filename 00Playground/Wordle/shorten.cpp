#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define N 1379

ifstream fin ("word_list_any.txt");
ofstream fout ("word_list.txt");

int main() {
  while (!fin.eof()) {
    string ne;
    fin >> ne;
    if (ne.length() == 5) fout << ne << endl;
  }
  fin.close();
  fout.close();
}
