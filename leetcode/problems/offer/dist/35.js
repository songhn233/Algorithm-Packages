function searchInsert(nums, target) {
    var l = 0, r = nums.length - 1;
    while (l < r) {
        var mid = (l + r) >> 1;
        if (nums[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return nums[l] >= target ? l : nums.length;
}
