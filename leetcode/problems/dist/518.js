function change(amount, coins) {
    var f = Array(amount + 1).fill(0);
    f[0] = 1;
    for (var i = 0; i < coins.length; i++) {
        for (var j = coins[i]; j <= amount; j++) {
            f[j] += f[j - coins[i]];
        }
    }
    return f[amount];
}
