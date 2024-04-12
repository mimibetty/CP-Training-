#include <bits/stdc++.h>
using namespace std;

int a[200005];

struct RMQ {
    vector<long long> a;
    vector<vector<long long>> sparseMax, sparseMin;
    int n;
    RMQ(vector<long long> arr) {
        a = arr;
        n = arr.size();
        sparseMax.resize(n);
        sparseMin.resize(n);
        for (int i = 0; i < n; i++) {
            sparseMax[i].resize(__lg(n) + 1);
            sparseMax[i][0] = a[i];

            sparseMin[i].resize(__lg(n) + 1);
            sparseMin[i][0] = a[i];
        }

        for (int len = 1; len < __lg(n) + 1; len++) {
            for (int i = 0; i + (1 << (len - 1)) < n; i++) {
                sparseMax[i][len] = max(sparseMax[i][len - 1], sparseMax[(1 << (len - 1)) + i][len - 1]);
                sparseMin[i][len] = min(sparseMin[i][len - 1], sparseMin[(1 << (len - 1)) + i][len - 1]);
            }
        }
    }

    long long queryMax(int l, int r) {
        long long k = __lg(r - l + 1);
        return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
    }

    long long queryMin(int l, int r) {
        long long k = __lg(r - l + 1);
        return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
    }

    // find Max, Min, Gcd
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long maxval = -1e18;
    int n,l,r;
    cin >> n >> l >> r;

    vector<long long>b(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    
    RMQ rmq(b);
    for (int i = 0; i <= n - l; i++) {
    	long long sum = rmq.queryMax(i + l, min(i + r, n) ) - b[i];
    	maxval = max(maxval, sum );
    }
    cout << maxval;
    return 0;
}