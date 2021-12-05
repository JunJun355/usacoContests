"""
ID: 06jajun
LANG: PYTHON3
TASK: homework
"""
# * ->

def main():
    fin = open('homework.in', 'r')
    fout = open('homework.out', 'w')

    n = int(fin.readline())
    hmk = [int(c) for c in fin.readline().split()]
    hmk.reverse()
    s = hmk[0] + hmk[1]
    m = min(hmk[0], hmk[1])
    s -= m
    c = s
    ca = n - 2
    cas = [n - 2]
    for i in range(2, n - 1):
        if hmk[i] < m:
            s += m
            m = hmk[i]
            s -= hmk[i]
        s += hmk[i]
        if s / i > c:
            c = s / i
            ca = n - i - 1
            cas = [ca]
        elif s / i == c:
            cas.append(n - i - 1)
    cas.reverse()
    fout.write(str('\n'.join([str(nu) for nu in cas])))
    fin.close()
    fout.close()


if __name__ == '__main__':
    main()
