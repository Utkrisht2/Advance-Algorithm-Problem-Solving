/* How to check if a number is a power of two using bit manipulation. Write its algorithm, 
program. Find its time and space complexities. Explain with suitable example. */

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n = 16;
    if (isPowerOfTwo(n))
        cout << n << " is a power of two." << endl;
    else
        cout << n << " is NOT a power of two." << endl;
    return 0;
}
