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
int last_move = -1; // visual aid to see previous move when printing
const bool ai_play = true;
const int ai_turn = 1, max_depth = 7;


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
    if (last_move != -1) {
        string bottom(2 * (last_move + 1), ' ');
        cout << bottom << '^' << endl;
    }
    cout << endl;
} // done

int evaluation(pair<int, int> move) {
    int potential = 0;
    int potencies[3][4] = {{0, 1, 3, 5}, {0, 3, 5, 10}, {0, 3, 7, 10}};
    int x = move.first, y = move.second;
    // cout << x << ' ' << y << endl;
    int i, j, temp, curr;
    char thing = board[y][x];

    // up-down
    for (i=y; i<5; i++) {
        if (board[i + 1][x] != thing) break;
    }
    potential += potencies[0][i >= 3 ? i - y + 1 : 0];
    // cout << potential << ' ';

    // left-right
    i = x, j = x;
    while (max(x - 3, 0) < i && (board[y][i - 1] == thing || board[y][i - 1] == '.')) i--;
    while (min(x + 3, 6) > j && (board[y][j + 1] == thing || board[y][j + 1] == '.')) j++;
    curr = 0, temp = 0;
    if (j - i >= 3) for (int c = i; c <= j; c++) {
        if (c > i + 3) {
            if (board[y][c - 4] == thing) curr--;
        }
        if (board[y][c] == thing) curr++;
        temp = max(curr, temp);
    }
    potential += potencies[1][temp];
    // cout << potential << ' ';

    // left-down diagonal
    i = 0, j = 0;
    while (max(-3, max(-x, -y)) < i && (board[y + i - 1][x + i - 1] == thing || board[y + i - 1][x + i - 1] == '.')) i--;
    while (min(3, min(6-x, 5-y)) > j && (board[y + j + 1][x + j + 1] == thing || board[y + j + 1][x + j + 1] == '.')) j++;
    curr = 0, temp = 0;
    if (j - i >= 3) for (int c = i; c <= j; c++) {
        if (c > i + 3) {
            if (board[y + c - 4][x + c - 4] == thing) curr--;
        }
        if (board[y + c][x + c] == thing) curr++;
        temp = max(curr, temp);
    }
    potential += potencies[2][temp];
    // cout << potential << ' ';

    // left-up diagonal
    i = 0, j = 0;
    while (max(-3, max(1-x, y-5)) < i && (board[y - i + 1][x + i - 1] == thing || board[y - i + 1][x + i - 1] == '.')) i--;
    while (min(3, min(6-x, y)) > j && (board[y - j - 1][x + j + 1] == thing || board[y - j - 1][x + j + 1] == '.')) j++;
    curr = 0, temp = 0;
    if (j - i >= 3) for (int c = i; c <= j; c++) {
        if (c > i + 3) {
            if (board[y - c + 4][x + c - 4] == thing) curr--;
        }
        if (board[y - c][x + c] == thing) curr++;
        temp = max(curr, temp);
    }
    potential += potencies[2][temp];
    // cout << potential << ' ';

    // cout << endl;
    return potential;
}

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

int search(pair<int, int> move, int d=0) {
    // printb();
    int eval = INF;
    // int x = move.first, y = move.second;


    if (done(move)) {
        // printb();
        eval = INF - d * 1000;
    }
    else if (d == max_depth || m == 42) {
        eval = evaluation(move);
    }
    else {
        // int scores[8]; memset(scores, 0, sizeof scores);
        // eval = 7; scores[eval] = INT_MIN;
        for (int x=0; x<7; x++) {
            int y;
            if (make_move(x, y)) {
                board[y][x] = (m % 2 == 0) ? 'x' : 'o';
                m++;
                int curr = -search(make_pair(x, y), d + 1);
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
    // if (d < 3 && abs(eval) >= INF / 2 && abs(eval) <= INF - 3) {
    //     printb();
    //     cout << eval << endl;
    // }
    // if (eval == 0) return sway;
    return eval + evaluation(move);
} // NOT NOT NOT done NOT NOT NOT

int get_ai_move() {
    int scores[7]; for (int i=0; i<7; i++) scores[i] = -INF;
    int choice, y;
    for (choice = 0;;choice++) if (make_move(choice, y)) break;
    for (int x=0; x<7; x++) {
        if (make_move(x, y)) {
            board[y][x] = (m % 2 == 0) ? 'x' : 'o';
            m++;
            scores[x] = search(make_pair(x, y));
            // cout << scores[x] << ' ';
            board[y][x] = '.';
            m--;
            if (scores[choice] < scores[x]) choice = x;
        }
    }
    for (int score : scores) cout << score << ' ';
    cout << endl;
    cout << choice << endl << endl;
    // if (scores[choice] < -INF / 2) return -1;
    return choice;
} // NOT NOT NOT done NOT NOT NOT

pair<int, int> get_move() {
    int x, y;
    do {
        // if (ai_play && ai_turn == m % 2) x = get_ai_move();
        // else {
        //     cout << "Enter move Player " << (m % 2 + 1) << ": ";
        //     cin >> x; x--;
        // }
        x = get_ai_move();
        if (x == -1) return make_pair(-1, -1);
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
        if (move.first == -1) {
            cout << "I resign. I realized your win is forced." << endl;
        }
        board[move.second][move.first] = (m % 2 == 0) ? 'x' : 'o';
        last_move = move.first;
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