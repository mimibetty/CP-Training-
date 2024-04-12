#include <bits/stdc++.h>
using namespace std;

struct RMQ {
    vector<int> a;
    vector<vector<int>> sparseMax, sparseMin;
    int n;
    RMQ(vector<int> arr) {
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

    int queryMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
    }

    int queryMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
    }

    // find Max, Min, Gcd
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    long long res = 0;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    RMQ rmq(a);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (rmq.queryMax(i,j) - rmq.queryMin(i,j) == k) res++;
        }
    }
    cout << res;

    return 0;
}