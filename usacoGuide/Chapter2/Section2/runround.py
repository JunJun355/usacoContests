"""
ID: 06jajun
LANG: PYTHON3
TASK: runround
"""
best = float('inf')
def main():
    fin = open('runround.in', 'r')
    fout = open('runround.out', 'w')
    m = int(fin.readline().strip())
    fin.close()
    digs = [False] * 9
    numl = []

    def check():
        curr = 0
        s = set()
        n = len(numl)
        for i in range(n):
            curr = (curr + numl[curr]) % n
            s.add(curr)
        if len(s) == n:
            return True
        return False

    def recurse():
        if numl == []:
            for i in range(1, 10):
                numl.append(i)
                digs[i - 1] = True
                recurse()
                digs[i - 1] = False
                numl.pop()
            return
        numi = int(''.join([str(c) for c in numl]))
        global best
        if numi > best: return
        if numi > m and check():
            best = numi

        for i in range(1, 10):
            if digs[i - 1]:
                continue
            numl.append(i)
            digs[i - 1] = True
            recurse()
            digs[i - 1] = False
            numl.pop()
    recurse()
    fout.write(str(best)+'\n')
    fout.close()
    return


if __name__ == '__main__':
    main()
