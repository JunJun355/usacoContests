"""
ID: 06jajun
LANG: PYTHON3
TASK: div7
"""


def main():
    fin = open ('div7.in', 'r')
    fout = open ('div7.out', 'w')

    n = int(fin.readline())
    smallest = [-1] * 7
    smallest_index = [-1] * 7
    sums = [0]
    for i in range(n):
        sums.append(sums[-1] + int(fin.readline()))
    for i, sum in enumerate(sums):
        if smallest[sum % 7] == -1:
            smallest[sum % 7] = sum
            smallest_index[sum % 7] = i
    most = 0
    for i, sum in enumerate(sums):
        if smallest[sum % 7] != -1:
            most = max(most, i - smallest_index[sum % 7])
    fout.write(str(most))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
