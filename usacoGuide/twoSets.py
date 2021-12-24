def main():
    n = int(input())
    if n % 4 == 0 or n % 4 == 3:
        print('YES')
        high = n
        low = 0
        sumi = n * (n + 1) // 2
        ans = n
        while high >= low:
            middle = (low + high) // 2
            middlesumi = middle * (middle + 1) // 2
            if middlesumi > sumi // 2:
                high = middle - 1
                ans = min(middle, ans)
            elif middlesumi < sumi // 2:
                low = middle + 1
            else:
                ans = middle
                print(middle)
                print(' '.join([str(i) for i in range(1, middle + 1)]))
                print(n - middle)
                print(' '.join([str(i) for i in range(middle + 1, n + 1)]))
                return
        middle = ans
        middlesumi = middle * (middle + 1) // 2
        takeaway = middlesumi - sumi // 2
        print(middle - 1)
        print(' '.join([str(i) for i in range(1, middle + 1) if i != takeaway]))
        print(n - middle + 1)
        print(str(takeaway) + ' ' + ' '.join([str(i) for i in range(middle + 1, n + 1)]))
    else:
        print("NO")


if __name__ == '__main__':
    main()
