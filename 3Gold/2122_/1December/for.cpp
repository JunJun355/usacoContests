#include <iostream>


using namespace std;

int main() {
    cout << ~(-5) << ' ' <<  (bool) ~(-1) << endl;
    for (int i=4; ~i; i--) {
        cout << i << ~i << endl;
    }
}