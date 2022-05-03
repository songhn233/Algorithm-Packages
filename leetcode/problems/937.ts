function reorderLogFiles(logs: string[]): string[] {
  const stringArr = [],
    numberArr = []
  logs.forEach((log) => {
    const args = log.split(' ').slice(1)
    args.every((arg) => isNaN(Number(arg)))
      ? stringArr.push(log)
      : numberArr.push(log)
  })
  return [
    ...stringArr.sort((a, b) => {
      const arr: string[] = a.split(' ').slice(1),
        brr: string[] = b.split(' ').slice(1)
      if (arr.length === brr.length && arr.every((x, idx) => x === brr[idx])) {
        return a.split(' ')[0] < b.split(' ')[0] ? -1 : 1
      } else {
        let i = 0,
          j = 0
        while (i < arr.length && j < brr.length) {
          if (arr[i] !== brr[j]) {
            return arr[i] < brr[j] ? -1 : 1
          }
          ++i, ++j
        }
        return arr.length < brr.length ? -1 : 1
      }
    }),
    ...numberArr,
  ]
}
