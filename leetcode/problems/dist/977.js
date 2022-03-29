function sortedSquares(nums) {
    var n = nums.length;
    var l = 0, r = n - 1;
    var ans = [];
    while (l <= r) {
        if (nums[l] * nums[l] >= nums[r] * nums[r]) {
            ans.push(nums[l] * nums[l]);
            ++l;
        }
        else {
            ans.push(nums[r] * nums[r]);
            --r;
        }
    }
    return ans.reverse();
}
