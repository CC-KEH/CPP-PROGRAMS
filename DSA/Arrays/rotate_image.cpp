//* Rotate Matrix

#include <bits/stdc++.h>
using namespace std;

void rotate_matrix(vector<vector<int>> &vec)
{
    // Transpose the Matrix.
    /*
        [1,2,3]     [1,4,7]
        [4,5,6] ->  [2,5,8]
        [7,8,9]     [3,6,9]
    */
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(vec[i][j], vec[j][i]);
        }
    }
    // Reverse each row.
    for (int i = 0; i < vec.size(); i++)
    {
        reverse(vec[i].begin(), vec[i].end());
    }
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate_matrix(vec);

    return 0;
}
