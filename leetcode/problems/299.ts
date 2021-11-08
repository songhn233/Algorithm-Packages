function getHint(secret: string, guess: string): string {
  const n = secret.length
  let a = 0,
    b = 0
  let x = Array(10).fill(0),
    y = Array(10).fill(0)
  for (let i = 0; i < n; i++) {
    if (secret[i] === guess[i]) {
      a++
    } else {
      x[secret[i]]++, y[guess[i]]++
    }
  }
  for (let i = 0; i < 10; i++) {
    b += Math.min(x[i], y[i])
  }
  return `${a}A${b}B`
}
