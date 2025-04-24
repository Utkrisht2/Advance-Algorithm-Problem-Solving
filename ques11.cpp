/*Find two numbers in a sorted array that add up to a target. Write its algorithm, program. 
Find its time and space complexities. Explain with suitable example. */

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findTwoSum(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return {arr[left], arr[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {-1, -1}; // Not found
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 6, 10};
    int target = 10;
    auto result = findTwoSum(nums, target);

    if (result.first != -1)
        cout << "Pair found: " << result.first << " + " << result.second << " = " << target << endl;
    else
        cout << "No pair found.\n";

    return 0;
}
