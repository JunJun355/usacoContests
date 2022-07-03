"""
ID: 06jajun
LANG: PYTHON3
TASK: zerosum
"""


def main():
    fin = open("zerosum.in", 'r')
    fout = open("zerosum.out", 'w')

    n = int(fin.readline().strip())

    def check(n, eq):
        f = ""
        eq.append('')
        for i in range(n):
            f+=str(i+1)
            f+=eq[i]
            # print(f)
        # print(f)
        if eval(f) == 0:
            f = ""
            for i in range(n):
                f += str(i+1)
                if eq[i] == "" and i != n - 1:
                    f += " "
                else: f += eq[i]
            fout.write(f+"\n")
        return 0

    def recurse(n, eq=[]):
        # print(n, eq)
        ans = 0
        if n == len(eq) + 1: return check(n, eq)
        for new in [[''], ['+'], ['-']]:
            ans += recurse(n, eq+new)
        return ans

    recurse(n)

    fin.close()
    fout.close()


if __name__ == '__main__':
    main()
