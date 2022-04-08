var __spreadArrays = (this && this.__spreadArrays) || function () {
    for (var s = 0, i = 0, il = arguments.length; i < il; i++) s += arguments[i].length;
    for (var r = Array(s), k = 0, i = 0; i < il; i++)
        for (var a = arguments[i], j = 0, jl = a.length; j < jl; j++, k++)
            r[k] = a[j];
    return r;
};
function intersection(nums1, nums2) {
    var set = new Set(nums1), ans = new Set();
    nums2.forEach(function (v) {
        if (set.has(v)) {
            ans.add(v);
        }
    });
    return __spreadArrays(ans.entries()).map(function (v) { return v[0]; });
}
