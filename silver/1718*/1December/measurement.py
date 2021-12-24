"""
ID: 06jajun
LANG: PYTHON3
TASK: measurement
"""
# * ->
from collections import defaultdict
from heapq import heapify, heappush, heappop


def main():
    fin = open ('measurement.in', 'r')
    fout = open ('measurement.out', 'w')

    n, g = [int(c) for c in fin.readline().split()]
    ans = 0
    measurements = []
    for i in range(n):
        measurements.append([int(c) for c in fin.readline().split()])
    measurements.sort()
    numtop = 100000
    top = g
    outputs = defaultdict(lambda: g)
    cows = defaultdict(lambda: 0)
    cows[g] = numtop
    ltop = [-g]
    heapify(ltop)
    for measurement in measurements:
        # print(measurement, cows, outputs, ltop)
        # print(ltop, measurement[1:], ans, outputs[measurement[1]] + measurement[2])
        cows[outputs[measurement[1]]] -= 1
        outputs[measurement[1]] += measurement[2]
        cows[outputs[measurement[1]]] += 1
        if measurement[2] >= 0:
            if outputs[measurement[1]] > top:
                if top == outputs[measurement[1]] - measurement[2] and numtop == 1:
                    ans -= 1
                numtop = 1
                top = outputs[measurement[1]]
                ans += 1
            elif outputs[measurement[1]] == top:
                numtop += 1
                ans += 1
        else:
            if top == outputs[measurement[1]] - measurement[2]:
                numtop -= 1
                ans += 1
        heappush(ltop, -outputs[measurement[1]])
        if numtop == 0:
            while numtop == 0:
                heappop(ltop)
                numtop = cows[-ltop[0]]
                top = -ltop[0]
            if numtop == 1 and outputs[measurement[1]] == top:
                ans -= 1
    # print(measurement, cows, outputs, ltop)
    fout.write(str(ans))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
