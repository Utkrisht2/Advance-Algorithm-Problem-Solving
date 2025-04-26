/* Find all unique combinations of numbers that sum to a target. Write its algorithm, 
program. Find its time and space complexities. Explain with suitable example. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& candidates, int target, vector<int>& combination,
               vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > target) break; // Prune the search

        combination.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], combination, result, i); // i not i+1, reuse allowed
        combination.pop_back(); // backtrack
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combination;
    backtrack(candidates, target, combination, result, 0);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Unique combinations that sum to " << target << ":\n";
    for (auto& comb : result) {
        cout << "{ ";
        for (int num : comb) cout << num << " ";
        cout << "}\n";
    }

    return 0;
}
