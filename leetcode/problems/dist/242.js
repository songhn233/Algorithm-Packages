function isAnagram(s, t) {
    if (s.length !== t.length)
        return false;
    var n = s.length;
    var map = Array(26).fill(0);
    var base = 'a'.charCodeAt(0);
    for (var i = 0; i < n; i++) {
        map[s[i].charCodeAt(0) - base]++;
        map[t[i].charCodeAt(0) - base]--;
    }
    return map.every(function (v) { return !v; });
}
