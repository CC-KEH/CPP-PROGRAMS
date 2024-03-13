//* Sort Colors (Dutch National flag algorithm.)

#include <bits/stdc++.h>
using namespace std;

void sort_colors(vector<int> &vec)
{
    int low = 0, mid = 0, high = vec.size() - 1;
    while (mid <= high)
    {
        // Case 0: Encountered 0
        if (vec[mid] == 0)
        {
            swap(vec[mid], vec[low]);
            low++;
            mid++;
        }
        // Case 1: Encountered 1
        else if (vec[mid] == 1)
        {
            mid++;
        }

        // Case 2: Encountered 2
        else
        {
            swap(vec[mid], vec[high]);
            high--;
        }
    }
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vec = {2, 0, 2, 1, 1, 0};
    sort_colors(vec);
    return 0;
}
