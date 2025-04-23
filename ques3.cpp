/*Solve the problem of finding the equilibrium index in an array. Write its algorithm, 
program. Find its time and space complexities. Explain with suitable example. */

#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) {
        totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int rightSum = totalSum - leftSum - arr[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += arr[i];
    }

    return -1; // No equilibrium index found
}

int main() {
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};

    int index = findEquilibriumIndex(arr);

    if (index != -1)
        cout << "Equilibrium index is: " << index << endl;
    else
        cout << "No equilibrium index found." << endl;

    return 0;
}
