from collections import defaultdict


def main():
    fin = open("Day7.in", "r")
    ans = 0
    pwd = []
    d = defaultdict(lambda: 0)
    inp = fin.readline().strip()
    while inp != '':
        inp = inp.split()
        if inp[0] == '$':
            if inp[1] == 'cd':
                if inp[2] == '/':
                    pwd = []
                elif inp[2] == '..':
                    pwd.pop()
                else:
                    pwd.append(inp[2])
            if inp[1] == 'ls':
                pass
        elif inp[0] == 'dir':
            pass
        else:
            curr = ''
            for p in pwd:
                curr += p
                d[curr] += int(inp[0])
        inp = fin.readline().strip()
    to_print = []
    for key in d:
        if d[key] <= 100000:
            to_print.append(key)
            ans += d[key]
    print('\n'.join(list(sorted(to_print))))
    print(ans)


def main1():
    fin = open("Day7.in", "r")
    ans = float('inf')
    pwd = []
    d = defaultdict(lambda: 0)
    inp = fin.readline().strip()
    while inp != '':
        inp = inp.split()
        if inp[0] == '$':
            if inp[1] == 'cd':
                if inp[2] == '/':
                    pwd = []
                elif inp[2] == '..':
                    pwd.pop()
                else:
                    pwd.append(inp[2])
            if inp[1] == 'ls':
                pass
        elif inp[0] == 'dir':
            pass
        else:
            curr = ''
            d[curr] += int(inp[0])
            for p in pwd:
                curr += p
                d[curr] += int(inp[0])
        inp = fin.readline().strip()
    good = d[''] - (70000000 - 30000000)
    for key in d:
        if d[key] >= good:
            ans = min(ans, d[key])
    print(ans)




if __name__ == '__main__':
    main1()
