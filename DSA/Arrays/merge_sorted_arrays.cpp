//* Merge Sorted Arrays STL and Gap Method

#include <bits/stdc++.h>
using namespace std;

// Approach 1 STL
// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         nums1[i + m] = nums2[i];
//     }
//     sort(nums1.begin(), nums1.end());
// }

void swap_if_greater(vector<int> &nums1, int left, vector<int> &nums2, int right)
{
    if (nums1[left] > nums2[right])
    {
        swap(nums1[left], nums2[right]);
    }
    return;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // 0s are present as a placeholders for nums2 elements, in nums1.
    int len = m + n;
    // Gap => ceil(m+n/2)
    // Eg: (4,5): 9 / 2 = 4; 9 % 2 = 1 -> 5
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        // 2 pointers, 1st on left i.e. 0th index, 2nd on left+gap
        int left = 0;
        int right = gap + left;
        while (right < len)
        {
            // Left in First Array, Right in Second Array.
            if (left < m && right >= m)
            {
                swap_if_greater(nums1, left, nums2, right - m);
            }
            // Both Left and Right in Second Array.
            else if (left >= m)
            {
                swap_if_greater(nums1, left - m, nums2, right - m);
            }
            // Both Left and Right in First Array.
            else
            {
                swap_if_greater(nums1, left, nums2, right);
            }
            left++, right++;
        }
        if (gap == 1)
        {
            break;
        }
        gap = (gap / 2) + (gap % 2);
    }

    for (int i = 0; i < n; i++)
    {
        nums1[i + m] = nums2[i];
    }
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << "\n";
    return 0;
}
