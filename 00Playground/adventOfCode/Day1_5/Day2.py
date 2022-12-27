def main():
    fin = open("Day2", "r")
    inp = fin.readline().strip()
    ans = 0
    while inp != '-1':
        inp = inp.split()
        if (inp[0] == 'A'):
            if (inp[1] == 'X'): ans += 3
            if (inp[1] == 'Y'): ans += 4
            if (inp[1] == 'Z'): ans += 8
        if (inp[0] == 'B'):
            if (inp[1] == 'X'): ans += 1
            if (inp[1] == 'Y'): ans += 5
            if (inp[1] == 'Z'): ans += 9
        if (inp[0] == 'C'):
            if (inp[1] == 'X'): ans += 2
            if (inp[1] == 'Y'): ans += 6
            if (inp[1] == 'Z'): ans += 7
        inp = fin.readline().strip()
    print(ans)



if __name__ == '__main__':
    main()
