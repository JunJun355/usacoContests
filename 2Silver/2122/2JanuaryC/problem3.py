"""
ID: 06jajun
LANG: PYTHON3
TASK: test
"""
from collections import deque
from copy import copy


def main():
    n, m = [int(c) for c in input().split()]
    prefs = []
    boxes = []
    for i in range(m + 1):
        boxes.append([])
    for i in range(n):
        pref = [int(c) for c in input().split()]
        prefs.append(pref)
        boxes[pref[0]].append(i)
        boxes[pref[1]].append(i)
    # print(prefs)
    # print(boxes)
    res = 0
    ans = []
    # Find Groups
    def find_cycle(c, le):
        to_search = deque([[c, []]])
        while to_search:
            curr_cow, prevs = to_search.popleft()
            # print(curr_cow, prevs)
            if len(prevs) > le:
                break
            news = boxes[prefs[curr_cow][0]] + boxes[prefs[curr_cow][1]]
            for new in news:
                if new not in prevs:
                    to_search.append([new, prevs + [new]])
                elif len(prevs) > 2 and new != prevs[-2] and new != prevs[-1]:
                    # print(news)
                    return prevs
        return [c]


    searched = set()
    for cow in range(n):
        if cow in searched:
            continue
        searched.add(cow)
        group = [cow]
        to_search = [cow]
        while to_search:
            curr_cow = to_search.pop()
            # print('------', curr_cow, to_search)
            # group.append(curr_cow)
            news = boxes[prefs[curr_cow][0]] + boxes[prefs[curr_cow][1]]
            # print(news)
            for new in news:
                if new not in searched:
                    group.append(new)
                    to_search.append(new)
                    searched.add(new)
        # print('xxxxxx', group)
        group_n = len(group)
        cycle = find_cycle(cow, group_n)
        cycle_n = len(cycle)
        s_cycle = set(cycle)
        # print(cycle)
        if cycle_n == 1:
            order = copy(cycle)
        else:
            if prefs[cycle[0]][0] in prefs[cycle[1]]:
                order = copy(cycle)
            else:
                order = []
                order.append(cycle[0])
                order += cycle[:0:-1]
        ans += order
        group_boxes = set()
        for i in group:
            group_boxes.add(prefs[i][0])
            group_boxes.add(prefs[i][1])
        # print(group_boxes)
        for cow in group:
            if cow not in s_cycle:
                ans.append(cow)
        res += max(group_n - len(group_boxes), 0)
    # print ans
    print(res)
    for i in ans:
        print(i + 1)


if __name__ == '__main__':
    main()
