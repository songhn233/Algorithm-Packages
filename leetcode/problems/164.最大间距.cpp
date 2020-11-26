class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans;
        if (nums.size() > 1)
            ans = nums[1] - nums[0];
        else
            ans = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
// @lc code=end
