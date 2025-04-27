/* Solve the problem of finding the next permutation of a given array. Write its algorithm, 
program. Find its time and space complexities. Explain with suitable example.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    
    // Step 1: Find first decreasing element
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    
    if (i >= 0) {
        int j = n - 1;
        // Step 2: Find element just larger than nums[i]
        while (nums[j] <= nums[i]) {
            j--;
        }
        // Step 3: Swap
        swap(nums[i], nums[j]);
    }
    
    // Step 4: Reverse the elements after i
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    
    cout << "Next Permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}
