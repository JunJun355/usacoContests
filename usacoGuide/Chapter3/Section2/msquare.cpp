/*
ID: 06jajun
TASK: msquare
LANG: C++17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int dist[40320];

int encode(int *board)
 {
  static int mult[8] =
    {1, 8, 8*7, 8*7*6, 8*7*6*5,
     8*7*6*5*4, 8*7*6*5*4*3, 8*7*6*5*4*3*2};

  int look[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int rlook[8] = {0, 1, 2, 3, 4, 5, 6, 7};

  int lv, rv;
  int t;

  rv = 0;
  for (lv = 0; lv < 8; lv++)
   {
    t = look[board[lv]];
    rv += t * mult[lv];


    look[rlook[7-lv]] = t;
    rlook[t] = rlook[7-lv];
   }
  return rv;
 }

static int tforms[3][8] = { {8, 7, 6, 5, 4, 3, 2, 1},
     {4, 1, 2, 3, 6, 7, 8, 5}, {1, 7, 2, 4, 5, 3, 6, 8} };

void do_trans(int *inboard, int *outboard, int t)
 {
  int lv;
  int *tform = tforms[t];

  for (lv = 0; lv < 8; lv++)
    outboard[lv] = inboard[tform[lv]-1];
 }

void do_rtrans(int *inboard, int *outboard, int t)
 {
  int lv;
  int *tform = tforms[t];

  for (lv = 0; lv < 8; lv++)
    outboard[tform[lv]-1] = inboard[lv];
 }

int queue[40325][8];
int qhead, qtail;

void do_dist(int *board)
 {
  int lv;
  int t1;
  int d, t;

  qhead = 0;
  qtail = 1;

  for (lv = 0; lv < 8; lv++) queue[0][lv] = board[lv];
  dist[encode(queue[0])] = 1;

  while (qhead < qtail)
   {
    t1 = encode(queue[qhead]);
    d = dist[t1];

    for (lv = 0; lv < 3; lv++)
     {
      do_rtrans(queue[qhead], queue[qtail], lv);

      t = encode(queue[qtail]);
      if (dist[t] == 0)
       {
        qtail++;
        dist[t] = d+1;
       }
     }

    qhead++;
   }
 }

void walk(FILE *fout)
 {
  int newboard[8];
  int cboard[8];
  int lv, lv2;
  int t, d;

  for (lv = 0; lv < 8; lv++) cboard[lv] = lv;
  d = dist[encode(cboard)];

  while (d > 1)
   {
    for (lv = 0; lv < 3; lv++)
     {
      do_trans(cboard, newboard, lv);
      t = encode(newboard);
      if (dist[t] == d-1)
       {

        fprintf (fout, "%c", lv+'A');

        for (lv2 = 0; lv2 < 8; lv2++) cboard[lv2] = newboard[lv2];
	break;
       }
     }
    d--;
   }
  fprintf (fout, "\n");
 }

int main(int argc, char **argv)
 {
  FILE *fout, *fin;
  int board[8];
  int lv;

  fin = fopen("msquare.in", "r");
  fout = fopen("msquare.out", "w");

  for (lv = 0; lv < 8; lv++)
   {
    fscanf (fin, "%d", &board[lv]);
    board[lv]--;
   }

  do_dist(board);

  for (lv = 0; lv < 8; lv++) board[lv] = lv;

  fprintf (fout, "%d\n", dist[encode(board)]-1);
  walk(fout);

  return 0;
 }
