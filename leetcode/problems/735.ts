function asteroidCollision(asteroids: number[]): number[] {
  const s: number[] = []
  for (let v of asteroids) {
    if (v < 0) {
      while (s.length > 0 && s[s.length - 1] > 0 && -v > s[s.length - 1]) {
        s.pop()
      }
      if (s.length === 0 || (s.length > 0 && s[s.length - 1] < 0)) {
        s.push(v)
      }
      if (s.length > 0 && s[s.length - 1] > 0 && -v == s[s.length - 1]) {
        s.pop()
      }
    } else {
      s.push(v)
    }
  }
  return s
}
