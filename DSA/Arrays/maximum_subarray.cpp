//* Kadanes Algorithm

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &vec)
{
    long long sum = 0;
    long long max_sum = LONG_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
        if (sum > max_sum)
        {
            max_sum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = maxSubArray(vec);

    cout << ans << endl;
    return 0;
}
