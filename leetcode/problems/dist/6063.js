function maximumScore(scores, edges) {
    var map = {}, n = scores.length;
    var ans = -1;
    for (var i = 0; i < n; i++) {
        map[i] = [];
    }
    edges.forEach(function (_a) {
        var x = _a[0], y = _a[1];
        map[x].push([y, scores[y]]);
        map[y].push([x, scores[x]]);
    });
    for (var i = 0; i < n; i++) {
        map[i].sort(function (x, y) { return y[1] - x[1]; });
        map[i] = map[i].slice(0, 3);
    }
    edges.forEach(function (_a) {
        var x = _a[0], y = _a[1];
        var xx = map[x], yy = map[y];
        for (var i = 0; i < xx.length; i++) {
            for (var j = 0; j < yy.length; j++) {
                var a = xx[i][0], b = yy[j][0];
                if (a !== b && a !== y && b !== x) {
                    ans = Math.max(ans, xx[i][1] + yy[j][1] + scores[x] + scores[y]);
                }
            }
        }
    });
    return ans;
}
