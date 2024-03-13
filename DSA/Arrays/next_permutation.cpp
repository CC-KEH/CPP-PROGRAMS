//* Next Permutation

#include <bits/stdc++.h>
using namespace std;

void next_permutation(vector<int> &vec)
{

    // Step 1: Find the breakpoint
    int bpt = -1;
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        if (i < vec.size() - 1 && vec[i] < vec[i + 1])
        {
            bpt = i;
            break;
        }
    }

    // Check if bpt is still -1, that means vec is sorted, just return the reversed vec
    if (bpt == -1)
    {
        reverse(vec.begin(), vec.end());
        return;
    }

    // Step 2: Find the Smallest number that is still greater than the ele at breakpt, and swap them.
    //* {1, 2, 3, 4, 7, 6, 5} -> {1, 2, 3, 5, 7, 6, 4}

    for (int i = vec.size() - 1; i > bpt; i--)
    {
        if (vec[i] > vec[bpt])
        {
            swap(vec[i], vec[bpt]);
            break;
        }
    }

    // Step 3: Reverse the Right half of the vec
    //* {1, 2, 3, 4, 7, 6, 4} -> {1, 2, 3, 5, 4, 6, 7}

    reverse(vec.begin() + bpt + 1, vec.end());
}

int main()
{
#ifndef ONLINE_JOB
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vec = {1, 2, 3, 4, 7, 6, 5};
    next_permutation(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
