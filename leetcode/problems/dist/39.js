function combinationSum(candidates, target) {
    var ans = [];
    var dfs = function (d, target, path) {
        if (d >= candidates.length || target < 0) {
            return;
        }
        if (target === 0) {
            ans.push(path.slice());
            return;
        }
        dfs(d + 1, target, path);
        path.push(candidates[d]);
        dfs(d, target - candidates[d], path);
        path.pop();
    };
    dfs(0, target, []);
    return ans;
}
