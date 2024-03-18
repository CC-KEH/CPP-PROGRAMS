//* Longest Consecutive Sequence
#include <bits/stdc++.h>
using namespace std;

int lcs(vector<int> &vec)
{
    unordered_set<int> st;
    int count = 0;
    int max_count = 0;

    for (int num : vec)
    {
        st.insert(num);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                count++;
                x++;
            }
            max_count = max(count, max_count);
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
    vector<int> vec = {100, 200, 1, 3, 2, 4};
    return 0;
}