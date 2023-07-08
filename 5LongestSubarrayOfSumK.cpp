// Longest Subarray With Sum K (Positive + Negatives)

#include <bits/stdc++.h>

using namespace std;

int getLongestSubarray(int arr[], int n, int k)
{
    int res = 0;
    unordered_map<int, int> mp;
    int sum = 0;
    mp[sum] = 0;
    for (int j = 0; j < n; j++)
    {
        sum += arr[j];
        if (sum == k)
        {
            res = max(res, j + 1);
        }
        if (mp.find(sum - k) != mp.end())
        {
            res = max(res, j - mp[sum - k]);
        }
        else
        {
            mp[sum] = j;
        }
    }
    return res;
}

int main()
{
    int arr[7] = {-1, -3, 4, 0, 2, -3, 4};
    int k = 0;
    cout << "Maximum Subarray Sum: " << getLongestSubarray(arr, 7, k);
    return 0;
}