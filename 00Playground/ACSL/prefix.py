def main():
    inp = input().strip().split()

    ans = helper(inp, 0)

    print(ans)


def helper(inp, start):
    if start == len(inp): return str(0), start
    operator = inp[start]
    f = ""
    s = ""
    start = start + 1
    if is_num(inp[start]):
        f = inp[start]
    else:
        f, start = helper(inp, start)
    start = start + 1
    if is_num(inp[start]):
        s = inp[start]
    else:
        s, start = helper(inp, start)
    return str(eval(f+operator+s)), start


def is_num(c):
    try:
        int(c)
        return True
    except:
        return False


if __name__ == '__main__':
    main()
