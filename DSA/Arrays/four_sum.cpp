//* Four Sum
#include <bits/stdc++.h>
using namespace std;

vector<int> four_sum(vector<int> &vec, int target)
{
    int n = vec.size();
    vector<vector<int>> ans;
    sort(vec.begin(), vec.end());

    // First Element
    for (int i = 0; i < n; i++)
    {
        // Taking care of duplicate
        if (i > 0 && vec[i] == vec[i - 1])
            continue;

        // Second Element
        for (int j = i + 1; j < n; j++)
        {

            // Taking care of duplicate
            if (j > i + 1 && vec[j] == vec[j - 1])
                continue;

            // Third and Fourth Element
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = vec[i];
                sum += vec[j];
                sum += vec[k];
                sum += vec[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {vec[i], vec[j], vec[k], vec[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && vec[k] == vec[k - 1])
                        k++;
                    while (k < l && vec[l] == vec[l + 1])
                        l--;
                }
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<int> ans = four_sum(nums, target);
    return 0;
}
