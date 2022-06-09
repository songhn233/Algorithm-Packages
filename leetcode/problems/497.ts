class Solution {
    rects: number[][]
    sum: number[]
    constructor(rects: number[][]) {
      this.rects = rects
      this.sum = []
      const s = this.sum, n = this.rects.length
      for (let i = 0; i < n; i++) {
        s[i] = (i == 0 ? 0 : s[i - 1]) + 
        (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
      }
    }

    pick(): number[] {
      const n = this.rects.length, s = this.sum, rt = this.rects
      const target = Math.floor(Math.random() * s[n - 1]) + 1
      let l = 0, r = n - 1
      while(l < r) {
        let m = l + r >> 1
        if(s[m] >= target) r = m
        else l = m + 1
      }
      const arr = rt[l]
      const x = arr[0] + Math.floor(Math.random() * (arr[2] - arr[0] + 1)),
            y = arr[1] + Math.floor(Math.random() * (arr[3] - arr[1] + 1))
      return [x, y]
    }
}