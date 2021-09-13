function findLongestWord(s: string, dictionary: string[]): string {
  let ans = ''
  for (let i = 0; i < dictionary.length; i++) {
    let x = 0,
      y = 0
    const n = dictionary[i].length,
      m = s.length
    while (x < n && y < m) {
      if (dictionary[i][x] === s[y]) x++, y++
      else y++
    }
    if (x >= n) {
      if (ans === '') {
        ans = dictionary[i]
      } else if (dictionary[i].length > ans.length) {
        ans = dictionary[i]
      } else if (dictionary[i].length === ans.length && dictionary[i] < ans) {
        ans = dictionary[i]
      }
    }
  }
  return ans
}
