const MOD: i32 = 1337;
impl Solution {
    pub fn super_pow(a: i32, b: Vec<i32>) -> i32 {
        let mut pow = 0;
        for v in &b {
            pow = (pow * 10 % 1140 + v) % 1140;
        }
        Solution::quick_pow(a, pow)
    }
    fn quick_pow(a: i32, p: i32) -> i32 {
        let mut ans = 1;
        let mut a = a % MOD;
        let mut p = p;
        while p > 0 {
            if p & 1 == 1 {
                ans = (a * ans) % MOD;
            }
            a = (a * a) % MOD;
            p >>= 1;
        }
        ans
    }
}
