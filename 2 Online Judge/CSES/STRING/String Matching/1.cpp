#include <bits/stdc++.h>
using namespace std;

// const long long BASE = 10042003;
// const long long MOD = 1e9 + 7;
// xóa BASE, MOD ở dòng 18 khi TLE

long long pw(long long a, long long n, long long MOD) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2, MOD);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

struct HashString {
    string str;
    vector<long long> prefixSum, inv;
    long long MOD, BASE;
    
    // constructor
    HashString(string str = "", long long BASE = 742003, long long MOD = 1e9 + 7): 
                                        str(str), MOD(MOD), BASE(BASE) {
        int n = str.size();
        prefixSum.resize(n + 1);
        inv.resize(n + 1);

        // calc inv
        long long invBase = pw(BASE, MOD - 2, MOD);
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            inv[i] = inv[i - 1] * invBase % MOD;
        }
        
        // calc prefixSum
        long long curPow = 1; // BASE ^ i
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = (prefixSum[i - 1] + curPow * str[i - 1] % MOD) % MOD;
            curPow = curPow * BASE % MOD;
        }
    }
   
    // return hash of str[l..r]
    long long query(int l, int r) {
        long long res = (prefixSum[r] - prefixSum[l - 1] + MOD) % MOD;
        res = res * inv[l] % MOD; // res /= pw(BASE, l)
        return res;
    }
};

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
        
    string s;
    cin >> s;
    string z;
    cin >> z;
    int n = s.size();
    int m = z.size();
    HashString hashS(s);
    HashString hashZ(z);

    int res = 0;
    long long x = hashZ.query(1,m);
    for (int i = 1; i <= n; i++) {
        if (i + m - 1 > n) break;
        if (1ll*hashS.query(i,i+m-1) == x) res++;
    }

    cout << res << endl;
    return 0;
}
