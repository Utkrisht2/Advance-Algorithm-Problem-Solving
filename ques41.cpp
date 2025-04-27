/*Write a program to find the maximum subarray sum using Kadane’s algorithm. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArraySum(const vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArraySum(arr);
    cout << "Maximum subarray sum is: " << result << endl;
    return 0;
}
