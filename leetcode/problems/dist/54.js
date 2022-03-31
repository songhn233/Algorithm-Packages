function spiralOrder(matrix) {
    var n = matrix.length, m = matrix[0].length;
    var ans = [];
    var tot = n * m;
    var x = 0, y = 0;
    var dx = [1, 0, -1, 0], dy = [0, 1, 0, -1];
    var vis = Array(n)
        .fill(0)
        .map(function () { return Array(m).fill(false); });
    var check = function (x, y) {
        return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y];
    };
    var cur = 0;
    while (tot--) {
        vis[y][x] = true;
        ans.push(matrix[y][x]);
        var nx = x + dx[cur], ny = y + dy[cur];
        if (!check(nx, ny)) {
            cur = (cur + 1) % 4;
            (nx = x + dx[cur]), (ny = y + dy[cur]);
        }
        ;
        (x = nx), (y = ny);
    }
    return ans;
}
