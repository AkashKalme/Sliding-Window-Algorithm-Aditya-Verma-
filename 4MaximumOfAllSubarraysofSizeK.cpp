// Maximum of all subarrays of size k

#include <bits/stdc++.h>

using namespace std;

vector<int> maximumOfSubarrays(int arr[], int n, int k)
{
    vector<int> res;
    deque<int> q;
    int i = 0;
    int j = 0;
    while (j < n)
    {
        while (!q.empty() && q.back() < arr[j])
        {
            q.pop_back();
        }
        q.push_back(arr[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            res.push_back(q.front());
            if (q.front() == arr[i])
            {
                q.pop_front();
            }
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    int arr[8] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    cout << "Maximum Array of Given Array with size " << k << " : ";
    vector<int> res = maximumOfSubarrays(arr, 8, k);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}