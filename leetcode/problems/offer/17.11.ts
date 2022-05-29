const findClosest = (words: string[], word1: string, word2: string) =>
  words.reduce(
    ([a, b, ans], v, idx) => {
      v === word1 && (a = idx)
      v === word2 && (b = idx)
      if (a >= 0 && b >= 0) ans = Math.min(ans, Math.abs(a - b))
      return [a, b, ans]
    },
    [-1, -1, Infinity]
  )[2]
