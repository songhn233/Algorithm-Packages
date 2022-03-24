function backspaceCompare(s, t) {
    var calc = function (arr) {
        var i = 0, j = 0;
        for (; j < arr.length; j++) {
            if (arr[j] === '#') {
                i && i--;
            }
            else {
                arr[i++] = arr[j];
            }
        }
        return arr.slice(0, i);
    };
    var srr = calc(s.split(''));
    var trr = calc(t.split(''));
    return srr.length === trr.length && trr.every(function (v, idx) { return v === srr[idx]; });
}
