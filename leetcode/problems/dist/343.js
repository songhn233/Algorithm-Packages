function integerBreak(n) {
    var f = Array(n + 1).fill(0);
    f[2] = 1;
    for (var i = 3; i <= n; i++) {
        for (var j = 1; j < i; j++) {
            f[i] = Math.max(f[i], (i - j) * j, f[i - j] * j);
        }
    }
    return f[n];
}
