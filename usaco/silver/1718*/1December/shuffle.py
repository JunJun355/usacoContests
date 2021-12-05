"""
ID: 06jajun
LANG: PYTHON3
TASK: shuffle
"""
# * ->

def main():
    fin = open ('shuffle.in', 'r')
    fout = open ('shuffle.out', 'w')

    n = int(fin.readline())
    shuffle = [int(c) - 1 for c in fin.readline().split()]
    included = set()
    stay = set()
    for i in range(n):
        if i not in included:
            curr = set()
            new = i
            while new not in curr and new not in included:
                curr.add(new)
                included.add(new)
                new = shuffle[new]
            if new not in curr and new in included: continue
            curr = set()
            while new not in curr:
                stay.add(new)
                curr.add(new)
                new = shuffle[new]

    fout.write(str(len(stay)))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
