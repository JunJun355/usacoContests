def main():
    n = int(input())
    arr = [int(c) for c in input().split()]
    prefixsum = 0
    times = [0] * n
    ans = 0
    for i in range(n):
        prefixsum += arr[i]
        ans += times[prefixsum % n]
        times[prefixsum % n] += 1
        if prefixsum % n == 0:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
