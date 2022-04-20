var toGoatLatin = function (s) {
    return s
        .split(' ')
        .map(function (v, idx) {
        return "" + (['a', 'e', 'i', 'o', 'u'].includes(v[0].toLowerCase())
            ? v + "ma"
            : "" + v.slice(1) + v[0] + "ma") + Array(idx + 1)
            .fill('a')
            .join('');
    })
        .join(' ');
};
