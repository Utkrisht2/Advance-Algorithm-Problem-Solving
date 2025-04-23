/*Check if an array can be split into two parts such that the sum of the prefix equals the 
sum of the suffix. Write its algorithm, program. Find its time and space complexities. 
Explain with suitable example. */

#include <iostream>
#include <vector>
using namespace std;

bool canBeSplitWithEqualSum(const vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) {
        totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < arr.size() - 1; ++i) { // Exclude last element from left
        leftSum += arr[i];
        int rightSum = totalSum - leftSum;
        if (leftSum == rightSum) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 3};

    if (canBeSplitWithEqualSum(arr))
        cout << "Array can be split into two parts with equal sum." << endl;
    else
        cout << "Array cannot be split into two parts with equal sum." << endl;

    return 0;
}
