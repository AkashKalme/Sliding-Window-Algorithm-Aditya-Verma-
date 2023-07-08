// Count the Occurences of Anagrams

#include <bits/stdc++.h>

using namespace std;

int countAnagrams(string pat, string txt)
{
    int n = txt.size();
    int k = pat.size();
    int res = 0;
    map<char, int> mp;
    for (auto i : pat)
    {
        mp[i]++;
    }
    int distinct = mp.size();
    int i = 0;
    int j = 0;
    while (j < n)
    {
        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0)
            {
                distinct--;
            }
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (distinct == 0)
            {
                res++;
            }
            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++;
                if (mp[txt[i]] == 1)
                {
                    distinct++;
                }
            }
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    // string txt = "forxxorfxdofr";
    // string pat = "for";

    string txt = "aabaabaa";
    string pat = "aaba";
    cout << "Number of Anagrams: " << countAnagrams(pat, txt) << "\n";
    return 0;
}