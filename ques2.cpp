/*Write a program to find the sum of elements in a given range [L, R] using a prefix sum 
array. Write its algorithm, program. Find its time and space complexities. Explain with 
suitable example*/

#include <iostream>
#include <vector>
using namespace std;

// Function to create prefix sum array
vector<int> createPrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}

// Function to find sum in range [L, R]
int rangeSum(const vector<int>& prefix, int L, int R) {
    if (L == 0)
        return prefix[R];
    return prefix[R] - prefix[L - 1];
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10}; // example array
    int L = 1, R = 3;

    vector<int> prefix = createPrefixSum(arr);
    int sum = rangeSum(prefix, L, R);

    cout << "Sum from index " << L << " to " << R << " is: " << sum << endl;
    return 0;
}
