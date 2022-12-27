def main():
    fin = open("Day4.in", "r")
    ans = 0
    for i in range(1000):
        inp = [[int(c) for c in d.split('-')] for d in fin.readline().split(',')]
        if (inp[0][0] <= inp[1][0] and inp[0][1] >= inp[1][1]):
            ans += 1
        elif (inp[0][0] >= inp[1][0] and inp[0][1] <= inp[1][1]):
            ans += 1
    print(ans)




def main1():
    fin = open("Day4.in", "r")
    ans = 0
    for i in range(1000):
        inp = [[int(c) for c in d.split('-')] for d in fin.readline().split(',')]
        if (inp[0][0] >= inp[1][0] and inp[0][0] <= inp[1][1]):
            ans += 1
            print(inp)
        elif (inp[0][1] >= inp[1][0] and inp[0][1] <= inp[1][1]):
            ans += 1
            print(inp)
        elif (inp[0][0] <= inp[1][0] and inp[1][0] <= inp[0][1]):
            ans += 1
            print(inp)
        elif (inp[0][0] <= inp[1][1] and inp[1][1] <= inp[0][1]):
            ans += 1
            print(inp)
    print(ans)


if __name__ == '__main__':
    main()
