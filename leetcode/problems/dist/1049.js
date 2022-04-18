function lastStoneWeightII(stones) {
    var m = stones.reduce(function (a, b) { return a + b; }), f = Array(m).fill(0), n = stones.length;
    var max = function (a, b) { return (a > b ? a : b); };
    for (var i = 0; i < n; i++) {
        for (var j = m; j >= stones[i]; j--) {
            f[j] = max(f[j], f[j - stones[i]] + stones[i]);
        }
    }
    return Math.abs(m - 2 * f[Math.floor(m / 2)]);
}
