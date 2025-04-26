/* Generate all subsets of a given array. Write its algorithm, program. Find its time and 
space complexities. Explain with suitable example.*/

#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }

    // Exclude current element
    generateSubsets(index + 1, nums, current, result);

    // Include current element
    current.push_back(nums[index]);
    generateSubsets(index + 1, nums, current, result);

    // Backtrack
    current.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(0, nums, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> allSubsets = subsets(nums);

    cout << "All subsets:\n";
    for (auto& subset : allSubsets) {
        cout << "{ ";
        for (int val : subset)
            cout << val << " ";
        cout << "}\n";
    }

    return 0;
}
