/*
ID: 06jajun
TASK: ttwo
LANG: C++17
*/
// First try without any sample case testing!!! So, actually first try!

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

#define MXN 1e3+1
#define INF 1e9

struct Figure {
  int x, y, d; //d=[0, 1, 2, 3]==[N, E, S, W]
};

char field[10][10];
Figure cow, john;
ifstream fin ("ttwo.in");
ofstream fout ("ttwo.out");
bool states[10][10][4][10][10][4];

void move_cow() {
  if (cow.d == 0) {
    if (cow.y == 0 || field[cow.y - 1][cow.x] == '*') {
      cow.d += 1;
    }
    else {
      cow.y -= 1;
    }
  } else if (cow.d == 1) {
    if (cow.x == 9 || field[cow.y][cow.x + 1] == '*') {
      cow.d += 1;
    }
    else {
      cow.x += 1;
    }
  } else if (cow.d == 2) {
    if (cow.y == 9 || field[cow.y + 1][cow.x] == '*') {
      cow.d += 1;
    }
    else {
      cow.y += 1;
    }
  } else if (cow.d == 3) {
    if (cow.x == 0 || field[cow.y][cow.x - 1] == '*') {
      cow.d -= 3;
    }
    else {
      cow.x -= 1;
    }
  }
}

void move_john() {
  if (john.d == 0) {
    if (john.y == 0 || field[john.y - 1][john.x] == '*') {
      john.d += 1;
    }
    else {
      john.y -= 1;
    }
  } else if (john.d == 1) {
    if (john.x == 9 || field[john.y][john.x + 1] == '*') {
      john.d += 1;
    }
    else {
      john.x += 1;
    }
  } else if (john.d == 2) {
    if (john.y == 9 || field[john.y + 1][john.x] == '*') {
      john.d += 1;
    }
    else {
      john.y += 1;
    }
  } else if (john.d == 3) {
    if (john.x == 0 || field[john.y][john.x - 1] == '*') {
      john.d -= 3;
    }
    else {
      john.x -= 1;
    }
  }
}

int sim() {
  for (int i=1; ; i++) {
    move_cow();
    move_john();
    if (cow.x == john.x && cow.y == john.y) {
      return i;
    }
    else if (states[cow.x][cow.y][cow.d][john.x][john.y][john.d] == true) {
      return 0;
    }
    states[cow.x][cow.y][cow.d][john.x][john.y][john.d] = true;
  }
}

int main() {
  for (int i=0; i<10; i++) {
    string ne;
    fin >> ne;
    for (int j=0; j<10; j++) {
      field[i][j] = ne[j];
      if (ne[j] == 'F') {
        john.x=j; john.y=i; john.d=0;
      }
      else if (ne[j] == 'C') {
        cow.x=j; cow.y=i; john.d=0;
      }
    }
  }
  states[cow.x][cow.y][cow.d][john.x][john.y][john.d] = true;
  fout << sim() << endl;
}
