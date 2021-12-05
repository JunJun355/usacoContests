"""
ID: 06jajun
LANG: PYTHON3
TASK: mountains
"""
# * ->

def main():
    fin = open ('mountains.in', 'r')
    fout = open ('mountains.out', 'w')

    n = int(fin.readline())
    mountains = []
    for i in range(n):
        mountains.append([int(c) for c in fin.readline().split()])
    mountains.sort()
    # print(mountains)
    inmountains = []
    for mountain in mountains:
        # print(mountain)
        b, m = sum(mountain), mountain[1] - mountain[0]
        # print([b, m])
        while inmountains and m >= inmountains[-1][1]:
            inmountains.pop()
        if not inmountains or b > inmountains[-1][0]:
            inmountains.append([b, m])
        # print(inmountains)
    fout.write(str(len(inmountains)))
    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
