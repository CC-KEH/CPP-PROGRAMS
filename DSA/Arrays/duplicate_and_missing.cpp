//* Find Duplicate and Missing.

#include <bits/stdc++.h>
using namespace std;

pair<int, int> find_duplicate_and_missing(vector<int> &vec)
{
    int xr = 0;
    //* Step 1: XOR all numbers of vec with numbers from 1 - N.
    for (int i = 0; i < vec.size(); i++)
    {
        xr ^= vec[i];
        xr ^= (i + 1);
    }
    //* Step 2: Find the differentiating bit number.
    int df_bit = (xr & ~(xr - 1));

    //* Step 3: Again XOR all numbers of vec with numbers from 1 - N.
    // But, first divide in 2 groups based on df_bit, one and zero, and then xor.
    // We will left with one number in both variable.
    int zero = 0;
    int one = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        // Part of 1 Group.
        if (vec[i] & df_bit != 0)
        {
            one ^= vec[i];
        }
        // Part of 0 Group,
        else
        {
            zero ^= vec[i];
        }
    }
    for (int i = 1; i <= vec.size(); i++)
    {
        // Part of 1 Group.
        if ((i & df_bit) != 0)
        {
            one ^= i;
        }
        // Part of 0 Group,
        else
        {
            zero ^= i;
        }
    }
    //* Step 4: Identify the Numbers here.
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (zero == vec[i])
        {
            count++;
        }
    }
    if (count == 2)
    {
        return make_pair(zero, one);
    }
    return make_pair(one, zero);
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> vec = {1, 3, 4, 2, 2};
    pair<int, int> ans = find_duplicate_and_missing(vec);
    cout << "duplicate: " << ans.first << "\n"
         << "missing: " << ans.second << endl;
    return 0;
}
