// Johny goes to a mall with his Mom. He wants to by toys. His Mom says to pick toys with given consitions:
// All toys must be consecutive.
// The type of toys must be of atmost k.
// Return the number of toys.

#include <bits/stdc++.h>

using namespace std;

int pickToys(string s, int k)
{
    int n = s.size();
    int res = 0;
    unordered_map<char, int> mp;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        mp[s[j]]++;
        while (mp.size() > k)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                mp.erase(s[i]);
            i++;
        }
        res = max(res, j - i + 1);
    }
    return res;
}

int main()
{
    string s = "abaccab";
    int k = 2;
    cout << "Maximum Number of Toys: " << pickToys(s, k) << "\n";
    return 0;
}