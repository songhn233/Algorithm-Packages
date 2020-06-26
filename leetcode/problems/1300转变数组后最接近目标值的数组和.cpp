class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int l=0,r=arr.back();
        vector<int> s;int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            s.push_back(sum);
        }
        int ans=0x3f3f3f3f,res;
        int n=arr.size();
        for(int i=l;i<=r;i++)
        {
            int idx=upper_bound(arr.begin(),arr.end(),i)-arr.begin();
            int temp=0;
            if(idx!=0) temp+=s[idx-1];
            if(idx<=n) temp+=(n-idx)*i;
            if(abs(temp-target)<ans)
            {
                ans=abs(temp-target);
                res=i;
            }
        }
        return res;
    }
};