//* Length of Largest Subarray with Sum 0
#include <bits/stdc++.h>
using namespace std;

int largest_subarray_zero_sum(vector<int> &vec)
{
    int max_count = 0;
    int sum = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
        if (sum == 0)
        {
            max_count = i + 1;
        }

        // if we already had this sum present,
        // that means from the end of that sum to this sum,
        // there is a subarray with total sum=0
        // that subarray is between these 2 sums arrays, and that is what we look for
        else if (mpp.find(sum) != mpp.end())
        {
            max_count = max(max_count, i - mpp[sum]);
        }
        else
        {
            mpp[sum] = i;
        }
    }
    return max_count;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> vec = {1, 3, -5, 6, -2};
    int ans = largest_subarray_zero_sum(vec);
    cout << ans << endl;
    return 0;
}