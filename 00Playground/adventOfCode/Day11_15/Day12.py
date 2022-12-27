def main():
    fin = open("Day12.in", "r")
    ans = 0
    grid = []
    for i in range(41):
        grid.append(list(fin.readline().strip()))
    to_search = [(0, 1000-ord('a'), 0, 0)]
    lgrid = []
    for i in range(41):
        lgrid.append([float('inf')] * 180)
    grid[0][0] = 'a'
    lgrid[0][0] = 0
    grid[20][154] = 'z'
    while to_search:
    # for i in range(8):
        d, l, x, y = to_search.pop(0)
        if x == 20 and y == 154: return d
        curr = grid[x][y]
        grid[x][y] = '.'
        print('\n'.join([''.join(c) for c in grid]))
        for i in range(-1, 2):
            for j in range(-1, 2):
                if abs(i + j) == 1:
                    m = x + i
                    n = y + j
                    if not(m >= 0 and m < len(grid) and n >= 0 and n < len(grid[0])):
                        # print(m, n)
                        continue
                    if ord(grid[m][n]) - ord(curr) < 2 and (-2 < ord(grid[m][n]) - ord(curr) or grid[m][n] == 'p'):
                        if lgrid[m][n] == float('inf'):
                            if m == 20 and n == 154: return d + 1
                            lgrid[m][n] = d + 1
                            to_search.append((lgrid[m][n], 1000-ord(grid[m][n]), m, n))
        to_search.sort()
        # print(to_search)
    return best





def main1():
    fin = open("Day12.in", "r")
    ans = 0
    grid = []
    for i in range(41):
        grid.append(list(fin.readline().strip()))
    to_search = [(0, 1000-ord('a'), 20, 154)]
    lgrid = []
    for i in range(41):
        lgrid.append([float('inf')] * 180)
    # grid[20][0] = 'a'
    lgrid[20][154] = 0
    grid[20][154] = 'z'
    while to_search:
    # for i in range(8):
        d, l, x, y = to_search.pop(0)
        if grid[x][y] == 'a': return d
        curr = grid[x][y]
        grid[x][y] = '.'
        print('\n'.join([''.join(c) for c in grid]))
        for i in range(-1, 2):
            for j in range(-1, 2):
                if abs(i + j) == 1:
                    m = x + i
                    n = y + j
                    if not(m >= 0 and m < len(grid) and n >= 0 and n < len(grid[0])):
                        # print(m, n)
                        continue
                    if ord(curr) - ord(grid[m][n]) < 2:
                        if lgrid[m][n] == float('inf'):
                            lgrid[m][n] = d + 1
                            to_search.append((lgrid[m][n], 1000-ord(grid[m][n]), m, n))
        to_search.sort()

if __name__ == '__main__':
    print(main1())
