#include <bits/stdc++.h>
using namespace std;

struct RMQ {
    vector<long long> a;
    vector<vector<long long>> sparseMax, sparseMin,sparseGcd;
    int n;
    RMQ(vector<long long> arr) {
        a = arr;
        n = arr.size();
        sparseMax.resize(n);
        sparseMin.resize(n);
        sparseGcd.resize(n);

        for (int i = 0; i < n; i++) {
            sparseMax[i].resize(__lg(n) + 1);
            sparseMax[i][0] = a[i];

            sparseMin[i].resize(__lg(n) + 1);
            sparseMin[i][0] = a[i];

            sparseGcd[i].resize(__lg(n) + 1);
            sparseGcd[i][0] = a[i];
        }

        for (int len = 1; len < __lg(n) + 1; len++) {
            for (int i = 0; i + (1 << (len - 1)) < n; i++) {
                sparseMax[i][len] = max(sparseMax[i][len - 1], sparseMax[(1 << (len - 1)) + i][len - 1]);
                sparseMin[i][len] = min(sparseMin[i][len - 1], sparseMin[(1 << (len - 1)) + i][len - 1]);
                sparseGcd[i][len] = min(sparseGcd[i][len - 1], sparseGcd[(1 << (len - 1)) + i][len - 1]);
            }
        }
    }

    long long  queryMax(long long  l, long long  r) {
        long long  k = __lg(r - l + 1);
        return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
    }

    long long  queryMin(long long  l, long long  r) {
        long long  k = __lg(r - l + 1);
        return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
    }

    long long  queryGcd(long long  l, long long  r) {
        long long  k = __lg(r - l + 1);
        return min(sparseGcd[l][k], sparseGcd[r - (1 << k) + 1][k]);
    }
    // find Max, Min, Gcd
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;

    vector<long long> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    RMQ rmq(a);

    long long res = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        res = max(res, rmq.queryGcd(i, i + k -1));
    }
    cout << res;

    return 0;
}