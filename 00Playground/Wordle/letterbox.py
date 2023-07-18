from collections import defaultdict

def solve():
    string = "eyi lka vtg rou"
    board = [list(c) for c in string.split()]

    fin = open("word_list_any.txt", "r")
    fout = open("letterbox_list.txt", "w")
    letters = defaultdict(lambda: -1)
    for side in range(len(board)):
        for letter in board[side]:
            letters[letter] = side
    
    for inp in fin.readlines():
        inp = inp.strip()
        b = letters[inp[0]] != -1 and len(inp) >= 3
        for i in range(len(inp) - 1):
            if letters[inp[i + 1]] != -1 and letters[inp[i]] != letters[inp[i + 1]]:
                pass
            else:
                b = False

        if b: fout.write(inp + "\n")

    fin.close()
    fout.close()

    fin = open("letterbox_list.txt", "r")
    words = []
    for line in fin.readlines():
        words.append(line.strip())

    arr = []
    def recurse(letter, d = 5):
        if len(set(arr)) == 12 and d == 3:
            print(arr)
        if d == 0:
            if len(set(arr)) == 12:
                # print(arr)
                pass
            return
        try: arr.pop()
        except: pass
        for word in words:
            if word[0] == letter:
                for c in word:
                    arr.append(c)
                recurse(word[-1], d - 1)
                for c in word: arr.pop()
        arr.append(letter)
        return
    
    for c in letters:
        recurse(c)
    

        

if __name__ == '__main__':
    solve()