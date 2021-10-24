const countValidWords = (sentence: string) =>
  sentence
    .split(' ')
    .filter(Boolean)
    .map((v) => /^[a-z]*([a-z]-[a-z])?[a-z]*[!\.,]?$/.test(v))
    .filter(Boolean).length
