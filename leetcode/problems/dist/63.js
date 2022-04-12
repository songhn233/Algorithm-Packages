function uniquePathsWithObstacles(obstacleGrid) {
    var n = obstacleGrid.length, m = obstacleGrid[0].length;
    var f = Array(n)
        .fill(0)
        .map(function (_) { return Array(m).fill(0); });
    for (var i = 0; i < n && !obstacleGrid[i][0]; i++)
        f[i][0] = 1;
    for (var i = 0; i < m && !obstacleGrid[0][i]; i++)
        f[0][i] = 1;
    for (var i = 1; i < n; i++) {
        for (var j = 1; j < m; j++) {
            if (obstacleGrid[i][j] === 0) {
                f[i][j] = f[i][j - 1] + f[i - 1][j];
            }
        }
    }
    return f[n - 1][m - 1];
}
