#include <bits/stdc++.h>
using namespace std;

struct BitDictCompact {
    typedef unsigned long long ull;
    static constexpr size_t BLOCK = sizeof(ull) * CHAR_BIT;

    size_t _size, _ones;
    vector<ull> data;
    vector<size_t> block_rank;
    BitDictCompact() {}
    BitDictCompact(const vector<bool> &bits) :
            _size(bits.size()),
            data((bits.size() + BLOCK - 1) / BLOCK),
            block_rank(data.size()) {
        size_t acc_rank = 0;
        for (int i = 0; i < bits.size(); i++) {
            size_t block_idx = i / BLOCK, bit_idx = i % BLOCK;
            data[block_idx] |= ull(bits[i]) << bit_idx;
            if (bit_idx == 0)
                block_rank[block_idx] = acc_rank;
            acc_rank += bits[i];
        }
        _ones = acc_rank;
    }
    size_t size() const {
        return _size;
    }
    // 0 <= idx <= N, return number of 1s in the range [0, idx)
    size_t rank(size_t idx) const {
        if (idx >= _size)
            return _ones;
        size_t block_idx = idx / BLOCK, bit_idx = idx % BLOCK;
        size_t ret = block_rank[block_idx];
        ull mask = (1ull << bit_idx) - 1;
        return block_rank[block_idx] + __builtin_popcountll(data[block_idx] & mask);
    }
};

template <typename T, int N = sizeof(T) * CHAR_BIT, typename BD = BitDictCompact>
struct WaveletArray {
    array<BD, N> bit_dict;
    static constexpr T max_value = N == sizeof(T) * CHAR_BIT ? numeric_limits<T>::max() : (T(1) << N) - 1;

    WaveletArray() {}
    WaveletArray(vector<T> data) {
        for (int lvl = N - 1; lvl >= 0; lvl--) {
            vector<bool> bits(data.size());
            for (size_t i = 0; i < data.size(); i++)
                bits[i] = (T(1) << lvl) & data[i];
            _build_level(bits, lvl);
            stable_partition(data.begin(), data.end(),
                [=](const T& x) { return ((T(1) << lvl) & x) == 0; });
        }
    }
    T range_kth(size_t left, size_t right, size_t k) {
        T ret = 0;
        for (int lvl = N - 1; lvl >= 0; lvl--) {
            const auto &bd = bit_dict[lvl];
            size_t zero_count = (right - bd.rank(right)) - (left - bd.rank(left));
            bool one = k >= zero_count;
            if (one)
                k -= zero_count;
            ret |= T(one) << lvl;
            left = _index_at_next_level(left, lvl, one);
            right = _index_at_next_level(right, lvl, one);
        }
        return ret;
    }
    size_t range_count(size_t left, size_t right, T val) {
        for (int lvl = N - 1; lvl >= 0; lvl--) {
            bool one = (val >> lvl) & 1;
            left = _index_at_next_level(left, lvl, one);
            right = _index_at_next_level(right, lvl, one);
        }
        return right - left;
    }
    size_t range_range_count(size_t left, size_t right, T low, T high) {
        if (low > high)
            return 0;
        return _range_range_count(left, right, low, high, N - 1);
    }
protected:
    void _build_level(const vector<bool> &bits,int lvl) {
        bit_dict[lvl] = BD(bits);
    }
    size_t _index_at_next_level(size_t idx, int lvl, bool one) {
        const BD &bd = bit_dict[lvl];
        if (!one)
            return idx - bd.rank(idx);
        else
            return bd.size() - bd.rank(bd.size()) + bd.rank(idx);
    }
    size_t _range_range_count(size_t left, size_t right, T low, T high, int lvl) {
        if (left >= right)
            return 0;
        if (high - low == (lvl == N - 1 ? max_value : (T(1) << (lvl + 1)) - 1))
            return right - left;
        T bit_mask = T(1) << lvl;
        if (bit_mask & (low ^ high)) {
            T split = ~(bit_mask - 1) & high;
            return _range_range_count(this->_index_at_next_level(left, lvl, false),
                                      this->_index_at_next_level(right, lvl, false),
                                      low, split - 1, lvl - 1)
                 + _range_range_count(this->_index_at_next_level(left, lvl, true),
                                      this->_index_at_next_level(right, lvl, true),
                                      split, high, lvl - 1);
        } else {
            bool branch = bit_mask & low;
            return _range_range_count(this->_index_at_next_level(left, lvl, branch),
                                      this->_index_at_next_level(right, lvl, branch),
                                      low, high, lvl - 1);
        }
    }
};

struct Point {
    int x, y;
};

int main(){
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (auto &p: pts) {
        int x, y;
        cin >> x >> y;
        p.x = x + y;
        p.y = x - y;
    }
    sort(pts.begin(), pts.end(), [](const Point &p, const Point &q) {
        return p.y < q.y;
    });
    vector<int> y_ord(n);
    for (int i = 0; i < n; i++) {
        y_ord[i] = pts[i].y;
        pts[i].y = i;
    }
    sort(pts.begin(), pts.end(), [](const Point &p, const Point &q) {
        return p.x < q.x;
    });
    vector<int> x_ord(n);
    for (int i = 0; i < n; i++) {
        x_ord[i] = pts[i].x;
        pts[i].x = i;
    }
    vector<uint32_t> data(n);
    for (int i = 0; i < n; i++)
        data[i] = pts[i].y;
    WaveletArray<uint32_t, 17> wavelet(data);
    int q;
    cin>>q;
    while (q--) {
        int a, b, k;
        cin >> a >> b >> k;
        int lo = -1, hi = 200000;
        while (hi - lo > 1) {
            int dist = (lo + hi) / 2;
            int l = a + b - dist, r = a + b + dist, d = a - b - dist, u = a - b + dist;
            l = lower_bound(x_ord.begin(), x_ord.end(), l) - x_ord.begin();
            r = upper_bound(x_ord.begin(), x_ord.end(), r) - x_ord.begin();
            d = lower_bound(y_ord.begin(), y_ord.end(), d) - y_ord.begin();
            u = upper_bound(y_ord.begin(), y_ord.end(), u) - y_ord.begin();
            int cnt = 0;
            if (u > 0) {
                cnt = wavelet.range_range_count(l, r, d, u - 1);
            }
            if (cnt >= k)
                hi = dist;
            else
                lo = dist;
        }
        cout << hi << '\n';
    }
}
