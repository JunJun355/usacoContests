def main():
    inp = input().strip().split()

    ans = helper(inp, len(inp) - 1)

    print(ans)


def helper(inp, start):
    if start == -1: return str(0), start
    operator = inp[start]
    f = ""
    s = ""
    start -= 1
    if is_num(inp[start]):
        f = inp[start]
    else:
        f, start = helper(inp, start)
    start -= 1
    if is_num(inp[start]):
        s = inp[start]
    else:
        s, start = helper(inp, start)
    return str(eval(s+operator+f)), start


def is_num(c):
    try:
        int(c)
        return True
    except:
        return False


if __name__ == '__main__':
    main()
