function numSquares(n) {
    var nums = [];
    var f = Array(n + 1).fill(Infinity);
    f[0] = 0;
    var i = 1;
    while (i * i <= n) {
        nums.push(i * i);
        ++i;
    }
    for (var i_1 = 0; i_1 < nums.length; i_1++) {
        for (var j = nums[i_1]; j <= n; j++) {
            f[j] = Math.min(f[j], f[j - nums[i_1]] + 1);
        }
    }
    return f[n];
}
