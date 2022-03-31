function generateMatrix(n) {
    var ans = Array(n)
        .fill(0)
        .map(function (_) { return Array(n).fill(0); });
    var vis = Array(n)
        .fill(0)
        .map(function (_) { return Array(n).fill(false); });
    var x = 0, y = 0, cur = 0, tot = n * n;
    var dx = [0, 1, 0, -1], dy = [1, 0, -1, 0];
    var check = function (x, y) {
        return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y];
    };
    for (var i = 1; i <= tot; i++) {
        ;
        (vis[x][y] = true), (ans[x][y] = i);
        if (!check(x + dx[cur], y + dy[cur])) {
            cur = (cur + 1) % 4;
        }
        ;
        (x += dx[cur]), (y += dy[cur]);
    }
    return ans;
}
