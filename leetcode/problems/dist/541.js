function reverseStr(s, k) {
    var arr = s.split('');
    var n = arr.length;
    var reverse = function (i, j) {
        var _a;
        var l = i - 1, r = j + 1;
        while (++l < --r) {
            ;
            _a = [arr[r], arr[l]], arr[l] = _a[0], arr[r] = _a[1];
        }
    };
    for (var i = 0; i < n; i += 2 * k) {
        if (i + k - 1 > n - 1) {
            reverse(i, n - 1);
        }
        else {
            reverse(i, i + k - 1);
        }
    }
    return arr.join('');
}
