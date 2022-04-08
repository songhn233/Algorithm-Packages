function isHappy(n) {
    var next = function (n) {
        return String(n)
            .split('')
            .map(Number)
            .map(function (v) { return v * v; })
            .reduce(function (a, b) { return a + b; });
    };
    var a = next(n), b = n;
    while (a !== 1 && a !== b) {
        a = next(next(a));
        b = next(b);
    }
    return a === 1;
}
