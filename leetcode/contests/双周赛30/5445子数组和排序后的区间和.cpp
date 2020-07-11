class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> t;
        for(int i=0;i<nums.size();i++) {
            long long temp=0;
            for(int j=i;j<nums.size();j++) {
                temp+=nums[j];
                 t.push_back(temp);
            }
        }
        sort(t.begin(),t.end());
        long long ans=0;
        long long p=1e9+7;
        for(int i=left-1;i<right;i++) ans=(ans+t[i])%p;
        return ans;
    }
};