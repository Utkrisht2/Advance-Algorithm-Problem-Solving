/* Find the k-th smallest element in a sorted matrix. Write its algorithm, program. Find its 
time and space complexities. Explain with suitable example. */

#include <iostream>
#include <vector>
using namespace std;

// Helper to count elements <= mid in matrix
int countLessEqual(const vector<vector<int>>& matrix, int mid, int& smaller, int& larger) {
    int count = 0, n = matrix.size();
    int row = n - 1, col = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            smaller = max(smaller, matrix[row][col]);
            count += row + 1;
            col++;
        } else {
            larger = min(larger, matrix[row][col]);
            row--;
        }
    }

    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int smaller = matrix[0][0], larger = matrix[n - 1][n - 1];
        int count = countLessEqual(matrix, mid, smaller, larger);

        if (count < k)
            low = larger;
        else
            high = smaller;
    }

    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    cout << "K-th smallest element is: " << kthSmallest(matrix, k) << endl;
    return 0;
}
