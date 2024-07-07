#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long N = 1 << 30;

long long lucas(long long n);

unordered_map<long long, long long> F;
long long fibonacci(long long n) {
    if (F.find(n) != F.end()) return F[n];
    long long ans;
    long long m = n >> 1;
    if (n % 2 == 0) {
        ans = lucas(m) * fibonacci(m);
    }
    else {
        ans = (lucas(m + 1) * fibonacci(m) + lucas(m) * fibonacci(m + 1)) >> 1;
    }
    F[n] = ans;
    return ans;
}

unordered_map<long long, long long> L;
long long lucas(long long n) {
    if (L.find(n) != L.end()) return L[n];
    long long ans, m = n >> 1;
    if (n % 2 == 0) {
        ans = (5 * fibonacci(m) * fibonacci(m) + lucas(m) * lucas(m)) >> 1;
    }
    else {
        ans = (5 * fibonacci(m) * fibonacci(m + 1) + lucas(m) * lucas(m + 1)) >> 1;
    }
    L[n] = ans;
    return ans;
}

int main() {
    F[0] = 0; F[1] = 1; F[2] = 1;
    L[0] = 2; L[1] = 1; L[2] = 3;
    cout << N << endl;
    cout << fibonacci(11);
}