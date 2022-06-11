/**
 * @param {string} s
 * @param {string} sub
 * @param {character[][]} mappings
 * @return {boolean}
 */
var matchReplacement = function (s, sub, mappings) {
  const n = s.length,
    m = sub.length
  const mp = {}
  mappings.forEach(([a, b]) => {
    if (!mp[a]) {
      mp[a] = new Set()
    }
    mp[a].add(b)
  })
  for (let i = 0; i < n - m + 1; i++) {
    let flag = true
    for (let j = i; j <= i + m - 1; j++) {
      if (sub[j - i] == s[j] || (mp[sub[j - i]] && mp[sub[j - i]].has(s[j]))) {
        continue
      } else {
        flag = false
        break
      }
    }
    if (flag) {
      return true
    }
  }
  return false
}
