def main():
    fin = open("Day3.in", "r")
    inp = fin.readline().strip()
    ans = 0
    while inp != '-1':
        n = len(inp) // 2
        inp1 = inp[:n]
        inp2 = inp[n:]
        over = list(set(list(inp1)).intersection(set(list(inp2))))
        over = over[0]
        if ord(over) > 96:
            ans += ord(over) - 96
        else: ans += ord(over) - 38
        print(ans)
        inp = fin.readline().strip()


def main1():
    fin = open("Day3.in", "r")
    inp = [fin.readline().strip() for i in range(3)]
    ans = 0
    while len(inp) == 3:
        over = list(set(list(inp[0])).intersection(set(list(inp[1])).intersection(set(list(inp[2])))))
        over = over[0]
        if ord(over) > 96:
            ans += ord(over) - 96
        else: ans += ord(over) - 38
        print(ans)
        inp = [fin.readline().strip() for i in range(3)]



if __name__ == '__main__':
    main1()
