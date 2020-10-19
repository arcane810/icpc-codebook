// Function to calculate (x ^ p) % MOD in O(log p)
// Limits: x -> [INT64_MIN, INT64_MAX], p -> [0, INT64_MAX]

int mod_expo(int x, int p) {
    int res = 1;
    x = ((x % MOD) + MOD) % MOD;
    while (p > 0) {
        if (p & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        p /= 2;
    }
    return res;
}

// Function to calculate y such that (x * y) % MOD = 1
// Requirements: MOD is prime
// Limits: x -> [INT64_MIN, INT64_MAX]

int mod_inv(int x) {
    return mod_expo(x, MOD - 2);
}
