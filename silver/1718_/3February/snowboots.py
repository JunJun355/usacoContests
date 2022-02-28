"""
ID: 06jajun
LANG: PYTHON3
TASK: snowboots
"""
# * ->

def main():
    fin = open ('snowboots.in', 'r')
    fout = open ('snowboots.out', 'w')

    n, b = [int(c) for c in fin.readline().split()]
    depths = [int(c) for c in fin.readline().split()]
    boots = []
    for i in range(b):
        boots.append([int(c) for c in fin.readline().split()])
    discards = [float('inf')] * (n)
    discards[0] = 0
    for i in range(n):
        curr = discards[i]
        # print(curr, discards)
        if curr == float('inf'): continue
        curr_depth = depths[i]
        for j in range(curr, b):
            bd = boots[j][0]
            bdist = boots[j][1]
            for k in range(i + 1, min(n, i + bdist + 1)):
                if bd >= depths[k] and bd >= curr_depth:
                    discards[k] = min(discards[k], j)
                    # print(k, j)
                    # print(discards)
                # print(k)
    print(discards)
    fout.write(str(discards[-1]))
    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
