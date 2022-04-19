function lengthLongestPath(input) {
    var files = input.split('\n');
    var s = [0];
    var ans = 0;
    files.forEach(function (v) {
        var cnt = v.lastIndexOf('\t') + 1;
        while (cnt + 1 < s.length) {
            s.pop();
        }
        var length = s[s.length - 1] + (v.length - cnt + 1);
        s.push(length);
        if (v.includes('.')) {
            ans = Math.max(ans, length - 1);
        }
    });
    return ans;
}
