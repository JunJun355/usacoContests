def main():
    arr = ['0', '1']
    n = int(input())
    for i in range(n - 1):
        arr = ['0' + i for i in arr] + ['1' + i for i in arr[::-1]]
    print('\n'.join(arr))


if __name__ == '__main__':
    main()
