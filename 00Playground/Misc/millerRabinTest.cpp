#include <iostream>
#include <vector>

using namespace std;

#define ULL __int128

int print_uint128(ULL n) {
  if (n == 0)  return printf("0");

  char str[40] = {0}; // log10(1 << 128) + '\0'
  char *s = str + sizeof(str) - 1; // start at the end
  while (n != 0) {
    if (s == str) return -1; // never happens

    *--s = "0123456789"[n % 10]; // save last digit
    n /= 10;                     // drop it
  }
  return printf("%s", s);
}

ULL expmod(ULL base, ULL ex, ULL mod) {
    if (ex == 1) return base;
    if (ex == 0) return 1;
    ULL halfRes = expmod(base, ex / 2, mod);
    ULL res = (halfRes * halfRes) % mod;
    // cout << halfRes * halfRes << endl;
    res = (res * (ex % 2 == 1 ? base : 1)) % mod;
    
    // print_uint128(res);
    // cout << ' '; print_uint128(ex);
    // cout << endl;
    return res;
}

bool subtest(ULL n, ULL base, ULL s, ULL d) {
    ULL res = expmod(base, d, n);
    // print_uint128(res);
    // cout << "expmod complete" << " ";
    if (res == 1) return true;
    while (s >= 0) {
        if (res == n - 1) return true;
        res = (res * res) % n;
        s--;
    }
    return false;
}

bool millerRabin(ULL n) {
    bool isPrime = true;

    ULL thing = n - 1;
    ULL count = 0;
    while (thing % 2 == 0) {
        count++;
        thing /= 2;
    }

    vector<ULL> primes;
    for (ULL i=2; i < 45; i++) {
        bool isPrime = true;
        for (ULL prime : primes) {
            if (i % prime == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(i);
    }

    for (ULL prime : primes) {
        print_uint128(prime); cout << " ";
    }
    cout << endl;

    for (ULL prime : primes) {
        print_uint128(n); cout << " "; print_uint128(prime); cout << " "; print_uint128(count); cout << " "; print_uint128(thing); cout << endl;
        // cout << n << ' ' << prime << ' ' << count << ' ' << thing << endl;
        bool th = subtest(n, prime, count, thing);
        if (!th) return false;
    }

    return true;
}

int main() {
    // print_uint128(expmod(2, 3749528034479, 29996224275833));
    cout << millerRabin(29996224275833);
    // cout << subtest(29996224275833, 2, 3, 3749528034479);
    cout << endl;
    // cout << expmod(2, 3749528034479, 29996224275833) << endl;
    // cout << millerRabin(29996224275833) << endl;
}