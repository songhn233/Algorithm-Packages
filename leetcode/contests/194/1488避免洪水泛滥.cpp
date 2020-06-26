class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n,-2);
        set<int> s;
        map<int,int> pre;
        for(int i=0;i<rains.size();i++) {
            if(rains[i]) {
                ans[i]=-1;
                if(pre.find(rains[i])!=pre.end()) {
                    auto it = s.lower_bound(pre[rains[i]]);
                    if(it==s.end()) return {};
                    ans[*it]=rains[i];
                    s.erase(it);
                    pre[rains[i]]=i;
                }
                else {
                    pre[rains[i]]=i;
                }
            }
            else {
                s.insert(i);
            }
        }
        for(int i=0;i<ans.size();i++) {
            if(ans[i]==-2) ans[i]=1;
        }
        return ans;
    } 
};