/*How to count the number of 1s in the binary representation of numbers from 0 to n. 
Write its algorithm, program. Find its time and space complexities. Explain with 
suitable example. */

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}

int main() {
    int n = 5;
    vector<int> result = countBits(n);
    cout << "Count of 1s from 0 to " << n << ": ";
    for (int i = 0; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
