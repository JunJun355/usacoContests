def main():
    fin = open("Day9.in", "r")
    grid = set()
    ans = 0
    hx = 0
    hy = 0
    tx = 0
    ty = 0
    for i in range(2000):
        inp = fin.readline().split()
        dir, dis = inp[0], int(inp[1])
        for j in range(dis):
            if dir == 'R': hx += 1
            if dir == 'L': hx -= 1
            if dir == 'U': hy += 1
            if dir == 'D': hy -= 1
            if hx - tx > 1:
                if hy - ty > 0:
                    ty += 1
                elif ty - hy > 0:
                    ty -= 1
                tx += 1
            elif tx - hx > 1:
                if hy - ty > 0:
                    ty += 1
                elif ty - hy > 0:
                    ty -= 1
                tx -= 1
            elif hy - ty > 1:
                if hx - tx > 0:
                    tx += 1
                elif tx - hx > 0:
                    tx -= 1
                ty += 1
            elif ty - hy > 1:
                if hx - tx > 0:
                    tx += 1
                elif tx - hx > 0:
                    tx -= 1
                ty -= 1
            grid.add((tx, ty))
    # print(list(sorted(list(grid))))
    print(len(grid))





def main1():
    fin = open("Day9.in", "r")
    grid = set()
    ans = 0
    knots = []
    for i in range(10): knots.append([0, 0])
    for i in range(2000):
        inp = fin.readline().split()
        dir, dis = inp[0], int(inp[1])
        for j in range(dis):
            hx = knots[0][0]
            hy = knots[0][1]
            if dir == 'R': hx += 1
            if dir == 'L': hx -= 1
            if dir == 'U': hy += 1
            if dir == 'D': hy -= 1
            knots[0][0] = hx
            knots[0][1] = hy
            for i in range(9):
                hx = knots[i][0]
                hy = knots[i][1]
                tx = knots[i+1][0]
                ty = knots[i+1][1]
                if hx - tx > 1:
                    if hy - ty > 0:
                        ty += 1
                    elif ty - hy > 0:
                        ty -= 1
                    tx += 1
                elif tx - hx > 1:
                    if hy - ty > 0:
                        ty += 1
                    elif ty - hy > 0:
                        ty -= 1
                    tx -= 1
                elif hy - ty > 1:
                    if hx - tx > 0:
                        tx += 1
                    elif tx - hx > 0:
                        tx -= 1
                    ty += 1
                elif ty - hy > 1:
                    if hx - tx > 0:
                        tx += 1
                    elif tx - hx > 0:
                        tx -= 1
                    ty -= 1
                knots[i][0] = hx
                knots[i][1] = hy
                knots[i+1][0] = tx
                knots[i+1][1] = ty
            grid.add((tx, ty))
    # print(list(sorted(list(grid))))
    print(len(grid))




if __name__ == '__main__':
    main1()
