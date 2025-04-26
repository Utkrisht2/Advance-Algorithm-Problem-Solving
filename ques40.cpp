/* Solve the problem of finding the element with maximum frequency in an array. Write 
its algorithm, program. Find its time and space complexities. Explain with suitable 
example. */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxFrequencyElement(const vector<int>& nums) {
    unordered_map<int, int> freqMap;
    int maxFreq = 0;
    int maxElem = nums[0];

    for (int num : nums) {
        freqMap[num]++;
        if (freqMap[num] > maxFreq) {
            maxFreq = freqMap[num];
            maxElem = num;
        }
    }

    return maxElem;
}

int main() {
    vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 3, 3};
    int result = maxFrequencyElement(arr);
    cout << "Element with maximum frequency: " << result << endl;
    return 0;
}
