function alienOrder(words: string[]): string {
  const edges: Record<string, Set<string>> = {}
  const count: Record<string, number> = {}
  for (let word of words) {
    for (let c of word) {
      if (!edges[c]) {
        edges[c] = new Set()
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
      if (!edges[pre[j]].has(cur[j])) {
        ++count[cur[j]]
        edges[pre[j]].add(cur[j])
      }
      break
    }
    if (j === len && pre.length > cur.length) {
      return ''
    }
  }
  const q = []
  Object.keys(edges).forEach((v) => {
    if (count[v] === 0) {
      q.push(v)
    }
  })
  const ans: string[] = []
  while (q.length) {
    const node = q.shift()
    ans.push(node)
    const list = edges[node]
    for (let v of list) {
      --count[v]
      if (count[v] === 0) {
        q.push(v)
      }
    }
  }
  if (ans.length !== Object.keys(edges).length) {
    return ''
  } else {
    return ans.join('')
  }
}
