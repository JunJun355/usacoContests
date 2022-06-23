from collections import defaultdict


def main():
    inp = input().strip()
    dict = defaultdict(lambda: 0)
    for i in list(inp):
        dict[i] += 1
    arr = []
    oddTimes = 0
    oddIndex = -1
    for i in range(65, 91):
        arr.append(dict[chr(i)])
        if arr[-1] % 2 == 1:
            oddTimes += 1
            oddIndex = i - 65
    if oddTimes > 1:
        print("NO SOLUTION")
        return
    ansStr = ''
    for i in range(26):
        if i != oddIndex:
            ansStr += chr(i + 65) * (arr[i] // 2)
    if oddIndex != -1:
        print(ansStr + chr(oddIndex + 65) * arr[oddIndex] + ansStr[::-1])
        return
    print(ansStr + ansStr[::-1])


if __name__ == '__main__':
    main()
