//* Kadanes Algorithm

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &vec)
{
    int min_price = INT_MAX;
    int max_profit = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int profit = vec[i] - min_price;
        min_price = min(vec[i], min_price);
        max_profit = max(max_profit, profit);
    }

    return max_profit;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vec = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(vec);

    cout << ans << endl;
    return 0;
}
