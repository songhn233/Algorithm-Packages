class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n=A.size(),ans=0,maxx=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,maxx+A[i]-i);
            maxx=max(maxx,A[i]+i);
        }
        return ans;
    }
};