// Longest Subarray With Sum K (Positive + Negatives)

#include <bits/stdc++.h>

using namespace std;

int getLongestSubarray(int arr[], int n, int k)
{
    int res = 0;
    int sum = 0;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        sum += arr[j];
        while (i <= j && sum > k)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == k)
        {
            res = max(res, j - i + 1);
        }
    }
    return res;
}

int main()
{
    int arr[7] = {1, 2, 3, 1, 1, 1, 1};
    int k = 3;
    cout << "Maximum Subarray Sum: " << getLongestSubarray(arr, 7, k);
    return 0;
}