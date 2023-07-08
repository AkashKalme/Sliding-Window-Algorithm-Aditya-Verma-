// Longest Substring Without Repeating Characters

#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int res = 0;
    unordered_map<char, int> mp;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        mp[s[j]]++;
        while (mp.size() < j - i + 1)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        res = max(res, j - i + 1);
    }
    return res;
}

int main()
{
    string s = "abcabcbb";
    cout << "Number of Anagrams: " << lengthOfLongestSubstring(s) << "\n";
    return 0;
}