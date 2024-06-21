#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

class FenwickTree {
public:
    FenwickTree(int size) : size(size), tree(size + 1, 0) {}

    void update(int index, long long value) {
        while (index <= size) {
            tree[index] = (tree[index] + value) % MOD;
            index += index & -index;
        }
    }

    long long query(int index) {
        long long result = 0;
        while (index > 0) {
            result = (result + tree[index]) % MOD;
            index -= index & -index;
        }
        return result;
    }

    long long range_query(int left, int right) {
        return (query(right) - query(left - 1) + MOD) % MOD;
    }

private:
    int size;
    vector<long long> tree;
};

long long sum_of_squares(int m) {
    long long m1 = m, m2 = m + 1, m3 = 2 * m + 1;
    m1 = (m1 * m2) % MOD;
    m1 = (m1 * m3) % MOD;
    long long inv6 = 166666668; // Modular inverse of 6 under MOD
    return (m1 * inv6) % MOD;
}

int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    FenwickTree fenwick(n);

    for (int i = 0; i < q; ++i) {
        int type_op;
        cin >> type_op;

        if (type_op == 1) {
            int x, m;
            cin >> x >> m;

            // Calculate the total grains to be distributed
            long long total_grains = sum_of_squares(m);

            // Distribute grains in a circular manner
            int start = x;
            int end = (x + m - 1) % n;
            if (end >= start) {
                fenwick.update(start, total_grains);
                if (end + 1 <= n)
                    fenwick.update(end + 1, -total_grains);
            } else {
                // Case where the distribution wraps around the end of the array
                fenwick.update(start, total_grains);
                if (end + 1 <= n)
                    fenwick.update(end + 1, -total_grains);
                fenwick.update(1, total_grains);
                if (end + 1 <= n)
                    fenwick.update(end + 1, -total_grains);
            }
        } else if (type_op == 2) {
            int i, j;
            cin >> i >> j;
            cout << fenwick.range_query(i, j) << "\n";
        }
    }

    return 0;
}