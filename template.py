"""
ID: 06jajun
LANG: PYTHON3
TASK: test
"""
from collections import defaultdict


def run(n, m, edges):
    highest1 = 1
    tosearch = [1]
    searched = set([1])
    while tosearch:
        curr = tosearch.pop()
        for new in edges[curr]:
            if new in searched: continue
            if new == n: return 0
            searched.add(new)
            tosearch.append(new)
            highest1 = max(highest1, new)
    lowestn = n
    tosearch = [n]
    searched.add(n)
    while tosearch:
        curr = tosearch.pop()
        for new in edges[curr]:
            if new in searched: continue
            searched.add(new)
            tosearch.append(new)
            lowestn = max(lowestn, new)

    curr_lowest = ((lowestn - highest1) / 2) ** 2 * 2
    for check in edges.keys():
        if check in searched:
            continue
        tosearch = [check]
        low, high = abs(check - highest1), abs(check - lowestn)
        while tosearch:
            curr = tosearch.pop()
            low, high = min(low, abs(curr - highest1)), min(high, abs(curr - lowestn))
            for new in edges[curr]:
                if new in searched: continue
                searched.add(new)
                tosearch.append(new)
        curr_lowest = min(curr_lowest, (low ** 2 + high ** 2))
    return curr_lowest

def main():
    t = int(input())
    for i in range(t):
        n, m = [int(c) for c in input().split()]
        edges = defaultdict(lambda: [])
        for i in range(m):
            a, b = [int(c) for c in input().split()]
            edges[a].append(b)
            edges[b].append(a)
        print(run(n, m, edges))


if __name__ == '__main__':
    main()
