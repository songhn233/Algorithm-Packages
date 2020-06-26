class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> f(n+1,0);
        f[0]=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<wordDict.size();j++) {
                int m=wordDict[j].size();
                if(m>i+1) continue;
                if(wordDict[j]==s.substr(i+1-m,m)) {
                    f[i+1]|=f[i+1-m];
                }
            }
        }
        return f[n];
    }
};