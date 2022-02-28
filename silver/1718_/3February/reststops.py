"""
ID: 06jajun
LANG: PYTHON3
TASK: reststops
"""
# * ->

def main():
    fin = open ('reststops.in', 'r')
    fout = open ('reststops.out', 'w')

    L, N, F, B = [int(c) for c in fin.readline().split()]
    rest_stops = []
    for i in range(N):
        rest_stops.append([int(c) for c in fin.readline().split()])
    pref = [0] * (N + 1)
    for i in range(N - 1, -1, -1):
        pref[i] = max(pref[i + 1], rest_stops[i][1])
    print(pref)
    i = 0
    prev = 0
    tot = 0
    while i < N:
        if rest_stops[i][1] < pref[i]:
            i += 1
            continue
        tot += (rest_stops[i][0] - prev) * rest_stops[i][1] * (F - B)
        prev = rest_stops[i][0]
        i += 1
        print(tot)
    fout.write(str(tot))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
