/*Find the maximum sum of any subarray of size K in a given array. Write its algorithm, 
program. Find its time and space complexities. Explain with suitable example.*/

#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarrayOfSizeK(const vector<int>& arr, int K) {
    int n = arr.size();
    if (K > n) return -1;

    // Compute the sum of the first window
    int windowSum = 0;
    for (int i = 0; i < K; ++i) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for (int i = K; i < n; ++i) {
        windowSum += arr[i] - arr[i - K];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int K = 3;

    int result = maxSumSubarrayOfSizeK(arr, K);
    cout << "Maximum sum of subarray of size " << K << " is: " << result << endl;

    return 0;
}
