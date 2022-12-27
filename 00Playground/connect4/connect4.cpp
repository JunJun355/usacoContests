#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

#define INF 1000000000

using namespace std;

char board[6][7];
int m = 0;
const bool ai_play = true;
const int ai_turn = 1, max_depth = 8;


void printb() {
    for (int i=0; i<6; i++) {
        cout << '|';
        for (int j=0; j<7; j++) {
            cout << ' ' << board[i][j];
        }
        cout << endl;
    }
    cout << '+';
    for (int j=0; j<14; j++) cout << '-';
    cout << endl << ' ';
    for (int j=0; j<7; j++) cout << ' ' << j + 1;
    cout << endl;
} // done

bool done(pair<int, int> move) {
    int y = move.first, x = move.second;
    int tot = 0;
    char thing = board[x][y];
    assert(thing != '.');

    // check down
    tot = 0;
    for (int i=x; i<min(x+4, 6); i++) {
        if (board[i][y] != thing) tot = 0;
        else tot++;
        if (tot == 4) return true;
    }

    // check left right
    tot = 0;
    for (int j=max(y - 3, 0); j < min(y + 4, 7); j++) {
        if (board[x][j] != thing) tot = 0;
        else tot++;
        if (tot == 4) return true;
    }

    // check left-down diagonal
    tot = 0;
    for (int i=max(-3, max(-x, -y)); i<min(4, min(6-x, 7-y)); i++) {
        if (board[x + i][y + i] != thing) tot = 0;
        else tot++;
        if (tot == 4) return true;
    }

    // check left-up diagonal
    tot = 0;
    for (int i=max(-3, max(x - 5, -y)); i<min(4, min(x, 7-y)); i++) {
        if (board[x - i][y + i] != thing) tot = 0;
        else tot++;
        if (tot == 4) return true;
    }

    return false;
} // done

bool make_move(int x, int& y) {
    if (board[0][x] != '.') return false;
    for (y=0; y<5; y++) {
        if (board[y + 1][x] != '.') break;
    }
    return true;
} // done

int evaluation(pair<int, int> move, int d=0) {
    // printb();
    int eval = INF;
    int sway = 0;
    // int x = move.first, y = move.second;


    if (done(move)) {
        // printb();
        eval = INF;
    }
    else if (d == max_depth) {
        eval = 0;
    }
    else {
        // int scores[8]; memset(scores, 0, sizeof scores);
        // eval = 7; scores[eval] = INT_MIN;
        for (int x=0; x<7; x++) {
            int y;
            if (make_move(x, y)) {
                board[y][x] = (m % 2 == 0) ? 'x' : 'o';
                m++;
                int curr = -evaluation(make_pair(x, y), d + 1);
                curr -= curr / abs(curr);
                // cout << curr << ' ';
                board[y][x] = '.';
                m--;
                eval = min(eval, curr);
                // if (eval <= -INF/2) break;
            }
        }
    }
    // cout << endl;
    // cout << eval << endl;
    if (d < 3 && abs(eval) >= INF / 2 && abs(eval) <= INF - 3) {
        printb();
        cout << eval << endl;
    }
    if (eval == 0) return sway;
    return eval;
} // NOT NOT NOT done NOT NOT NOT

int get_ai_move() {
    int scores[7]; memset(scores, -INF, sizeof scores);
    int choice, y;
    for (choice = 0;;choice++) if (make_move(choice, y)) break;
    for (int x=0; x<7; x++) {
        if (make_move(x, y)) {
            board[y][x] = (m % 2 == 0) ? 'x' : 'o';
            m++;
            scores[x] = evaluation(make_pair(x, y));
            // cout << scores[x] << ' ';
            board[y][x] = '.';
            m--;
            if (scores[choice] < scores[x]) choice = x;
        }
    }
    for (int score : scores) cout << score << ' ';
    cout << endl;
    cout << choice;
    return choice;
} // NOT NOT NOT done NOT NOT NOT

pair<int, int> get_move() {
    int x, y;
    do {
        if (ai_play && ai_turn == m % 2) x = get_ai_move();
        else {
            cout << "Enter move Player " << (m % 2 + 1) << ": ";
            cin >> x; x--;
        }
        if (make_move(x, y)) break;
        cout << "!Error" << endl;
    } while (false);
    return make_pair(x, y);
} // done

void setup() {
    memset(board, '.', sizeof(board));
    printb();
} // done

void game() {
    setup();
    pair<int, int> move;
    do {
        move = get_move();
        board[move.second][move.first] = (m % 2 == 0) ? 'x' : 'o';
        printb();
        m++;
    } while (!done(move) && m < 42);
    cout << "Player " << (m % 2) << " wins!";
    return ;
} // done

int main() {
    game();
    return 0;
} // done
