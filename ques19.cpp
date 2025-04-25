/* How to find the maximum product subarray. Write its algorithm, program. Find its time 
and space complexities. Explain with suitable example.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; ++i) {
        if (nums[i] < 0)
            swap(maxProd, minProd);

        maxProd = max(nums[i], nums[i] * maxProd);
        minProd = min(nums[i], nums[i] * minProd);

        result = max(result, maxProd);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray is: " << maxProduct(nums) << endl;
    return 0;
}
