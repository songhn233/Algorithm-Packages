const connect = (root: Node | null) => {
  if (!root) return root
  const q = []
  let preRoot = null
  q.push(root)
  while (q.length) {
    let len = q.length
    while (len--) {
      const top = q.shift()
      top.next = null
      if (preRoot) {
        preRoot.next = top
      }
      preRoot = top
      if (top.left) q.push(top.left)
      if (top.right) q.push(top.right)
    }
    preRoot = null
  }
  return root
}
