function peakIndexInMountainArray(arr: number[]): number {
  for (let i = 0; i < arr.length; i++) {
    if (i > 0 && arr[i] < arr[i - 1]) {
      return i - 1
    }
  }
}
