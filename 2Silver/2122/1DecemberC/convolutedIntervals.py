"""
ID: 06jajun
LANG: PYTHON3
TASK: test
"""


def main():
    n, m = [int(c) for c in input().split()]
    f = [0] * (m + 1)
    pairs = []
    for _ in range(n):
        curr = [int(c) for c in input().split()]
        pairs.append(curr)
        f[curr[0]] += 1
        f[curr[-1]] -= 1
    


if __name__ == '__main__':
    main()
