class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1e4,res=0;
        for(int i=0;i<nums.size();i++) {
            vector<int> temp;
            for(int j=0;j<nums.size();j++) {
                if(j==i) continue;
                temp.push_back(nums[j]);
            }
            int tar=target-nums[i];
            for(int j=0;j<temp.size();j++) {
                int t=tar-temp[j];
                int l=j+1,r=(int)temp.size()-1;
                while(l<r) {
                    int mid=l+r>>1;
                    if(temp[mid]>=t) r=mid;
                    else l=mid+1;
                }
                if(temp[r]>=t) {
                    if(r==j) r++;
                    if(r<temp.size()&&abs(target-temp[r]-temp[j]-nums[i])<ans) {
                        ans=abs(target-temp[r]-temp[j]-nums[i]);
                        res=temp[r]+temp[j]+nums[i];
                    }
                }
                l=0,r=j-1;
                while(l<r) {
                    int mid=l+r+1>>1;
                    if(temp[mid]<=t) l=mid;
                    else r=mid-1;
                }
                if(temp[l]<=t)
                {
                    if(l==j) l--;
                    if(l>=0&&abs(target-temp[l]-temp[j]-nums[i])<ans) {
                        ans=abs(target-temp[l]-temp[j]-nums[i]);
                        res=temp[l]+temp[j]+nums[i];
                    }
                }
            }
        }
        return res;
    }
};