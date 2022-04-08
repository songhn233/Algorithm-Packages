function fourSumCount(nums1, nums2, nums3, nums4) {
    var map = new Map();
    for (var i = 0; i < nums1.length; i++) {
        for (var j = 0; j < nums2.length; j++) {
            var sum = nums1[i] + nums2[j];
            if (map.has(sum)) {
                map.set(sum, map.get(sum) + 1);
            }
            else {
                map.set(sum, 1);
            }
        }
    }
    var ans = 0;
    for (var i = 0; i < nums3.length; i++) {
        for (var j = 0; j < nums4.length; j++) {
            var sum = nums3[i] + nums4[j];
            if (map.has(-sum)) {
                ans += map.get(-sum);
            }
        }
    }
    return ans;
}
