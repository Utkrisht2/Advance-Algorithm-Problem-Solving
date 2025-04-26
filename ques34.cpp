/* Solve the problem of finding the subarray sum equal to K using hashing. Write its 
algorithm, program. Find its time and space complexities. Explain with suitable 
example. */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    int currSum = 0, count = 0;

    for (int num : nums) {
        currSum += num;

        if (currSum == k) count++;

        if (prefixSumCount.find(currSum - k) != prefixSumCount.end())
            count += prefixSumCount[currSum - k];

        prefixSumCount[currSum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int k = 3;
    cout << "Number of subarrays with sum " << k << " is: " << subarraySum(arr, k) << endl;
    return 0;
}
