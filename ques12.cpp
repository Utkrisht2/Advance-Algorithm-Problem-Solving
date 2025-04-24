/* Rearrange numbers into the lexicographically next greater permutation. Write its 
algorithm, program. Find its time and space complexities. Explain with suitable 
example. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find first decreasing element from the end
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find the number just larger than nums[i] from the right
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the elements from i+1 to end
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}

