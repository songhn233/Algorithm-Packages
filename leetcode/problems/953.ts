function isAlienSorted(words: string[], order: string): boolean {
  const compare = words.slice()
  const map = order.split('').reduce((obj, v, idx) => {
    obj[v] = idx
    return obj
  }, {} as Record<string, number>)
  words.sort((a, b) => {
    let i = 0
    const t = Math.min(a.length, b.length)
    while (i < t) {
      if (map[a[i]] === map[b[i]]) {
        ++i
      } else {
        return map[a[i]] < map[b[i]] ? -1 : 1
      }
    }
    return a.length <= b.length ? -1 : 1
  })
  return compare.join() === words.join()
}
