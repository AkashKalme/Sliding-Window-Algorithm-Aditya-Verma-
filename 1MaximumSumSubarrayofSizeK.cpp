// Maximum Sum Subarray of size K

#include <bits/stdc++.h>

using namespace std;

int maxSubarraySum(int arr[], int n, int k)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int i = 0;
    int j = 0;
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            maxSum = max(sum, maxSum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

int main()
{
    int arr[7] = {2, 5, 1, 8, 2, 9, 1};
    int k = 3;
    cout << "Maximum Subarray Sum: " << maxSubarraySum(arr, 7, k);
    return 0;
}