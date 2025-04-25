/* Solve the problem of finding the next greater element for each element in an array. 
Write its algorithm, program. Find its time and space complexities. Explain with 
suitable example. */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums[i])
            st.pop();

        if (!st.empty())
            result[i] = st.top();

        st.push(nums[i]);
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 25};
    vector<int> res = nextGreaterElements(nums);

    cout << "Next Greater Elements:\n";
    for (int val : res)
        cout << val << " ";
    return 0;
}
