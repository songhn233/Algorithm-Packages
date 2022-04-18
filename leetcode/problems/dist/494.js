function findTargetSumWays(nums, target) {
    var sum = nums.reduce(function (a, b) { return a + b; });
    if (Math.abs(target) > sum || (target + sum) & 1) {
        return 0;
    }
    var v = (target + sum) / 2, n = nums.length, m = sum, f = Array(m + 1).fill(0);
    f[0] = 1;
    for (var i = 0; i < n; i++) {
        for (var j = m; j >= nums[i]; j--) {
            f[j] += f[j - nums[i]];
        }
    }
    return f[v];
}
