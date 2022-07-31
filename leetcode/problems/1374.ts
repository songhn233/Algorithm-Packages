function generateTheString(n: number): string {
  return n & 1
    ? Array(n).fill('a').join('')
    : Array(n - 1)
        .fill('a')
        .join('') + 'b'
}
