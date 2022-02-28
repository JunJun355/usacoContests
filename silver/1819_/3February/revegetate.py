"""
ID: 06jajun
LANG: PYTHON3
TASK: revegetate
"""
# * ->
from collections import defaultdict


def main():
    fin = open ('revegetate.in', 'r')
    fout = open ('revegetate.out', 'w')

    n, m = [int(c) for c in fin.readline().split()]
    connections = []
    for _ in range(n): connections.append([])
    for _ in range(m):
        s, a, b = fin.readline().split()
        a, b = int(a) - 1, int(b) - 1
        connections[a].append([b, int(s=='D')])
        connections[b].append([a, int(s=='D')])
    tot = n
    # print(connections)
    colors = defaultdict(lambda: -1)
    for f, c in enumerate(connections):
        if not c or colors[f] != -1:
            continue
        colors[f] = 0
        to_check = [f]
        checked = set(to_check)
        while to_check:
            # print(colors)
            curr = to_check.pop()
            for connection in connections[curr]:
                new = (colors[curr] + connection[1]) % 2
                # print(curr, connection, new)
                if colors[connection[0]] != -1 and colors[connection[0]] != new:
                    fout.write('0\n')
                    fout.close()
                    return
                if connection[0] not in checked:
                    tot -= 1
                    colors[connection[0]] = new
                    to_check.append(connection[0])
                    checked.add(connection[0])
        # print(checked)
    fout.write('1' + '0' * tot)
    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
