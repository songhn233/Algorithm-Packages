function fizzBuzz(n: number): string[] {
  const ans: string[] = []
  for (let i = 1; i <= n; i++) {
    let tmp: string = ''
    if (i % 3 === 0) tmp += 'Fizz'
    if (i % 5 === 0) tmp += 'Buzz'
    if (tmp === '') tmp = i.toString()
    ans.push(tmp)
  }
  return ans
}
