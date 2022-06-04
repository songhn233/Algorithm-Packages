class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> sta;
        map<char, int> mp;
        map<char, bool> sp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (!sp[s[i]])
            {
                while (sta.size() && mp[sta.top()] && s[i] < sta.top())
                {
                    char temp = sta.top();
                    sta.pop();

                    sp[temp] = false;
                }
                sta.push(s[i]);
                sp[s[i]] = true;
            }
            mp[s[i]]--;
        }
        string ans = "";
        while (sta.size())
        {
            ans += sta.top();
            sta.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};