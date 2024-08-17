def millerRabin(n):
    isPrime = True

    thing = n - 1
    count = 0
    while thing % 2 == 0:
        count += 1
        thing //= 2

    # print(count, thing)

    primes = [2]
    for i in range(3, 45, 2):
        isP = True
        for prime in primes:
            if i % prime == 0:
                isP = False
        if isP:
            primes.append(i)

    # print(primes)

    for prime in primes:
        print(prime)
        isPrime = isPrime and subtest(n, prime, count, thing)

    return isPrime

def subtest(n, base, s, d):
    res = exp(base, d, n)
    if res == 1: return True
    while s >= 0:
        if res == n - 1: return True
        res = (res * res) % n
        s -= 1
    return False


def exp(base, ex, mod):
    if ex == 1: return base
    if ex == 0: return 1
    halfRes = exp(base, ex // 2, mod)
    return (halfRes * halfRes * (base if ex % 2 == 1 else 1)) % mod

if __name__ == '__main__':
    # print(exp(2, 3749528034479, 29996224275833))
    # print(subtest(29996224275833, 2, 3, 3749528034479))
    # print(millerRabin(22801763489))
    # print(millerRabin(29996224275833))
    print(millerRabin(1111111111111111111))
    print(millerRabin(12345678910987654321))
    