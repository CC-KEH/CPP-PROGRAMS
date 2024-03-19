//* length of largest substring without duplicate characters.
#include <bits/stdc++.h>
using namespace std;

int largest_substr_no_duplicate(string &str)
{
    if (str.length() == 0)
        return 0;
    int len = 0;
    int left = 0;
    unordered_set<char> st;
    for (int right = 0; right < str.length(); right++)
    {
        if (st.find(str[right]) != st.end())
        {
            while (left < right && st.find(str[right]) != st.end())
            {
                st.erase(str[left]);
                left++;
            }
        }
        st.insert(str[right]);
        len = max(right - left + 1, len);
    }
    return len;
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str = "abcabcbb";
    int ans = largest_substr_no_duplicate(str);
    cout << ans << endl;
    return 0;
}