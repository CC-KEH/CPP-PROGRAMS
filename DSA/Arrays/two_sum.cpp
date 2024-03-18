//* Two Sum
#include <bits/stdc++.h>
using namespace std;

pair<int, int> two_sum(vector<int> vec, int target)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < vec.size(); i++)
    {
        int more_needed = target - vec[i];
        if (ump.find(more_needed) != ump.end())
        {
            return make_pair(ump[more_needed], i);
        }
        ump[vec[i]] = i;
    }
    return make_pair(-1, -1);
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums = {3, 2, 1, 4};
    int target = 5;
    pair<int, int> ans = two_sum(nums, target);
    std::cout << "Pairs: " << ans.first << "," << ans.second << endl;
    return 0;
}
