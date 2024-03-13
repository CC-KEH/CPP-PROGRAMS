#include <bits/stdc++.h>

using namespace std;
// Pascals Triangle

vector<vector<int>> generate(int numRows)
{
    int N = numRows;

    vector<vector<int>> ans;
    for (int i = 0; i < N; i++)
    {
        ans.push_back(vector<int>());
        ans[i].push_back(1);
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == j)
                ans[i].push_back(1);

            else
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 3;
    vector<vector<int>> trg = generate(n);
    for (auto it : trg)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
