function minSubArrayLen(target, nums) {
    var n = nums.length;
    var l = 0, r = 0, sum = 0, ans = n + 1;
    while (r < n) {
        sum += nums[r++];
        while (sum >= target) {
            ans = Math.min(ans, r - l);
            sum -= nums[l++];
        }
    }
    return ans === n + 1 ? 0 : ans;
}
