//* Grid Unique Paths

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Simple Recursion (Exceeds Time Limit)
// int count_paths(int i, int j, int m, int n)
// {
//     if (i == (m - 1) && j == (n - 1))
//         return 1;
//     if (i >= m || j >= n)
//         return 0;
//     return count_paths(i + 1, j, m, n) + count_paths(i, j + 1, m, n);
// }

// Approach 2: Memoisation
int dp_count_paths(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == (m - 1) && j == (n - 1))
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }
    else if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    return dp[i][j] = dp_count_paths(i + 1, j, m, n, dp) + dp_count_paths(i, j + 1, m, n, dp);
}

int unique_paths(int m, int n)
{

    vector<vector<int>> dp(m, vector<int>(n, -1));
    int num = dp_count_paths(0, 0, m, n, dp);
    if (m == 1 && n == 1)
        return num;
    else
        return dp[0][0];
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m = 3;
    int n = 7;
    int paths = unique_paths(m, n);
    cout << paths << endl;
    return 0;
}
