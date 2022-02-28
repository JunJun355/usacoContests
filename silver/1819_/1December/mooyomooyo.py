"""
ID: 06jajun
LANG: PYTHON3
TASK: mooyomooyo
"""
# * ->

def main():
    fin = open ('mooyomooyo.in', 'r')
    fout = open ('mooyomooyo.out', 'w')

    n, k = [int(c) for c in fin.readline().split()]
    board = []
    for i in range(n):
        board.append(list(fin.readline().strip()))
    # print('\n'.join([''.join(row) for row in board]), '\n')
    while r(board, n, k):
        # print('\n'.join([''.join(row) for row in board]), '\n')
        re(board, n)
        # print('\n'.join([''.join(row) for row in board]), '\n')
    fout.write('\n'.join([''.join(row) for row in board]))
    fout.write('\n')
    fout.close()


def r(board, n, k):
    checked = set()
    moves = ((0, 1), (-1, 0), (0, -1), (1, 0))
    res = 0
    for i in range(n - 1, -1, -1):
        for j in range(10):
            if (i, j) not in checked and board[i][j] != '0':
                to_check = [(i, j)]
                curr = [(i, j)]
                checked.add((i, j))
                type = board[i][j]
                while to_check:
                    ncurr = to_check.pop()
                    for movex, movey in moves:
                        nmovex, nmovey = ncurr[0] + movex, ncurr[1] + movey
                        if 0 <= nmovex < n and 0 <= nmovey < 10 and board[nmovex][nmovey] == type and (nmovex, nmovey) not in checked:
                            to_check.append((nmovex, nmovey))
                            checked.add((nmovex, nmovey))
                            curr.append((nmovex, nmovey))
                if len(curr) >= k:
                    res = 1
                    # print(curr)
                    for spot in curr:
                        board[spot[0]][spot[1]] = '0'
                    # print('---', '\n'.join([''.join(row) for row in board]), '\n')
    return res


def re(board, n):
    for j in range(10):
        down = 0
        for i in range(n - 1, -1, -1):
            board[i + down][j] = board[i][j]
            if board[i][j] == '0':
                down += 1
            if down:
                board[i][j] = '0'
    # print('\n'.join([''.join(row) for row in board]))


if __name__ == '__main__':
    main()
