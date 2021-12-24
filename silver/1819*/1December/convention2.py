"""
ID: 06jajun
LANG: PYTHON3
TASK: convention2
"""
# * ->
from heapq import heappush, heappop


def main():
    fin = open ('convention2.in', 'r')
    fout = open ('convention2.out', 'w')

    n = int(fin.readline())
    def comp(cow1, cow2):
        if cow1[0] > cow2[0]:
            return False
        elif cow1[0] < cow2[0]:
            return True
        if cow1[2] < cow2[2]:
            return False
        else:
            return True
    cows = []
    for i in range(n):
        cows.append([i] + [int(c) for c in fin.readline().split()])
    # print(cows)
    cows.sort(key=lambda x:[x[1], x[0]])
    qu = []
    i = 0
    time = 0
    ans = 0
    while qu or i < n:
        # print('-', qu, time)
        if not qu and i < n:
            heappush(qu, cows[i])
            i += 1
        # print(qu)
        curr = heappop(qu)
        # print(curr)
        time = max(time, curr[1])
        ans = max(time - curr[1], ans)
        j = i
        time = time + curr[2]
        while j < n:
            if cows[j][1] <= time:
                heappush(qu, cows[j])
                j += 1
            else:
                break
        i = j
    print(ans)
    fout.write(str(ans))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
