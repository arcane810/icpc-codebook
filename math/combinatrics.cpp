// Function to precalculate factorials and inverse factorials
// till MAX_FACT in O(MAX_FACT + log MOD)
// Requirements: MOD is prime

vector<int> fact, inv_fact;
void precalculate_factorials(int MAX_FACT) {
    fact.resize(MAX_FACT + 1);
    inv_fact.resize(MAX_FACT + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAX_FACT; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    inv_fact[MAX_FACT] = mod_inv(fact[MAX_FACT]);
    for (int i = MAX_FACT - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}

// Function to calculate nPr in O(1)
// Requirements: precalculate_factorials() must have been run
// Limits: n -> [0, MAX_N], r -> [0, INT64_MAX]

int nPr_mod(int n, int r) {
    return (n < r) ? 0 : (fact[n] * inv_fact[n - r]) % MOD;
}

// Function to calculate nCr in O(1)
// Requirements: precalculate_factorials() must have been run
// Limits: n -> [0, MAX_N], r -> [0, INT64_MAX]

int nCr_mod(int n, int r) {
    return (n < r) ? 0 : (nPr_mod(n, r) * inv_fact[r]) % MOD;
}
