//1-based indexing is used for this implementation
//do not use update() at x = 0
//lower_bound returns inf when no suitable position exists
struct fenwick_tree_1D {
    int n, log_n;
    vector<int> tree;
    fenwick_tree_1D(int _n) : n(_n), log_n((int)(log2(_n) + 1.0L)), tree(_n + 5) {}
    void update(int x, int v)
    {
        while(x <= n)
        {
            tree[x] += v;
            x += x & (-x);
        }
    }
    int prefix_sum(int x)
    {
        int r = 0;
        while(x)
        {
            r += tree[x];
            x -= x & (-x);
        }
        return r;
    }
    int range_sum(int l, int r)
    {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
    int lower_bound(int v)
    {
        int b = 0, s = 0;
        for(int i = log_n; i >= 0; i--)
            if((b | (1LL << i)) <= n && s + tree[b | (1LL << i)] < v)
                s += tree[b | (1LL << i)], b |= (1LL << i);
        return (b != n) ? (b + 1) : inf;
    }
};