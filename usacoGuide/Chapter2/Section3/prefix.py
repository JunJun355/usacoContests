"""
ID: 06jajun
LANG: PYTHON3
TASK: prefix
"""


def main():
    fin = open("prefix.in", 'r')
    fout = open("prefix.out", 'w')

    primitives = fin.readline().strip().split()
    fin.readline()
    to_match = ""
    new = fin.readline().strip()
    while new:
        to_match += new
        new = fin.readline().strip()
    primitives.sort()
    n, m = len(to_match), len(primitives)

    indices = [0] * n

    def recurse(i=0):
        bot, top = 0, m - 1
        while bot <= top:
            

    fin.close()
    fout.close()


if __name__ == '__main__':
    main()
