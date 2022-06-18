const findFrequentTreeSum = (root: TreeNode | null) => {
  const mp = new Map<number, number>()
  const dfs = (root: TreeNode | null) => {
    if (!root) {
      return 0
    }
    const lv = dfs(root.left)
    const rv = dfs(root.right)
    const sum = lv + rv + root.val
    mp.set(sum, mp.has(sum) ? mp.get(sum) + 1 : 1)
    return sum
  }
  dfs(root)
  const maxn = [...mp.values()].reduce((a, b) => (a > b ? a : b))
  return [...mp.keys()].reduce(
    (a, b) => (mp.get(b) === maxn ? [...a, b] : a),
    []
  )
}
