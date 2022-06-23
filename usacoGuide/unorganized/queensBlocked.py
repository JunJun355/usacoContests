def main():
    block = [[], [], [], [], [], [], [], []]
    for i in range(8):
        curr = input()
        for j in range(8):
            if curr[j] == '*':
                block[j].append(i)
    print(recurse([], block))


def recurse(queens, block):
    if len(queens) == 8:
        # print(queens)
        return check(queens)
    ans = 0
    for i in range(8):
        if i not in queens and i not in block[len(queens)]:
            if check(queens + [i]):
                ans += recurse(queens + [i], block)
    return ans



def check(queens):
    for i in range(len(queens) - 1):
        if queens[i] + i == queens[-1] + len(queens) - 1:
            return 0
        if queens[i] - i == queens[-1] - len(queens) + 1:
            return 0
    return 1


if __name__ == '__main__':
    main()
