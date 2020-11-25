class Solution
{
public:
    string sortString(string s)
    {
        map<int, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a']++;
        }
        string ans = "";
        while (ans.size() < n)
        {
            for (int i = 0; i < 26; i++)
            {
                if (mp[i])
                {
                    ans += 'a' + i;
                    mp[i]--;
                }
            }
            for (int i = 25; i >= 0; i--)
            {
                if (mp[i])
                {
                    ans += 'a' + i;
                    mp[i]--;
                }
            }
        }
        return ans;
    }
};
