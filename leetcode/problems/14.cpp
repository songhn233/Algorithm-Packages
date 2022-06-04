class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        int lim=(int)strs[0].size();
        int ans=0;
        for(int i=0;i<strs.size();i++) lim=min(lim,(int)strs[i].size());
        for(int len=0;len<lim;len++)
        {
            int flag=1;
            for(int i=1;i<strs.size();i++)
            {
                if(strs[i][len]==strs[0][len]) continue;
                flag=0;break;
            }
            if(flag) 
            {
                ans=len+1;
                continue;
            }
            else break;
        }
        return (strs[0].substr(0,ans));
    }
};