"""
ID: 06jajun
LANG: PYTHON3
TASK: meetings
"""
from collections import deque, defaultdict


def main():
    t = int(input())
    for case in range(t):
        m, n, k = [int(c) for c in input().split()]
        if m <= k or n <= k:
            print("YES")
            continue
        cats = [int(c) for c in input().split()]
        nums = defaultdict(lambda: 0)
        for i in cats:
            nums[i] += 1
        lowest = sorted(cats, reverse=True)
        minf, mine = 0, 0
        i = 0
        while cats:
            # print(mine, i, n, cats)
            if minf <= cats[mine + i] <= minf + k - 1:
                nums[cats[mine + i]] -= 1
                n -= 1
                cats.pop(mine + i)
                if n == 0:
                    break
                if mine + k - 1 == n:
                    mine = max(0, mine - 1)
                while not nums[lowest[-1]]:
                    # print(nums)
                    # print(lowest)
                    # print(cats)
                    lowest.pop()
            elif minf < lowest[-1]:
                minf = lowest[-1]
                i = 0
            elif i < k - 1:
                i += 1
            elif mine + k < n:
                mine += 1
            else:
                print("NO")
                break
            i = min(i, n - 1)
        if not cats:
            print("YES")
        # else:
        #     print(cats)



if __name__ == '__main__':
    main()
