def main():
    filled = []
    for i in range(7): filled.append([False] * 7)
    def recurse(string, x=0, y=0, start=0):
        if start == 48:
            if 0 <= x <= 6 and 0 <= y <= 6 and not filled[x][y]:
                print(x, y)
                return 1
            return 0
        if x < 0 or x > 6 or y < 0 or y > 6: return 0
        if filled[x][y]: return 0
        filled[x][y] = True

        t = 0
        if string[start] == 'D' or string[start] == '?':
            t += recurse(string, x, y + 1, start + 1)
        if string[start] == 'U' or string[start] == '?':
            t += recurse(string, x, y - 1, start + 1)
        if string[start] == 'R' or string[start] == '?':
            t += recurse(string, x + 1, y, start + 1)
        if string[start] == 'L' or string[start] == '?':
            t += recurse(string, x - 1, y, start + 1)

        filled[x][y] = False

        return t

    print(recurse(input().strip()))


main()
