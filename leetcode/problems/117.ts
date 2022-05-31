interface Node {
  left: Node
  right: Node
  next: Node
}

function connect(root: Node | null): Node | null {
  if (!root) return root
  let last: Node | null = null,
    nextStart: Node | null = null
  let start: Node | null = root
  const work = (node: Node) => {
    if (last) last.next = node
    if (!nextStart) nextStart = node
    last = node
  }
  while (start) {
    ;(last = null), (nextStart = null)
    for (let t = start; t; t = t.next) {
      if (t.left) work(t.left)
      if (t.right) work(t.right)
    }
    start = nextStart
  }
  return root
}
