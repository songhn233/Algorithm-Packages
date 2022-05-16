/*
 * Encodes a tree to a single string.
 */
function serialize(root: TreeNode | null): string {
  const list = []
  const dfs = (root: TreeNode | null) => {
    if (!root) return
    list.push(root.val)
    if (root.left) dfs(root.left)
    if (root.right) dfs(root.right)
  }
  dfs(root)
  return list.join()
}
/*
 * Decodes your encoded data to tree.
 */
function deserialize(data: string): TreeNode | null {
  const list = data.split(',').filter(Boolean).map(Number)
  const dfs = (l: number, r: number) => {
    if (!list.length || list[0] < l || list[0] > r) {
      return null
    }
    const val = list.shift()
    const root = new TreeNode(val)
    root.left = dfs(l, val)
    root.right = dfs(val, r)
    return root
  }
  return dfs(-Number.MAX_SAFE_INTEGER, Number.MAX_SAFE_INTEGER)
}
