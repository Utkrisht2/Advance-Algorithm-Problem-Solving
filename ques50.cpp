/*Explain the concept of equilibrium index and its applications in array problems. */

#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int total_sum = 0;
    int left_sum = 0;

    // Calculate total sum of the array
    for (int num : arr) {
        total_sum += num;
    }

    // Traverse the array to find the equilibrium index
    for (int i = 0; i < arr.size(); ++i) {
        // Subtract the current element from the total sum
        total_sum -= arr[i];

        // Check if the left sum is equal to the remaining right sum
        if (left_sum == total_sum) {
            return i;
        }

        // Add the current element to the left sum
        left_sum += arr[i];
    }

    return -1; // No equilibrium index found
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    int index = findEquilibriumIndex(arr);
    if (index != -1) {
        cout << "Equilibrium index is: " << index << endl;
    } else {
        cout << "No equilibrium index found." << endl;
    }
    return 0;
}
