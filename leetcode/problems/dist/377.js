function combinationSum4(nums, target) {
    var f = Array(target + 1).fill(0), n = nums.length;
    f[0] = 1;
    for (var i = 0; i <= target; i++) {
        for (var j = 0; j < n; j++) {
            if (i >= nums[j])
                f[i] += f[i - nums[j]];
        }
    }
    return f[target];
}
