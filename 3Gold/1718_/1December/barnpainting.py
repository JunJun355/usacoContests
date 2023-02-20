"""
ID: 06jajun
LANG: PYTHON3
TASK: barnpainting
"""
# * ->


def main():
    fin = open ('barnpainting.in', 'r')
    fout = open ('barnpainting.out', 'w')

    n, k = [int(c) for c in fin.readline().split()]

    connections = []
    colors = []
    counts = []
    for _ in range(n):
        connections.append([])
        colors.append([0, 1, 2])
        counts.append([1, 1, 1])
    for _ in range(n - 1):
        x, y = [int(c) - 1 for c in fin.readline().split()]
        connections[x].append(y)
        connections[y].append(x)

    for _ in range(k):
        cow, color = [int(c) - 1 for c in fin.readline().split()]
        colors[cow] = [color]
        counts[cow] = [0, 0, 0]
        counts[cow][color] = 1
        for ncow in connections[cow]:
            if color in colors[ncow]:
                colors[ncow].remove(color)
                counts[ncow][color] = 0
    # print(connections)
    # print(colors)
    # print(counts)

    to_search = [cow]
    searched = set(to_search)
    for i in range(n):
        t = False
        for ncow in connections[to_search[i]]:
            if ncow in searched: continue
            t = True
            to_search.append(ncow)
            searched.add(ncow)
    # print(to_search)
    searched = set()
    while to_search:
        # print(counts)
        curr = to_search.pop()
        # print(curr)
        searched.add(curr)
        for ncow in connections[curr]:
            if ncow in searched: continue
            counts[ncow][0] *= counts[curr][1] + counts[curr][2]
            counts[ncow][1] *= counts[curr][0] + counts[curr][2]
            counts[ncow][2] *= counts[curr][0] + counts[curr][1]
    fout.write(str(sum(counts[cow]) % 1000000007))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
