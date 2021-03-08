// Function to calculate (x ^ p) % MOD in O(log p)
// Limits: x -> [INT64_MIN, INT64_MAX], p -> [0, INT64_MAX]

int mod_expo(int x, int p, int mod = MOD) {
    int res = 1;
    x = ((x % mod) + mod) % mod;
    while (p > 0) {
        if (p & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }
    return res;
}

// Function to calculate y such that (x * y) % MOD = 1
// Requirements: MOD is prime
// Limits: x -> [INT64_MIN, INT64_MAX]

int mod_inv(int x, int mod = MOD) {
    return mod_expo(x, mod - 2, mod);
}
