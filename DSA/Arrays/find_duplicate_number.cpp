//* Find the Duplicate Number (Tortoise method)

#include <bits/stdc++.h>
using namespace std;

int find_duplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> vec = {1, 3, 4, 2, 2};

    int duplicate = find_duplicate(vec);
    cout << duplicate << endl;
    return 0;
}
