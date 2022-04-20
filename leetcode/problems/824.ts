const toGoatLatin = (s: string) =>
  s
    .split(' ')
    .map(
      (v, idx) =>
        `${
          ['a', 'e', 'i', 'o', 'u'].includes(v[0].toLowerCase())
            ? `${v}ma`
            : `${v.slice(1)}${v[0]}ma`
        }${Array(idx + 1)
          .fill('a')
          .join('')}`
    )
    .join(' ')
