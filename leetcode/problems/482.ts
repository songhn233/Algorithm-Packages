const licenseKeyFormatting = (s: string, k: number) => {
  const arr = s.split('-').join('').split('')
  const n = arr.length
  const rest = n % k
  const ans = []
  if (rest) ans.push(arr.splice(0, rest).join(''))
  while (arr.length) ans.push(arr.splice(0, k).join(''))
  return ans
    .join('-')
    .split('')
    .map((v) => v.toUpperCase())
    .join('')
}
