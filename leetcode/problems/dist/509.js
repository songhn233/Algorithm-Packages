function fib(n) {
    var _a;
    if (n <= 1)
        return n;
    var f = [0, 1];
    for (var i = 2; i <= n; i++) {
        ;
        _a = [f[1], f[0] + f[1]], f[0] = _a[0], f[1] = _a[1];
    }
    return f[1];
}
