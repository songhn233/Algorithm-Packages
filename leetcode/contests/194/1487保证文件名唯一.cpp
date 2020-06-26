class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string,int> mp;
        vector<string> ans;
        for(int i=0;i<names.size();i++){
            mp[names[i]]++;
            if(mp[names[i]]>1) {
                while(mp[names[i]+"("+to_string(mp[names[i]]-1)+")"])
                {
                    mp[names[i]]++;
                }
                mp[names[i]+"("+to_string(mp[names[i]]-1)+")"]++;
                ans.push_back(names[i]+"("+to_string(mp[names[i]]-1)+")");
            }
            else ans.push_back(names[i]);
        }
        return ans;
    }
};