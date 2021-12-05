def main():
    print(recurse([]))


def recurse(queens):
    if len(queens) == 8:
        print(queens)
        return check(queens)
    ans = 0
    for i in range(8):
        if i not in queens:
            if check(queens + [i]):
                ans += recurse(queens + [i])
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
