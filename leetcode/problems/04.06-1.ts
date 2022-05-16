const inorderSuccessor = function (root, p) {
  let cur = root,
    ans = null
  while (cur) {
    if (cur.val > p.val) {
      ans = cur
      cur = cur.left
    } else {
      cur = cur.right
    }
  }
  return ans
}
