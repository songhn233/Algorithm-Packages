function alienOrder(words: string[]): string {
  const edges = new Map()
  const count: Record<string, number> = {},
    vis: Record<string, boolean> = {}
  for (let word of words) {
    for (let c of word) {
      if (!edges.has(c)) {
        edges.set(c, [])
        count[c] = 0
      }
    }
  }
  for (let i = 1; i < words.length; i++) {
    const pre = words[i - 1],
      cur = words[i]
    const len = Math.min(pre.length, cur.length)
    let j = 0
    for (j = 0; j < len; j++) {
      if (pre[j] === cur[j]) continue
      if (vis[`${pre[j]}${cur[j]}`]) break
      const val = edges.get(pre[j])
      edges.set(pre[j], [...val, cur[j]])
      vis[`${pre[j]}${cur[j]}`] = true
      ++count[cur[j]]
      break
    }
    if (j === len && pre.length > cur.length) {
      return ''
    }
  }
  const q = []
  ;[...edges.keys()].forEach((v) => {
    if (count[v] === 0) {
      q.push(v)
    }
  })
  const ans: string[] = []
  while (q.length) {
    const node = q.shift()
    ans.push(node)
    const list = edges.get(node)
    for (let v of list) {
      --count[v]
      if (count[v] === 0) {
        q.push(v)
      }
    }
  }
  if (ans.length !== [...edges.keys()].length) {
    return ''
  } else {
    return ans.join('')
  }
}
