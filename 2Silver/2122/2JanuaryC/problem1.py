"""
ID: 06jajun
LANG: PYTHON3
TASK: test
"""
from math import ceil, log, floor


def main():
    n = int(input())
    pairs = []
    for i in range(n):
        pairs.append([int(c) for c in input().split()])
    # print(pairs)
    for x, y in pairs:
        # print('---')
        i = 0
        if x == y:
            # print('--------------', 0)
            print(0)
            continue
        while x > y:
            # if x < y:
            #     if 2 * (x + 1) <= y:
            #         x += 1
            #     elif 2 * x <= y:
            #         x *= 2
            #     else:
            #         x += 1
            # else:
            if x % 2 == 0:
                x //= 2
            else:
                x += 1
            i += 1
            # print(x)
        search = []
        while x != 1:
            search.append([x, i])
            if x % 2 == 0:
                x //= 2
                i += 1
            else:
                x = (x + 1) // 2
                i += 2
        # print(search)
        found = []
        for num, tot in search:
            # print('--')
            while num < y:
                m = floor(log(y / num, 2))
                # print(m)
                if m != 0:
                    up = y // (2 ** m)
                else:
                    up = y
                tot += up - num
                num = up
                if num != y:
                    num *= 2
                    tot += 1
                # print(num)
            found.append(tot)

        # print(found, y)
        # print('-----------------', min(found))
        print(min(found))


if __name__ == '__main__':
    main()
