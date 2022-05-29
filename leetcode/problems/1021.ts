function removeOuterParentheses(s: string): string {
  let sta = 0,
    pre = 0
  const ans: string[] = []
  for (let i = 0; i < s.length; i++) {
    const v = s[i]
    if (v === '(') ++sta
    else --sta
    if (sta === 0) {
      ans.push(s.slice(pre, i + 1))
      pre = i + 1
    }
  }
  return ans.map((v) => v.slice(1, -1)).join('')
}
