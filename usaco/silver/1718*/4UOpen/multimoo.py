"""
ID: 06jajun
LANG: PYTHON3
TASK: multimoo
"""
# * ->
from collections import defaultdict


def main():
    fin = open ('multimoo.in', 'r')
    fout = open ('multimoo.out', 'w')

    n= int(fin.readline())
    grid = []
    for i in range(n):
        grid.append([int(c) for c in fin.readline().split()])

    # find single
    maxi = 1
    checked = set()
    moves = ((1, 0), (-1, 0), (0, 1), (0, -1))
    edges = defaultdict(lambda: set())
    regid = 0
    ids = []
    sizes = []
    for i in range(n):
        for j in range(n):
            if (i, j) not in checked:
                # print('\n'.join(['  '.join([str(i) for i in c]) for c in grid]), edges)
                # print(checked)
                checked.add((i, j))
                ids.append(grid[i][j])
                currm = 1
                to_check = []
                to_check.append([i, j])
                tot = 0
                while to_check:
                    # print(regid, to_check)
                    curr = to_check.pop()
                    tot += 1
                    numcurr = grid[curr[0]][curr[1]]
                    grid[curr[0]][curr[1]] = str(regid)
                    for move in moves:
                        ncurrx, ncurry = curr[0] + move[0], curr[1] + move[1]
                        if 0 <= ncurrx < n and 0 <= ncurry < n:
                            currid = grid[ncurrx][ncurry]
                            if (ncurrx, ncurry) not in checked and currid == numcurr:
                                to_check.append([ncurrx, ncurry])
                                checked.add((ncurrx, ncurry))
                                currm += 1
                            elif type(currid) == type('a') and currid != str(regid):
                                edges[str(regid)].add(currid)
                                edges[currid].add(str(regid))
                maxi = max(maxi, currm)
                regid += 1
                sizes.append(tot)
    fout.write(str(maxi) + '\n')
    # print(edges)
    # print('\n'.join(['  '.join(c) for c in grid]), '\n')
    # print(regid)
    # print(maxi)
    # print(ids)
    # print(sizes)
    checked_pairs = set()
    ans = 0
    for i in range(regid):
        id = str(i)
        for j in edges[id]:
            ni, nj = min(ids[i], ids[int(j)]), max(ids[i], ids[int(j)])
            if (ni, nj) in checked_pairs or (ni, nj) in checked_pairs: continue
            # if int(j) < i: continue
            # print('---', i, j)
            tot = sizes[i]
            to_check = [new for new in edges[id] if ids[int(new)] == ids[int(j)]]
            checked = set(to_check)
            checked.add(id)
            checked.add(j)
            while to_check:
                # print(to_check, checked)
                curr = to_check.pop()
                tot += sizes[int(curr)]
                for new in edges[curr]:
                    if new not in checked and (ids[int(new)] == ids[i] or ids[int(new)] == ids[int(j)]):
                        to_check.append(new)
                        checked.add(new)
                        # tot += sizes[int(new)]
            # print(i, j)
            ans = max(ans, tot)
            checked_pairs.add((ni, nj))
            # print(tot)
    fout.write(str(ans))
        # to_check = [[n, ids[n]] for n in edges[id]]
        # tot = sizes[i]
        # checked = set(to_check)
        # while to_check:
        #     currn, currid = to_check.pop()
        #     for j in edges[currn]:
        #         if ids[j] == currid:
        #             to_check.append()


    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
