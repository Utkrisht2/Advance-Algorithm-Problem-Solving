/* How to find the maximum XOR of two numbers in an array. Write its algorithm, 
program. Find its time and space complexities. Explain with suitable example. */

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum XOR
int maxXor(vector<int> &arr) {
    int res = 0;
    int fir = 0, sec = 0;
    // Generate all possible pairs
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if((arr[i]^arr[j]) > res){
              res = max(res, arr[i] ^ arr[j]);
             fir = arr[i], sec = arr[j];
            }
            }
    }
    return res;
}

int main() {
    vector<int> arr = {26, 100, 25, 13, 4, 14};
    cout << maxXor(arr);
    return 0;
}