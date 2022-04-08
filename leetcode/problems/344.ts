function reverseString(s: string[]): void {
  let l = -1,
    r = s.length
  while (++l < --r) {
    ;[s[l], s[r]] = [s[r], s[l]]
  }
}
