//* number of subarrays with XOR K.
#include <bits/stdc++.h>
using namespace std;

int xor_k(vector<int> &vec, int &k)
{
    int xr = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++;
    int count = 0;
    for (int num : vec)
    {
        xr ^= num;
        int x = xr ^ k;
        if (mpp.find(x) != mpp.end())
        {
            count += mpp[x];
        }
        mpp[xr]++;
    }
    return count;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> vec = {5, 6, 7, 8, 9};
    int k = 5;
    int ans = xor_k(vec, k);
    cout << ans << endl;
    return 0;
}