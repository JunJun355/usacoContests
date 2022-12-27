def main():
    fin = open("Day13.in", "r")
    ans = 0
    n = 150
    for i in range(n):
        inp1 = fin.readline().strip()
        inp2 = fin.readline().strip()
        # print(mysplit(inp1), mysplit(inp2))
        c = comp(mysplit(inp1), mysplit(inp2))
        # print(inp1, inp2, c)
        if c in [0, 1]:
            ans += i + 1
        fin.readline()
    print(ans)


def mysplit(str):
    # print(str)
    if ']' not in str: return [str]
    # print(0, ans)
    count = -1
    j = 1
    ans = []
    for i in range(len(str) - 1):
        if str[i] == '[':
            count += 1
        elif str[i] == ']':
            count -= 1
        if count == 0 and str[i] == ',':
            ans.append(str[j:i])
            j = i + 1
    # print(i, j)
    if str[j:-1] != '': ans.append(str[j:-1])
    # print(ans)
    return ans


def comp(s, t):
    # print(s, t)
    if len(s) == 1 and ']' not in s[0] and len(t) == 1 and ']' not in t[0]:
        s = s[0]
        t = t[0]
        # print('x')
        if int(s) < int(t): return 0
        if int(s) == int(t): return 1
        return 2

    n = len(s)
    m = len(t)
    for i in range(min(n, m)):
        # print('--', s[i], t[i])
        c = comp(mysplit(s[i]), mysplit(t[i]))
        if c == 0: return 0
        if c == 2: return 2
    if n < m: return 0
    if n == m: return 1
    return 2



def main1():
    fin = open("Day13.in", "r")
    ans = 0
    n = 150
    packets = []
    for i in range(n):
        inp1 = fin.readline().strip()
        inp2 = fin.readline().strip()
        packets.append(inp1)
        packets.append(inp2)
        fin.readline()
    packets.append('[[2]]')
    packets.append('[[6]]')
    # print(packets)
    for i in range(2 * n + 2):
        m = packets[0]
        for j in range(1, len(packets)):
            c = comp(mysplit(m), mysplit(packets[j]))
            if c not in [0, 1]:
                m = packets[j]
        packets.pop(packets.index(m))
        if m == '[[2]]':
            print(i)
        elif m == '[[6]]':
            print(i)
            return
        # print(m)


if __name__ == "__main__":
    main()
    # mysplit('[1]')
