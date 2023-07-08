// First Negative Number in Window of Size k

#include <bits/stdc++.h>

using namespace std;

vector<int> firstNegatives(int arr[], int n, int k)
{
    vector<int> res;
    int i = 0;
    int j = 0;
    queue<int> neg;
    while (j < n)
    {
        if (arr[j] < 0)
        {
            neg.push(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (neg.empty())
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(neg.front());
            }
            if (arr[i] == neg.front())
            {
                neg.pop();
            }
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    int arr[8] = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    cout << "First Negative Number in every Window of size " << k << " : ";
    vector<int> res = firstNegatives(arr, 8, k);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}