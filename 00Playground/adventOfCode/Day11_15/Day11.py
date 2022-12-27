def main():
    fin = open("Day11.in", "r")
    monkeys = []
    operations = []
    tests = []
    yn = []
    n = 8
    tots = [0] * n
    for i in range(n):
        fin.readline()
        inp = fin.readline().split()
        # print(inp)
        inp = [int(c[:-1]) for c in inp[2:]]
        monkeys.append(inp)
        operations.append(fin.readline().strip()[17:])
        tests.append(int(fin.readline().split()[-1]))
        curr = []
        curr.append(int(fin.readline().split()[-1]))
        curr.append(int(fin.readline().split()[-1]))
        yn.append(curr)
        fin.readline()
    # print(monkeys)
    # print(operations)
    # print(tests)
    # print(yn)
    prod = 1
    for i in tests: prod *= i
    for i in range(10000):
        for j in range(n):
            while monkeys[j]:
                tots[j] += 1
                old = monkeys[j].pop()
                new = eval(operations[j])
                # new //= 3
                # print(new)
                new = new % prod
                if new % tests[j] == 0:
                    # if (new % prod) % tests[j] == 0:
                    #     print(new)
                    # print(yn[j])
                    monkeys[yn[j][0]].append(new)
                else:
                    # if (new % prod) % tests[j] != 0:
                    #     print(new)
                    monkeys[yn[j][1]].append(new)
    tots.sort()
    print(tots)
    print(tots[-2] * tots[-1])
    # print(monkeys)
# 1385670

def main1():
    fin = open("Day11.in", "r")
    monkeys = []
    operations = []
    tests = []
    yn = []
    n = 8
    tots = [0] * n
    for i in range(n):
        fin.readline()
        inp = fin.readline().split()
        # print(inp)
        inp = [int(c[:-1]) for c in inp[2:]]
        monkeys.append(inp)
        operations.append(fin.readline().strip()[17:])
        tests.append(int(fin.readline().split()[-1]))
        curr = []
        curr.append(int(fin.readline().split()[-1]))
        curr.append(int(fin.readline().split()[-1]))
        yn.append(curr)
        fin.readline()
    # print(monkeys)
    # print(operations)
    # print(tests)
    # print(yn)
    for i in range(10000):
        for j in range(n):
            for k in range(len(monkeys[j]) - 1, -1, -1):
                tots[j] += 1
                old = monkeys[j][k]
                new = eval(operations[j])
                # new %= 1385670
                new %= 9699690
                if new % tests[j] == 0:
                    monkeys[j].pop(k)
                    # print(yn[j])
                    monkeys[yn[j][0]].append(new)
                else:
                    monkeys[j].pop(k)
                    monkeys[yn[j][1]].append(new)
    tots.sort()
    print(tots)
    print(tots[-2] * tots[-1])


if __name__ == '__main__':
    main1()
