#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n = (int)8e6+1;
    bool composites[n];
    for (int i=0; i<n; i++) composites[i] = false;
    vector<int> primes;
    primes.clear();

    for (int i=2; i<n; i++) {
        if (composites[i]) continue;
        primes.push_back(i);
        for (int j=2 * i; j<n; j+=i) {
            composites[j] = true;
        }
    }

    cout << primes.size() << endl;
}