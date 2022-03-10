"""
ID: 06jajun
LANG: PYTHON3
TASK: paintbarn
"""
# * ->

def main1():
    fin = open ('paintbarn.in', 'r')
    fout = open ('paintbarn.out', 'w')

    n, k = [int(c) for c in fin.readline().split()]
    grid = []
    for i in range(1001):
        grid.append([0] * 1001)
    maxx = 0
    maxy = 0
    for _ in range(n):
        x1, y1, x2, y2 = [int(c) for c in fin.readline().split()]
        maxx, maxy = max(maxx, x2), max(maxy, y2)
        for i in range(y1, y2):
            grid[i][x1] += 1
            grid[i][x2] -= 1
    tot = 0
    curr = 0
    # print('\n'.join([' '.join([str(n) for n in c[0:maxx + 1]]) for c in grid[0:maxy]]))
    for i in range(maxy):
        # print(curr)
        # curr = 0
        for j in range(maxx + 1):
            curr += grid[i][j]
            if curr == k:
                tot += 1
                # print(i, j)
    fout.write(str(tot))

    fout.write('\n')
    fout.close()


def main():
    fin = open ('paintbarn.in', 'r')
    fout = open ('paintbarn.out', 'w')

    n, k = [int(c) for c in fin.readline().split()]
    grid = []
    for i in range(1001):
        grid.append([0] * 1001)
    tot = 0
    maxx, maxy = 0, 0
    for _ in range(n):
        a, b, c, d = [int(c) for c in fin.readline().split()]
        grid[a][b] += 1
        grid[a][d] -= 1
        grid[c][b] -= 1
        grid[c][d] += 1
        maxx, maxy = max(maxx, c), max(maxy, d)
    for j in range(1, maxx + 1):
        grid[0][j] += grid[0][j - 1]
        if grid[0][j] == k:
            tot += 1
    for i in range(1, maxy + 1):
        grid[i][0] += grid[i - 1][0]
        if grid[i][0] == k:
            tot += 1
    for i in range(1, maxx + 1):
        for j in range(1, maxy + 1):
            grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1]
            if grid[i][j] == k:
                tot += 1

    fout.write(str(tot))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
