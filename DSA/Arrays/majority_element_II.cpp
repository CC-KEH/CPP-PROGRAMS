//* Majority Elements (n/3)
// Extended Boyer Moore’s Voting Algorithm

#include <bits/stdc++.h>
using namespace std;

// floor(n/3): Indicates that there can be at max 2 elements.
// Eg: n = 9 -> floor(n/3) = 3, i.e freq of majority ele > 3, i.e. "4" -> 4,4,1 freq dstb
// Eg: n = 8 -> floor(n/3) = 2, i.e freq of majority ele > 2. i.e. "3" -> 3,3,1 freq dstb
// So we'll just use this approach, keep a count over 2 els.
vector<int> find_elements(vector<int> &nums)
{
    vector<int> ans;
    int count1 = 0;
    int count2 = 0;
    int ele1 = 0;
    int ele2 = 0;
    for (int num : nums)
    {
        if (count1 == 0 && ele2 != num)
        {
            ele1 = num;
            count1++;
        }
        else if (count2 == 0 && ele1 != num)
        {
            ele2 = num;
            count2++;
        }
        else if (ele1 == num)
            count1++;
        else if (ele2 == num)
            count2++;
        else
        {
            count1--;
            count2--;
        }
    }
    int final_count1 = 0;
    int final_count2 = 0;
    for (int num : nums)
    {
        if (num == ele1)
            final_count1++;
        else if (num == ele2)
            final_count2++;
    }
    int mini = floor(nums.size() / 3);

    if (final_count1 >= mini)
        ans.push_back(ele1);

    if (final_count2 >= mini)
        ans.push_back(ele2);

    return ans;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums = {3, 2, 3};
    vector<int> ans = find_elements(nums);

    return 0;
}
