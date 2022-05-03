var __spreadArrays = (this && this.__spreadArrays) || function () {
    for (var s = 0, i = 0, il = arguments.length; i < il; i++) s += arguments[i].length;
    for (var r = Array(s), k = 0, i = 0; i < il; i++)
        for (var a = arguments[i], j = 0, jl = a.length; j < jl; j++, k++)
            r[k] = a[j];
    return r;
};
function reorderLogFiles(logs) {
    var stringArr = [], numberArr = [];
    logs.forEach(function (log) {
        var args = log.split(' ').slice(1);
        args.every(function (arg) { return isNaN(Number(arg)); })
            ? stringArr.push(log)
            : numberArr.push(log);
    });
    return __spreadArrays(stringArr.sort(function (a, b) {
        var arr = a.split(' ').slice(1), brr = b.split(' ').slice(1);
        if (arr.length === brr.length && arr.every(function (x, idx) { return x === brr[idx]; })) {
            return a.split(' ')[0] < b.split(' ')[0] ? -1 : 1;
        }
        else {
            var i = 0, j = 0;
            while (i < arr.length && j < brr.length) {
                if (arr[i] !== brr[j]) {
                    return arr[i] < brr[j] ? -1 : 1;
                }
                ++i, ++j;
            }
            return arr.length < brr.length ? -1 : 1;
        }
    }), numberArr);
}
