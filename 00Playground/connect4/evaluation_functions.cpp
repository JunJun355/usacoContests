int evaluation1(pair<int, int> move) {
    // return 0;
    int potential = 0;
    int potencies[4] = {0, 1, 4, 10};
    int x = move.first, y = move.second;
    // cout << x << ' ' << y << endl;
    int i, j, temp, curr;
    char thing = board[y][x];

    // up-down
    for (i=y; i<5; i++) {
        if (board[i + 1][x] != thing) break;
    }
    potential += potencies[i >= 3 ? i - y + 1 : 0];
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
    potential += potencies[temp];
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
    potential += potencies[temp];
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
    potential += potencies[temp];
    // cout << potential << ' ';

    // cout << endl;
    return potential;
}

int evaluation2(pair<int, int> move) {
    // return 0;
    int potential = 0;
    int potencies[4] = {0, 1, 4, 10};
    int x = move.first, y = move.second;
    // cout << x << ' ' << y << endl;
    int i, j, temp, curr;
    char thing = board[y][x];

    /* ADD-ONS */ {
        /* up-down */ {
            for (i=y; i<5; i++) {
                if (board[i + 1][x] != thing) break;
            }
            potential += potencies[i >= 3 ? i - y + 1 : 0];
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
            potential += potencies[temp];
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
            potential += potencies[temp];
            // cout << potential << ' ';
        }

        /* left-up diagonal */ {
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
            potential += potencies[temp];
            // cout << potential << ' ';
        }
    }

    /* BLOCKS */ {
        /* up-down */ {
            for (i=y; i<5; i++) {
                if (board[i + 1][x] != thing) break;
            }
            potential += potencies[i >= 3 ? i - y + 1 : 0];
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
            potential += potencies[temp];
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
            potential += potencies[temp];
            // cout << potential << ' ';
        }

        /* left-up diagonal */ {
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
            potential += potencies[temp];
            // cout << potential << ' ';
        }
    }
    // cout << endl;
    return potential;
}

int evaluation3(pair<int, int> move) {
    // return 0;
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
            potential += potencies[2][temp];
            // cout << potential << ' ';
        }

        /* left-up diagonal */ {
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
        }

    }

    thing = board[y][x] == 'x' ? 'o' : 'x';

    /* BLOCKS */ {

        /* up-down */ {
            for (i=y; i<5; i++) {
                if (board[i + 1][x] != thing) break;
            }
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
            potential += potencies[2][temp];
            // cout << potential << ' ';
        }

        /* left-up diagonal */ {
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
        }

    }

    // cout << endl;

    return potential;
}
