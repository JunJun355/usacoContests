def main():
    fin = open("Day10.in", "r")
    ans = 0
    c = 1
    cycs = 1
    for i in range(147):
        inp = fin.readline().split()
        if inp[0] == "noop":
            if c % 40 == 20:
                print(cycs, c)
                ans += cycs * c
            c += 1
        else:
            if c % 40 == 20:
                print(cycs, c)
                ans += cycs * c
            c += 1
            if c % 40 == 20:
                print(cycs, c)
                ans += cycs * c
            c += 1
            cycs += int(inp[1])
    print(ans)



def main1():
    fin = open("Day10.in", "r")
    c = 0
    cycs = 1
    grid = []
    for i in range(6):
        grid.append(['.'] * 40)

    for i in range(147):
        inp = fin.readline().split()
        if inp[0] == "noop":
            print(cycs, c)
            if abs(cycs + (c // 40 * 40) - c) <= 1:
                grid[c // 40][c % 40] = '#'
            c += 1
        else:
            print(cycs, c)
            if abs(cycs + (c // 40 * 40) - c) <= 1:
                grid[c // 40][c % 40] = '#'
            c += 1
            if abs(cycs + (c // 40 * 40) - c) <= 1:
                grid[c // 40][c % 40] = '#'
            c += 1
            cycs += int(inp[1])
    print('\n'.join([' '.join(d) for d in grid]))
    # <--- ezfprakl --->


if __name__ == '__main__':
    main1()
