//* Given a matrix if an element in the matrix is 0.
//* then you will have to set its entire column and row to 0.
//* and then return the matrix.

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> set_zero(vector<vector<int>> &matrix, int m, int n)
{
    int row[m] = {0};
    int col[n] = {0};

    // Keep record of 0 in row no and col no in row and col arrays.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    matrix = set_zero(matrix, m, n);
    cout << "The Final matrix is: \n";
    for (auto it : matrix)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}

//* Approach 2
// class Solution {
// public:
// void setZeroes(vector<vector<int>> &matrix)
// {
//     int m = matrix.size();
//     int n = matrix[0].size();

//     vector<pair<int,int>> cords;

//     // Keep record of 0 cordinate in cords.
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 cords.push_back({i,j});
//             }
//         }
//     }

//     for(auto it : cords){
//         int r = it.first;
//         int c = it.second;
//         for(int i=0;i<m;i++){
//             matrix[i][c] = 0;
//         }
//         for(int j=0;j<n;j++){
//             matrix[r][j] = 0;
//         }
//     }
// }
// };