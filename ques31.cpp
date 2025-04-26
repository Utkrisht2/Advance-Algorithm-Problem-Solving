/* Use a deque to find the maximum in every sliding window of size K. Write its 
algorithm, program. Find its time and space complexities. Explain with suitable 
example. */

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices of elements not in this window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Remove indices of smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Add to result when first window is complete
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> maxVals = maxSlidingWindow(nums, k);
    for (int val : maxVals)
        cout << val << " ";
    return 0;
}
