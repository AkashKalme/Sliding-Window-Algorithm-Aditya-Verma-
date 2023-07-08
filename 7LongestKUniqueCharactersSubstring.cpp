// Longest K unique characters substring

#include <bits/stdc++.h>

using namespace std;

int longestKSubstr(string s, int k)
{
    int n = s.size();
    int res = 0;
    unordered_map<char, int> mp;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            continue;
        }
        else if (mp.size() == k)
        {
            res = max(res, j - i + 1);
        }
        else
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
    }
    return res;
}

int main()
{
    string s = "aabacbebebe";
    int k = 3;
    cout << "Number of Anagrams: " << longestKSubstr(s, k) << "\n";
    return 0;
}