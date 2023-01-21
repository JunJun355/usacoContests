def main():
    q = int(input())
    for _ in range(q):
        n = int(input())
        b = 9
        reps = 1
        while n > reps * b:
            n -= reps * b
            reps += 1
            b *= 10
        skip = str(10**(reps - 1) + (n - 1) // reps)
        print(skip[(n - 1)%reps])

main()
