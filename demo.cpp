//* Count Inversions.

#include <bits/stdc++.h>
using namespace std;

int count_inversions(vector<int> vec)
{
    //*Inversed pair
    // i < j but vec[i] > vec[j]
    int count = 0;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] > vec[j])
            {
                count++;
            }
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
    vector<int> vec = {1, 2, 3, 4, 5};
    int count = count_inversions(vec);
    cout << "Inversions: " << count << endl;
    return 0;
}
