function shortestToChar(s, c) {
    var N = s.length;
    var ans = Array(s.length).fill(-1);
    var check = function (idx) { return idx >= 0 && idx <= s.length && ans[idx] === -1; };
    var q = [];
    for (var i = 0; i < s.length; i++) {
        if (s[i] === c) {
            ans[i] = 0;
            q.push(i);
        }
    }
    while (q.length) {
        var tmp = q.length;
        while (tmp--) {
            var idx = q.shift();
            if (check(idx - 1)) {
                q.push(idx - 1), (ans[idx - 1] = ans[idx] + 1);
            }
            if (check(idx + 1)) {
                q.push(idx + 1), (ans[idx + 1] = ans[idx] + 1);
            }
        }
    }
    return ans;
}
