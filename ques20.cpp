/* Count all numbers with unique digits for a given number of digits. Write its algorithm, 
program. Find its time and space complexities. Explain with suitable example. */

#include <iostream>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    int result = 10, uniqueDigits = 9, available = 9;
    for (int i = 2; i <= n && available > 0; ++i) {
        uniqueDigits *= available;
        result += uniqueDigits;
        --available;
    }
    return result;
}

int main() {
    int n = 2;
    cout << "Count of numbers with unique digits for n = " << n << ": " 
         << countNumbersWithUniqueDigits(n) << endl;
    return 0;
}
