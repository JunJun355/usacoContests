"""
ID: 06jajun
LANG: PYTHON3
TASK: test
"""
from copy import copy


def main():
    n = int(input())
    arr = [int(c) for c in input().split()]
    # arr.append(-1)
    # print(n, arr)
    tot = 0
    stack = []
    for i in range(n):
        # print(stack)
        while stack and arr[stack[-1]] < arr[i]:
            stack.pop()
        if stack:
            tot += i - stack[-1] + 1
        stack.append(i)
    # print(tot)
    stack = []
    for i in range(n - 1, -1, -1):
        # print(stack)
        while stack and arr[stack[-1]] < arr[i]:
            stack.pop()
        if stack:
            tot += stack[-1] - i + 1
        stack.append(i)
    print(tot)




if __name__ == '__main__':
    main()
