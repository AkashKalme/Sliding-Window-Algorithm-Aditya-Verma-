// Minimum Window Substring
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s
// such that every character in t(including duplicates) is included in the window.If there is no such
// substring, return the empty string "".

#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t)
{
    string res = "";
    int lenres = INT_MAX;
    int resi = 0;
    int n = s.size();
    int m = t.size();
    if (n < m)
    {
        return res;
    }
    if (s == t)
    {
        return s;
    }
    unordered_map<char, int> mp;
    for (auto i : t)
    {
        mp[i]++;
    }
    int count = mp.size();
    int i = 0;
    int j = -1;
    while (j < n)
    {
        if (count != 0)
        {
            j++;
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    count--;
                }
            }
        }
        while (count == 0 && i <= j)
        {
            if (lenres > j - i + 1)
            {
                lenres = j - i + 1;
                resi = i;
            }
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                {
                    count++;
                }
            }
            i++;
        }
    }
    if (lenres == INT_MAX)
    {
        return res;
    }
    res = s.substr(resi, lenres);
    return res;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum Window Substring: " << minWindow(s, t) << "\n";
    return 0;
}