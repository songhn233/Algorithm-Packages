const repeat = (n: number) => Array(n).fill(' ').join('')
function reorderSpaces(text: string): string {
  const count = (text.match(/\s/g) ?? []).length
  const words = text.split(' ').filter(Boolean)
  const len = words.length - 1
  if (len <= 0) {
    return words[0] + repeat(count)
  }
  return words.join(repeat(Math.floor(count / len))) + repeat(count % len)
}
