"""
ID: 06jajun
LANG: PYTHON3
TASK: mootube
"""
# * -> t8 t9 * ->
from functools import lru_cache


def main():
    fin = open ('mootube.in', 'r')
    fout = open ('mootube.out', 'w')

    n, q = [int(c) for c in fin.readline().split()]
    connections = []
    for i in range(n):
        connections.append([])
    for _ in range(n - 1):
        curr1, curr2, currrel = [int(c) - 1 for c in fin.readline().split()]
        connections[curr1].append((curr2, currrel))
        connections[curr2].append((curr1, currrel))
    # print(connections)
    def connect(k, v):
        to_check = [v]
        checked_set = set(to_check)
        tot = 0
        while to_check:
            curr_vid = to_check.pop()
            for new_vid, new_rel in connections[curr_vid]:
                # print(k, v, new_connection)
                # new_vid, new_rel = new_connection
                if new_vid in checked_set or new_rel < k:
                    continue
                    # print(k, new_vid + 1)
                to_check.append(new_vid)
                checked_set.add(new_vid)
                tot += 1
        return tot
    for _ in range(q):
        k1, v1 = [int(c) - 1 for c in fin.readline().split()]
        fout.write(str(connect(k1, v1)) + '\n')
    fout.close()


def main1():
    fin = open ('mootube.in', 'r')
    fout = open ('mootube.out', 'w')

    n, q = [int(c) for c in fin.readline().split()]
    connections = []
    for i in range(n):
        connections.append([])
    for _ in range(n - 1):
        curr1, curr2, currrel = [int(c) - 1 for c in fin.readline().split()]
        connections[curr1].append([curr2, currrel])
        connections[curr2].append([curr1, currrel])
    # print(connections)
    checked = set()
    # @lru_cache(maxsize=None)
    def connect(k, curr_vid):
        tot = 0
        checked.add(curr_vid)
        for new_connection in connections[curr_vid]:
            # print(k, v, new_connection)
            new_vid, new_rel = new_connection
            if new_vid not in checked and new_rel >= k:
                tot += connect(k, new_vid) + 1
        return tot
    for i in range(q):
        k1, v1 = [int(c) - 1 for c in fin.readline().split()]
        # if i == 45 or i == 44 or i == 43:
        #     print(k1, v1, checked, connect(k1, v1))
        checked.clear()
        fout.write(str(connect(k1, v1)) + '\n')
        # checked.clear()
    fout.close()


if __name__ == '__main__':
    main()
