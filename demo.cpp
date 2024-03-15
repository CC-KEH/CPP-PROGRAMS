//* Count Reverse Pairs
#include <bits/stdc++.h>
using namespace std;

// i < j and arr[i] > 2 * arr[j];
int count_reversed(vector<int> &vec)
{
    int n = vec.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (vec[i] > vec[j] * 2)
                count++;
        }
    }
    return count;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums = {3, 2, 1, 4};
    int count = count_reversed(nums);
    cout << count << endl;
    return 0;
}
