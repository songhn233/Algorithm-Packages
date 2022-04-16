function numTrees(n) {
    var f = Array(n + 1).fill(0);
    f[0] = 1;
    for (var i = 1; i <= n; i++) {
        for (var j = 1; j <= i; j++) {
            f[i] += f[j - 1] * f[i - j];
        }
    }
    return f[n];
}
