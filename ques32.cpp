/* How to find the largest rectangle that can be formed in a histogram. Write its algorithm, 
program. Find its time and space complexities. Explain with suitable example. */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        int currHeight;
        if (i == n)
            currHeight = 0;
        else
            currHeight = heights[i];
        
        while (!s.empty() && currHeight < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : (i - s.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        
        s.push(i);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    return 0;
}
