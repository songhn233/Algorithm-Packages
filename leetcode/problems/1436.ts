function destCity(paths: string[][]): string {
  const map = new Map()
  for (let [s] of paths) {
    if (map.has(s)) {
      map.set(s, map.get(s) + 1)
    } else {
      map.set(s, 1)
    }
  }
  for (let [_, t] of paths) {
    if (!map.has(t)) {
      return t
    }
  }
}
