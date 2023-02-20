"""
ID: 06jajun
LANG: PYTHON3
TASK: atlarge
"""
from collections import deque
from copy import deepcopy
# * -> 3t 4* 5t * ->


def main():
    fin = open ('atlarge.in', 'r')
    fout = open ('atlarge.out', 'w')

    n, k = [int(c) for c in fin.readline().split()]
    edges = []
    for i in range(n + 1):
        edges.append([])
    for i in range(n - 1):
        x, y = [int(c) for c in fin.readline().split()]
        edges[x].append(y)
        edges[y].append(x)
    to_search = [[k, deque([k])]]
    block = set()
    layers = dict()
    layers[k] = 0
    i = 0
    searched = set([k])
    # print(edges)
    while i < n:
        # print(to_search)
        curr, ndist = to_search[i]
        ndist = deepcopy(ndist)
        if len(edges[curr]) == 1 and edges[curr][0] in searched:
            while ndist and layers[ndist[0]] < layers[curr] / 2:
                ndist.popleft()
            if ndist:
                block.add(ndist[0])
            else:
                block.add(curr)
            i += 1
            continue
        newlayer = layers[curr] + 1
        while ndist and layers[ndist[0]] < newlayer / 2:
            ndist.popleft()
        if len(edges[curr]) > 2:
            ndist.append(curr)
        for new in edges[curr]:
            if new in searched:
                continue
            to_search.append([new, ndist])
            searched.add(new)
            layers[new] = newlayer
        i += 1
    # print(block)
    # print(to_search)
    # print(layers)

    to_search = [k]
    searched = set(to_search)
    tot = 0
    while to_search:
        curr = to_search.pop()
        for new in edges[curr]:
            if new in searched:
                continue
            if new in block:
                tot += 1
                continue
            to_search.append(new)
            searched.add(new)
    fout.write(str(tot))
    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
