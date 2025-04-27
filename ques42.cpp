/* Explain the concept of dynamic programming and its use in solving the maximum 
subarray problem. 

Ans:- Dynamic Programming is a method for solving complex problems by breaking them down into smaller overlapping subproblems and storing the results of these subproblems to avoid recalculating them again.

Key points in DP:
Overlapping subproblems: Same subproblems are solved multiple times.
Optimal substructure: The solution to a bigger problem depends on the solution to smaller problems.

Idea:
Instead of solving the same subproblems again and again, solve once and reuse it!

How Dynamic Programming relates to the Maximum Subarray Problem?
The Maximum Subarray Problem (finding the largest sum of a contiguous subarray) can be solved using DP.
In Kadane’s algorithm (which is a DP approach), we think like this:
For each element, what's the best maximum sum ending at that position?
Use previously computed maximum to build the current one.

The state we store:
maxEndingHere[i] = max(arr[i], maxEndingHere[i-1] + arr[i])

The transition:
Either start fresh from arr[i] or extend the previous subarray by adding arr[i].*/