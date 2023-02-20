"""
ID: 06jajun
LANG: PYTHON3
TASK: piepie
"""
# Na ->


def main():
    fin = open ('piepie.in', 'r')
    fout = open ('piepie.out', 'w')

    n, d = [int(c) for c in fin.readline().split()]
    bget, eget = [], []
    bhave, ehave = [], []
    for i in range(n):
        b, e = [int(c) for c in fin.readline().split()]
        eget.append(e)
        bhave.append(b)
    for _ in range(n):
        b, e = [int(c) for c in fin.readline().split()]
        bget.append(b)
        ehave.append(e)


    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
