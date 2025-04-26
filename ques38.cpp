/* Generate all permutations of a given array. Write its algorithm, program. Find its time 
and space complexities. Explain with suitable example.*/

#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]); // fix element at 'start'
        generatePermutations(nums, start + 1, result);
        swap(nums[start], nums[i]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> allPermutations = permute(nums);

    cout << "All permutations:\n";
    for (auto& permutation : allPermutations) {
        cout << "{ ";
        for (int val : permutation)
            cout << val << " ";
        cout << "}\n";
    }

    return 0;
}
