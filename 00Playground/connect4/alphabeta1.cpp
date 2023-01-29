#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

#define INF 1000000000

using namespace std;

char board[6][7];
int m = 19;
int last_move = -1; // visual aid to see previous move when printing
unordered_map<string, int> cache;
string s[7] = {"", "", "oxoo", "oxoxoo", "xoxoxx", "xo", "x"};
const int search_order[7] = {3, 2, 4, 1, 5, 0, 6};
// const int search_order[7] = {3, 6, 2, 4, 1, 5, 0};
const bool ai_play = true;
const int ai_turn = 1, default_depth = 6;
int max_depth = default_depth;
int deez[5] = {6, 12, 15, 18, 0};
// int current[max_depth + 1], best[max_depth + 1];
// vector<int> searched;
int tot = 0;

void changeb(int x, int y, char t) {
    board[y][x] = t;
    if (t == '.') s[x].erase(s[x].size() - 1);
    else s[x] += t;
}

string encode() {
    return s[0]+"/"+s[1]+"/"+s[2]+"/"+s[3]+"/"+s[4]+"/"+s[5]+"/"+s[6];
}

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
    // for (string t : s) cout << t << endl;
} // done

int evaluation(pair<int, int> move) {
    return 0;
    int potential = 0;
    int potencies[3][4] = {{0, 1, 3, 5}, {0, 3, 5, 10}, {0, 3, 6, 10}};
    int x = move.first, y = move.second;

    int i, j, temp, curr;
    char thing = board[y][x];

    /* ADD-ONS */ {

        /* up-down */ {
            for (i=y; i<5; i++) {
                if (board[i + 1][x] != thing) break;
            }
            assert(0 <= i - y + 1 && i - y + 1 < 4);
            potential += potencies[0][i >= 3 ? i - y + 1 : 0];
            // cout << potential << ' ';
        }

        /* left-right */ {
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
            if (!(0 <= temp && temp < 4)) {
                printb();
                cout << x << ' ' << y << endl;
                cout << i << ' ' << j << endl;
                cout << temp << endl;
                assert(false);
            }
            potential += potencies[1][temp];
            // cout << potential << ' ';
        }

        /* left-down diagonal */ {
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
            assert(0 <= temp && temp < 4);
            potential += potencies[2][temp];
            // cout << potential << ' ';
        }

        /* left-up diagonal */ {
            i = 0, j = 0;
            while (max(-3, max(-x, y-5)) < i && (board[y - i + 1][x + i - 1] == thing || board[y - i + 1][x + i - 1] == '.')) i--;
            while (min(3, min(6-x, y)) > j && (board[y - j - 1][x + j + 1] == thing || board[y - j - 1][x + j + 1] == '.')) j++;
            curr = 0, temp = 0;
            if (j - i >= 3) for (int c = i; c <= j; c++) {
                if (c > i + 3) {
                    if (board[y - c + 4][x + c - 4] == thing) curr--;
                }
                if (board[y - c][x + c] == thing) curr++;
                temp = max(curr, temp);
            }
            assert(0 <= temp && temp < 4);
            potential += potencies[2][temp];
            // cout << potential << ' ';
        }

    }

    thing = board[y][x] == 'x' ? 'o' : 'x';

    /* BLOCKS */ {

        /* up-down */ {
            for (i=y; i<5; i++) {
                if (board[i + 1][x] != thing) break;
            }
            assert(0 <= i - y && i - y < 4);
            potential += potencies[0][i >= 3 ? i - y : 0];
            // cout << potential << ' ';
        }

        /* left-right */ {
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
            assert(0 <= temp && temp < 4);
            potential += potencies[1][temp];
            // cout << potential << ' ';
        }

        /* left-down diagonal */ {
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
            assert(0 <= temp && temp < 4);
            potential += potencies[2][temp];
            // cout << potential << ' ';
        }

        /* left-up diagonal */ {
            i = 0, j = 0;
            while (max(-3, max(-x, y-5)) < i && (board[y - i + 1][x + i - 1] == thing || board[y - i + 1][x + i - 1] == '.')) i--;
            while (min(3, min(6-x, y)) > j && (board[y - j - 1][x + j + 1] == thing || board[y - j - 1][x + j + 1] == '.')) j++;
            curr = 0, temp = 0;
            if (j - i >= 3) for (int c = i; c <= j; c++) {
                if (c > i + 3) {
                    if (board[y - c + 4][x + c - 4] == thing) curr--;
                }
                if (board[y - c][x + c] == thing) curr++;
                temp = max(curr, temp);
            }
            assert(0 <= temp && temp < 4);
            potential += potencies[2][temp];
            // cout << potential << ' ';
        }

    }

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
    for (int i=max(-3, max(-x, -y)); i<=min(3, min(5-x, 6-y)); i++) {
        if (board[x + i][y + i] != thing) tot = 0;
        else tot++;
        if (tot == 4) return true;
    }

    // check left-up diagonal
    tot = 0;
    for (int i=max(-3, max(x - 5, -y)); i<=min(3, min(x, 6-y)); i++) {
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

int search(pair<int, int> move, int d=1, int alpha=-INF, int beta=INF) {
    tot++;
    // printb();
    int eval = INF;
    // int x = move.first, y = move.second;

    string enc = encode();
    // if (cache.find(enc) != cache.end()) {
    //     return cache[enc];
    // }
    if (done(move)) {
        // printb();
        // tot++;
        eval = INF - d * 1000;
    }
    else if (d == max_depth || m == 42) {
        eval = evaluation(move);
        // eval = 0;
    }
    else {
        // int scores[8]; memset(scores, 0, sizeof scores);
        // eval = 7; scores[eval] = INT_MIN;
        for (int x : search_order) {
            int y;
            if (make_move(x, y)) {
                changeb(x, y, (m % 2 == 0) ? 'x' : 'o');
                m++;
                // searched.push_back(x);
                int curr = -search(make_pair(x, y), d + 1, -beta, -alpha);
                // cout << curr << ' ';
                // searched.pop_back();
                changeb(x, y, '.');
                m--;
                // if (curr == -2) continue;
                eval = min(eval, curr);
                beta = min(beta, eval);
                if (beta <= alpha) {
                    // tot++;
                    return eval;
                }
                // if (eval <= -INF/2) break;
            }
        }
        eval += evaluation(move);
    }
    cache[encode()] = eval;
    // cout << d;
    // for (int movei : searched) cout << ' ' << movei;
    // cout << ' ' << alpha << ' ' << beta << ' ' << eval << endl;
    return eval;
} // NOT NOT NOT done NOT NOT NOT

int get_ai_move() {
    // searched.clear();
    int scores[7]; int choice, y;
    vector<int> next_to_search = {3, 2, 4, 1, 5, 0, 6};
    vector<int> to_search;
    int dz = 0;
    do {
        dz++;
        to_search = next_to_search;
        tot = 0;
        for (int i=0; i<7; i++) scores[i] = -INF;
        for (choice = 0;;choice++) if (make_move(choice, y)) break;
        for (int x : to_search) {
            if (make_move(x, y)) {
                changeb(x, y, (m % 2 == 0) ? 'x' : 'o');
                // searched.push_back(x);
                m++;
                scores[x] = search(make_pair(x, y));
                // cout << scores[x] << ' ';
                // searched.pop_back();
                changeb(x, y, '.');
                m--;
                if (scores[choice] < scores[x]) {
                    choice = x;
                    next_to_search.clear(); next_to_search.push_back(x);
                }
                else if (scores[choice] == scores[x]) next_to_search.push_back(x);
            }
        }
        for (int score : scores) cout << score << ' ';
        cout << endl;
        // cout << choice << endl << endl;
        // if (scores[choice] < -INF / 2) return -1;
        cache.clear();
        cout << tot << endl;
        max_depth = deez[dz];
    } while (tot < 500000 && dz < 4 && (abs(scores[next_to_search.front()]) < 10000 && next_to_search.size() != 1));
    max_depth = default_depth;
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
        if (x == -1) return make_pair(-1, -1);
        if (make_move(x, y) && 0 <= x && x <= 7) break;
        cout << "!Error" << endl;
    } while (true);
    return make_pair(x, y);
} // done

void setup() {
    // memset(board, '.', sizeof(board));
    string s = "...ox.....ox....oxo....oox....xxoo...ooxxx";
    for (int i=0; i<6; i++) for (int j=0; j<7; j++) {
        board[i][j] = s[i * 7 + j];
    }
    printb();
} // done

void game() {
    setup();
    pair<int, int> move;
    // move = get_move();
    do {
        move = get_move();
        if (move.first == -1) {
            cout << "I resign. I realized your win is forced." << endl;
            return ;
        }
        changeb(move.first, move.second, (m % 2 == 0) ? 'x' : 'o');
        last_move = move.first;
        cout << evaluation(move) << endl;
        printb();
        m++;
    } while (!done(move) && m <= 42);
    if (m == 42) cout << "It's a draw!" << endl;
    else cout << "Player " << ((m + 1) % 2 + 1) << " wins!" << endl;
    return ;
} // done

int main() {
    game();
    return 0;
} // done
