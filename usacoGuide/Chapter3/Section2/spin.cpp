/*
ID: 06jajun
TASK: spin
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 1000
#define INF 1000000000

struct Wedge {
  int start, extent, end;
};

struct Wheel {
  int speed, nwedges;
  int rotation = 0;
  Wedge* wedges[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
};

Wheel* wheels[5];
ifstream fin ("spin.in");
ofstream fout ("spin.out");

int main() {
  // Get inputs
  for (int i=0; i<5; i++) wheels[i] = new Wheel();
  for (int i=0; i<5; i++) {
    fin >> wheels[i]->speed >> wheels[i]->nwedges;
    for (int j=0; j<wheels[i]->nwedges; j++) {
      wheels[i]->wedges[j] = new Wedge();
      fin >> wheels[i]->wedges[j]->start >> wheels[i]->wedges[j]->extent;
      wheels[i]->wedges[j]->end = wheels[i]->wedges[j]->start + wheels[i]->wedges[j]->extent;
    }
  }

  // Simulate spinning
  for (int i=0; i<360; i++) {
    // Check overlap
    short int tog[360];
    for (int j=0; j<360; j++) {
      tog[j] = 0;
    }
    for (auto wheel : wheels) {
      for (int k = 0; k < 5; k++) {
        if (wheel->wedges[k] == nullptr) break;
        for (int m=0; m<=wheel->wedges[k]->extent; m++) {
          tog[(wheel->rotation+wheel->wedges[k]->start+m)%360]++;
        }
      }
    }
    for (int k=0; k<360; k++) {
      // cout << tog[k] << ' ' << k << "  ";
      if (tog[k] == 5) {
        fout << i << endl;
        return 0;
      }
    }

    // Rotate
    for (auto wheel : wheels) {
      wheel->rotation = (wheel->rotation + wheel->speed) % 360;
    }
  }
  fout << "none" << endl;
}
