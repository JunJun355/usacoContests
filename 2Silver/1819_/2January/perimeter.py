"""
ID: 06jajun
LANG: PYTHON3
TASK: perimeter
"""
# * ->

def main():
    fin = open ('perimeter.in', 'r')
    fout = open ('perimeter.out', 'w')

    n = int(fin.readline())
    grid = []
    for i in range(n):
        grid.append(list(fin.readline().strip()))
    largesta = 0
    largestp = 0
    moves = ((1, 0), (0, 1), (-1, 0), (0, -1))
    # checked = set()
    for i in range(n):
        for j in range(n):
            if grid[i][j] == '#':
                grid[i][j] = '-'
                to_check = []
                to_check.append((i, j))
                currperm = 0
                currarea = 0
                while to_check:
                    cx, cy = to_check.pop()
                    currarea += 1
                    nx, ny = cx + 1, cy
                    if 0 <= nx < n and 0 <= ny < n:
                        if grid[nx][ny] == '#':
                            to_check.append((nx, ny))
                            grid[nx][ny] = '-'
                        elif grid[nx][ny] == '.':
                            currperm += 1
                    else:
                        currperm += 1
                    nx, ny = cx, cy + 1
                    if 0 <= nx < n and 0 <= ny < n:
                        if grid[nx][ny] == '#':
                            to_check.append((nx, ny))
                            grid[nx][ny] = '-'
                        elif grid[nx][ny] == '.':
                            currperm += 1
                    else:
                        currperm += 1
                    nx, ny = cx - 1, cy
                    if 0 <= nx < n and 0 <= ny < n:
                        if grid[nx][ny] == '#':
                            to_check.append((nx, ny))
                            grid[nx][ny] = '-'
                        elif grid[nx][ny] == '.':
                            currperm += 1
                    else:
                        currperm += 1
                    nx, ny = cx, cy - 1
                    if 0 <= nx < n and 0 <= ny < n:
                        if grid[nx][ny] == '#':
                            to_check.append((nx, ny))
                            grid[nx][ny] = '-'
                        elif grid[nx][ny] == '.':
                            currperm += 1
                    else:
                        currperm += 1

                if largesta < currarea:
                    largesta = currarea
                    largestp = currperm
                elif largesta == currarea:
                    largestp = min(largestp, currperm)
    fout.write(' '.join([str(num) for num in [largesta, largestp]]))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
