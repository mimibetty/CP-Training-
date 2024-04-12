#include<bits/stdc++.h>
using namespace std;

const long long MOD = 987654321;

long long pw(long long a, long long n) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

long long fact[1000005];
// long long f[1000005];
map<int,int>d;
long long lagrange(vector<pair<long long,long long>> &f, long long n) {
    int k = 6;
    if (n <= 10) return d[n];
    
    long long tu = 1;
    for (int i = 0; i <= k; i++) {
        tu *= (n - f[i].first);
        tu %= MOD;
    }

    long long res = 0;
    for (int i = 0; i <= k; i++) {
        long long val = f[i].second;
        for (int j = 0; j <= k; j++) {
            if (j == i) continue;
            val = val * (n - f[j].first) % MOD;

            if (f[i].first - f[j].first < 0) {
                val *= -1;
                val = val * pw(f[j].first - f[i].first, MOD - 2) % MOD;
            }
            else {
                val = val * pw(f[i].first - f[j].first, MOD - 2) % MOD;
            }

            val = (val % MOD + MOD) % MOD;
        }
        res += val;
        res %= MOD;
    }
    return res;
}
// n < 100 m < 1000;
n * m <= 1e7
int a[100][1000];
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = 0;
        }
    }
    int n = 5;  // số hàng
    int m = 4;  // số cột

    // khai báo ma trận 2 chiều n*m
    vector<vector<int>> matrix(n, vector<int>(m));

    // int t;
    // cin >> t;

    
    // f[0] = 0;
    // for (int i = 1; i <= k + 1; i++) {
    //     f[i] = f[i - 1] + pw(i, k);
    //     f[i] %= MOD;
    // }

    // f[5] = 11;
    // f[6] = 25;
    // f[7] = 50;
    // f[8] = 91;
    // f[9] = 154;
    // f[10] = 246;
    // f[11] = 375;
    // f[12] = 550;
// hãy     vector<pair<long long, long long>> ff;
//     // ff.push_back({3,0});
//     ff.push_back({4,4});
//     ff.push_back({5,11});
//     ff.push_back({6,25});
//     ff.push_back({7,50});
//     ff.push_back({8,91});
//     ff.push_back({9,154});
//     ff.push_back({10,246});
//     d[3] = 0;
//     d[4] = 4;
//     d[5] = 11;
//     d[6] = 25;
//     d[7] = 50;
//     d[8] = 91;
//     d[9] = 154;
//     d[10] = 246;

//     long long n;
//     cin >> n;
//     cout <<lagrange(ff, n) << endl;
    return 0;
}