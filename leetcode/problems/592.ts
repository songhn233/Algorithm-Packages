function gcd(a: number, b: number) {
  return b ? gcd(b, a % b) : a
}

function fractionAddition(expression: string): string {
  const list = [...expression.matchAll(/[-+]?\d+\/\d+/g)].map((v) => v[0])
  let a = 0,
    b = 1
  for (let v of list) {
    const [x, y] = v.split('/').map(Number)
    a = a * y + x * b
    b = y * b
  }
  if (a === 0) {
    return '0/1'
  }
  const t = gcd(Math.abs(a), Math.abs(b))
  return `${a / t}/${b / t}`
}
