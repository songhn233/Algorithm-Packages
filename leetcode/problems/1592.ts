function reorderSpaces(text: string): string {
  const count = (text.match(/\s/g) ?? []).length
  const arr = text.split(' ').filter(Boolean)
  if (arr.length <= 1) {
    return arr[0] + Array(count).fill(' ').join('')
  }
  const rst = count % (arr.length - 1)
  const n = Math.floor(count / (arr.length - 1))
  const ans = arr.map((v, idx) =>
    idx < arr.length - 1 ? v + Array(n).fill(' ').join('') : v
  )
  return ans.join('') + Array(rst).fill(' ').join('')
}
