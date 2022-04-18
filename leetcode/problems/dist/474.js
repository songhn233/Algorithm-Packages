function findMaxForm(strs, m, n) {
    var f = Array(m + 1)
        .fill(0)
        .map(function (_) { return Array(n + 1).fill(0); });
    for (var _i = 0, strs_1 = strs; _i < strs_1.length; _i++) {
        var s = strs_1[_i];
        var x = s.split('').filter(function (i) { return i === '0'; }).length, y = s.split('').filter(function (i) { return i === '1'; }).length;
        for (var i = m; i >= x; i--) {
            for (var j = n; j >= y; j--) {
                f[i][j] = Math.max(f[i][j], f[i - x][j - y] + 1);
            }
        }
    }
    return f[m][n];
}
