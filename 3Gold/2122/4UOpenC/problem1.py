"""
ID: 06jajun
LANG: PYTHON3
TASK: test
"""


def main():
    n = int(input())
    things = []
    for i in range(n):
        things.append([int(c) for c in input()])
    things.sort(key=lambda x: [x[1] + x[2]])
    i, j = 0, 0
    while i < len(cows) and j < len(apples):
        


if __name__ == '__main__':
    main()
