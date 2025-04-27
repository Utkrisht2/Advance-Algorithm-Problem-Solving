/*How to find two numbers in an array that add up to a target using hashing. Write its 
algorithm, program. Find its time and space complexities. Explain with suitable 
example. */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numIndex; // num -> index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (numIndex.find(complement) != numIndex.end()) {
            return {numIndex[complement], i};
        }
        numIndex[nums[i]] = i;
    }

    return {}; // No solution found
}

int main() {
    vector<int> nums = {1, 2, 7, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
        cout << "Elements: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    } else {
        cout << "No two elements sum to target." << endl;
    }

    return 0;
}
