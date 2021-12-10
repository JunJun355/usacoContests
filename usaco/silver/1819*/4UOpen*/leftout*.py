"""
ID: 06jajun
LANG: PYTHON3
TASK: leftout
"""
# Na ->


def main():
    fin = open ('leftout.in', 'r')
    fout = open ('leftout.out', 'w')

    n = int(fin.readline())
    grid = []
    for i in range(n):
        grid.append(list(fin.readline()))
    print(''.join([''.join(c) for c in grid]))
    candidates = []
    # columns
    for i in range(1, n):
        if grid[0][i] == 'R':
            for j in range(n):
                if grid[j][i] == 'R':
                    grid[j][i] = 'L'
                else:
                    grid[j][i] = 'R'
        print(''.join([''.join(c) for c in grid]))
    for i in range(1, n):
        if grid[i][0] == 'R':
            for j in range(n):
                if grid[i][j] == 'R':
                    grid[i][j] = 'L'
                else:
                    grid[i][j] = 'R'
                    candidates.append((i, j))
        print(''.join([''.join(c) for c in grid]))
    for j in range()
    fout.write('-1')

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
