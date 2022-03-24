function backspaceCompare(s: string, t: string): boolean {
  const calc = (arr: string[]) => {
    let i = 0,
      j = 0
    for (; j < arr.length; j++) {
      if (arr[j] === '#') {
        i && i--
      } else {
        arr[i++] = arr[j]
      }
    }
    return arr.slice(0, i)
  }
  const srr = calc(s.split(''))
  const trr = calc(t.split(''))
  return srr.length === trr.length && trr.every((v, idx) => v === srr[idx])
}
