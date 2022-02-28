"""
ID: 06jajun
LANG: PYTHON3
TASK: moobuzz
"""


def main():
    fin = open ('moobuzz.in', 'r')
    fout = open ('moobuzz.out', 'w')

    n = int(fin.readline())
    poss = [1, 2, 4, 7, 8, 11, 13, 14]
    ans = 15 * ((n - 1) // 8) + poss[(n - 1) % 8]
    fout.write(str(ans))

    fout.write('\n')
    fout.close()


def main1():
    fin = open ('moobuzz.in', 'r')
    fout = open ('moobuzz.out', 'w')

    n = int(fin.readline()) - 1
    list = [1, 2, 4, 7, 8, 11, 13, 14]
    fout.write(str(n // 8 * 15 + list[n % 8]))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
