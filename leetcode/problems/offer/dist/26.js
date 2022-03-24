function removeDuplicates(nums) {
    var i = 0, j = 1;
    var n = nums.length - 1;
    for (; j <= n; j++) {
        if (nums[j] === nums[i])
            continue;
        nums[++i] = nums[j];
    }
    return i + 1;
}
