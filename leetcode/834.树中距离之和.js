/*
 * @lc app=leetcode.cn id=834 lang=javascript
 *
 * [834] 树中距离之和
 */

// @lc code=start
/**
 * @param {number} N
 * @param {number[][]} edges
 * @return {number[]}
 */
const sumOfDistancesInTree = (N, edges) => {
  const map = new Array(N).fill(0).map(t => []);
  const nodeSize = new Array(N).fill(0);
  const dp = new Array(N).fill(0);
  const init = edges => {
    edges.forEach(edge => {
      const [u, v] = edge;
      map[u].push(v);
      map[v].push(u);
    });
  };
  const dfs = (u, fa) => {
    nodeSize[u] = 1;
    const vMap = map[u];
    vMap.forEach(v => {
      if (v === fa) {
        return ;
      }
      dfs(v, u);
      nodeSize[u] += nodeSize[v];
      dp[u] += dp[v] + nodeSize[v];
    });
  };
  const calc = (u, fa) => {
    const vMap = map[u];
    vMap.forEach(v => {
      if (v === fa) {
        return ;
      }
      dp[v] = dp[u] + N - 2 * nodeSize[v];
      calc(v, u);
    });
  };
  init(edges);
  dfs(0, -1);
  calc(0, -1);
  return dp;
};
// @lc code=end

