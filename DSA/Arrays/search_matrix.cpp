//* Pow(x,n)

#include <bits/stdc++.h>
using namespace std;

bool search_matrix(vector<vector<int>> &matrix, int target)
{
    // Approach it like a 1D list.
    int row = matrix.size(), col = matrix[0].size();
    int start = 0, end = row * col - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2, element = matrix[mid / col][mid % col];
        if (element == target)
            return true;
        else if (element < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> vec = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool present = search_matrix(vec, 74);
    cout << present << endl;
    return 0;
}
