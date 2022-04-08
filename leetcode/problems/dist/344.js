function reverseString(s) {
    var _a;
    var l = -1, r = s.length;
    while (++l < --r) {
        ;
        _a = [s[r], s[l]], s[l] = _a[0], s[r] = _a[1];
    }
}
