// 1-based indexing is used for this implementation
// do not use update() at (x, 0) or (0, y)
struct fenwick_tree_2D {
    int n, m;
    vector<vector<int>> tree;
    fenwick_tree_2D(int _n, int _m)
        : n(_n), m(_m), tree(_n + 5, vector<int>(_m + 5, 0)) {}
    void update(int x, int y, int v) {
        for (int i = x; i <= n; i += i & (-i))
            for (int j = y; j <= m; j += j & (-j))
                tree[i][j] += v;
    }
    int prefix_sum(int x, int y) {
        int r = 0;
        for (int i = x; i > 0; i -= i & (-i))
            for (int j = y; j > 0; j -= j & (-j))
                r += tree[i][j];
        return r;
    }
    int range_sum(int x1, int y1, int x2, int y2) {
        return prefix_sum(x2, y2) - prefix_sum(x2, y1 - 1) -
               prefix_sum(x1 - 1, y2) + prefix_sum(x1 - 1, y1 - 1);
    }
};