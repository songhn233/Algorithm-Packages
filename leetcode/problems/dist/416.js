function canPartition(nums) {
    var n = nums.length, sum = nums.reduce(function (a, b) { return a + b; });
    if (sum & 1) {
        return false;
    }
    var f = Array(sum + 1).fill(false);
    f[0] = true;
    for (var i = 0; i < n; i++) {
        for (var j = sum; j >= nums[i]; j--) {
            f[j] |= f[j - nums[i]];
        }
    }
    return f[sum / 2];
}
