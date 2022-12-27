def main():
    fin = open("Day1.in", "r")
    inp = fin.readline().strip()
    sumi = 0
    maxi = [0] * 4
    while inp != '-1':
        if inp == '':
            maxi[0] = sumi
            maxi.sort()
            sumi = 0
        else:
            sumi += int(inp)
        inp = fin.readline().strip()
    print(sum(maxi[1:]))




if __name__ == '__main__':
    main()
