"""
ID: 06jajun
LANG: PYTHON3
TASK: lemonade
"""
# * ->

def main():
    fin = open ('lemonade.in', 'r')
    fout = open ('lemonade.out', 'w')

    n = int(fin.readline())
    weights = [int(c) for c in fin.readline().split()]
    weights.sort()
    weights.reverse()
    for index, weight in enumerate(weights):
        if index > weight:
            fout.write(str(index) + '\n')
            return
    fout.write(str(n))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
