//* Merge Overlapping Sub-intervals

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n <= 1)
    {
        return intervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    //
    // {1,3},{2,6} -> {1,6}
    //
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
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

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    intervals = merge(intervals);

    return 0;
}
