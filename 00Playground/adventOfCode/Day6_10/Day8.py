def main():
    fin = open("Day8.in", "r")
    grid = []
    ans = 0
    for i in range(99):
        grid.append([int(c) for c in list(fin.readline().strip())])
    b = []
    for i in range(99):
        b.append([1] * 99)
    for i in range(99):
        m = -1
        for j in range(99):
            if m >= grid[i][j]: pass
            else: b[i][j] = 0
            m = max(grid[i][j], m)
        m = -1
        for j in range(98, -1, -1):
            if m >= grid[i][j]: pass
            else: b[i][j] = 0
            m = max(grid[i][j], m)

        m = -1
        for j in range(99):
            if m >= grid[j][i]: pass
            else: b[j][i] = 0
            m = max(grid[j][i], m)
        m = -1
        for j in range(98, -1, -1):
            if m >= grid[j][i]: pass
            else: b[j][i] = 0
            m = max(grid[j][i], m)
    # print('\n'.join([' '.join([str(c) for c in d]) for d in b]))
    for i in range(99):
        for j in range(99):
            if b[i][j] == 0: ans += 1
    print(ans)



def main1():
    fin = open("Day8.in", "r")
    fans = 0
    grid = []
    n = 99
    for i in range(n):
        grid.append([int(c) for c in list(fin.readline().strip())])
    for i in range(n):
        for j in range(n):
            ans = 1
            for k in range(j-1, -1, -1):
                if grid[i][k] >= grid[i][j]:
                    ans *= j - k
                    break
                if k == 0:
                    ans *= j - k
            for k in range(j+1, n):
                if grid[i][k] >= grid[i][j]:
                    ans *= k - j
                    break
                if k == n - 1:
                    ans *= k - j
            for k in range(i-1, -1, -1):
                if grid[k][j] >= grid[i][j]:
                    ans *= i - k
                    break
                if k == 0:
                    ans *= i - k
            for k in range(i+1, n):
                if grid[k][j] >= grid[i][j]:
                    ans *= k - i
                    break
                if k == n - 1:
                    ans *= k - i
            fans = max(ans, fans)
            print(ans)
    # print('\n'.join([' '.join([str(c) for c in d]) for d in b]))
    print(fans)



if __name__ == '__main__':
    main1()
