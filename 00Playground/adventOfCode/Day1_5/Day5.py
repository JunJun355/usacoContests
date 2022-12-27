def main():
    fin = open("Day5.in", "r")
    ans = 0
    stacks = [
        list("QFMRLWCV"),
        list("DQL"),
        list("PSRGWCNB"),
        list("LCDHBQG"),
        list("VGLFZS"),
        list("DGNP"),
        list("DZPVFCW"),
        list("CPDMS"),
        list("ZNWTVMPC")
    ]

    for i in range(501):
        stuff = fin.readline().split()
        move = stacks[int(stuff[3]) - 1][-int(stuff[1]):]
        for j in range(int(stuff[1])):
            thing = stacks[int(stuff[3]) - 1].pop()

        for j in move: stacks[int(stuff[5]) - 1].append(j)
    print(''.join([stack[-1] for stack in stacks]))





def main1():
    fin = open("Day5.in", "r")
    ans = 0



if __name__ == '__main__':
    main()
