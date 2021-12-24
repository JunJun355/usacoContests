"""
ID: 06jajun
LANG: PYTHON3
TASK: convention
"""
# * ->

def main():
    fin = open ('convention.in', 'r')
    fout = open ('convention.out', 'w')

    n, m, c = [int(c) for c in fin.readline().split()]
    arrivals = [int(c) for c in fin.readline().split()]
    arrivals.sort()
    def works(t):
        nc = 0
        nf = arrivals[0]
        nm = 1
        for i in range(n):
            nc += 1
            if nc > c or arrivals[i] - nf > t:
                nm += 1
                nf = arrivals[i]
                nc = 1
                # print(arrivals[i])
        # print(nm)
        if nm > m: return 0
        return 1

    time = 32768
    while True:
        if works(time):
            break
        time *= 2
    top = time
    bot = 1
    while bot <= top:
        middle = (top + bot) // 2
        # print('---')
        curr = works(middle)
        # print(middle, curr)
        # print(arrivals)
        if curr:
            time = middle
            top = middle - 1
        else:
            bot = middle + 1
    fout.write(str(time))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
