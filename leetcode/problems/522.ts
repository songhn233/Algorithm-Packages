const findLUSlength = (strs: string[]) => {
  let ans = -1
  for (let i = 0; i < strs.length; i++) {
    const str = strs[i]
    let flag = true
    for (let j = 0; j < strs.length; j++) {
      if (i === j) continue
      let x = 0,
        y = 0
      const target = strs[j]
      while (y < target.length) {
        if (str[x] === target[y]) {
          x++
        }
        y++
        if (x >= str.length) {
          flag = false
          break
        }
      }
      if (!flag) {
        break
      }
    }
    if (flag) {
      ans = Math.max(ans, str.length)
    }
  }
  return ans
}
