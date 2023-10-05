// Problem statement -:
// Given two values M and N, which represent a matrix[M][N]. Find the total number of unique paths from the top-leftmost cell (matrix[0][0]) to the bottom-rightmost cell (matrix[M-1][N-1]) 
// such that you are allowed to move in only two directions:- bottom and right.

//Approach -:
//since we have to count all possible ways so we use recursion to solve this program to cover all the possibilites , also
//overlapping subproblems can be seen here so we will use memoization ans tabulation methods to handle this.

// Below is the cpp code for memoization

#include<bits/stdc++.h>
using namespace std;

//1//MEMOIZATION
// Process of memoization involves three steps:
// 1) Represent the problem in form of indices ,i.e, func(i,j,dp).
// 2) Mention the base cases and check whether the answer has been previously computed or not.
// 3) Explore all the possibilities on every step .
// 4) Store the ans in dp vector and return it.

int countPaths(int i, int j, vector<vector<int>>& dp) {
    
    //Base cases:
    if (i == 0 && j == 0)
        return 1;

    // If we go outside the boundary of matrix, there are no ways so simply reuturn 0 from there.
    if (i < 0 || j < 0)
        return 0;


    // If we have already computed the number of ways for this cell, return it.
    if (dp[i][j] != -1)
        return dp[i][j];

    //On every cell we can perforn two tasks: either move up or move left
    int up = countPaths(i - 1, j, dp);
    int left = countPaths(i, j - 1, dp);

    //Store the result in dp vector and return the required value.
    return dp[i][j] = up + left;
}

int countWays(int m, int n) {

    // Create a vector of vector or a 2d-vector (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Here we will call the function with the bottom-right cell cordinates as the starting point (NOTE: memoization follows bottom-up appoach)
    return countPaths(m - 1, n - 1, dp);
}

int main() {
    // m=number of rows and n=number of columns
    int m,n;
    cin>>m>>n;

    //printing the result
    cout << "Number of ways to reach from (0,0) to (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}
