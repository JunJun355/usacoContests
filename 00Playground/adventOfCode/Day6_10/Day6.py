def main():
    fin = open("Day6.in", "r")
    ans = 0
    inp = fin.readline().strip()
    curr = [inp[0]] * 4
    for i in range(len(inp)):
        curr[i % 4] = inp[i]
        if len(set(curr)) == 4:
            print(i + 1)
            return ;



def main1():
    fin = open("Day6.in", "r")
    ans = 0
    inp = fin.readline().strip()
    curr = [inp[0]] * 14
    for i in range(len(inp)):
        curr[i % 14] = inp[i]
        if len(set(curr)) == 14:
            print(i + 1)
            return ;



if __name__ == '__main__':
    main1()
