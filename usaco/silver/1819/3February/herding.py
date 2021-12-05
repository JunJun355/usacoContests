"""
ID: 06jajun
LANG: PYTHON3
TASK: herding
"""
# * ->

def main():
    fin = open ('herding.in', 'r')
    fout = open ('herding.out', 'w')

    n = int(fin.readline())
    positions = []
    for i in range(n):
        positions.append(int(fin.readline()))
    positions.sort()
    minimaxi = float('inf')
    if positions[n - 1] - positions[1] == n - 2 and positions[1] - positions[0] > 2:
        minimaxi = 2
    elif positions[n - 2] - positions[0] == n - 2 and positions[n - 1] - positions[n - 2] > 2:
        minimaxi = 2
    else:
        for i in range(n):
            to_find = (n - 1) + positions[i]
            top = n - 1
            bot = i
            best = bot
            while top >= bot:
                middle = (top + bot) // 2
                # print(bot, middle, top)
                if positions[middle] < to_find:
                    bot = middle + 1
                    best = middle
                elif positions[middle] > to_find:
                    top = middle - 1
                else:
                    best = middle
                    break
            # print(best, to_find)
            # print(positions)
            minimaxi = min(minimaxi, n - (best - i + 1))
            # print(minimaxi, n - (best - i + 1))
            # print(positions)
    fout.write(str(minimaxi))
    fout.write('\n')
    fout.write(str(positions[-1] - positions[0] - n + 2 - min(positions[-1] - positions[-2], positions[1] - positions[0])))
    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
