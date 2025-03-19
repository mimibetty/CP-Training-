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
    
    // constructor khởi tạo 1 struct thì nó sẽ thực hiện hàm đấy khi vừa khởi tạo struct
    HashString(string str = "", long long BASE = 10042003, long long MOD = 1e9 + 7): 
                                        str(str), MOD(MOD), BASE(BASE) {
        int n = str.size();
        prefixSum.resize(n + 1);
        inv.resize(n + 1);

        // calc inv
        long long invBase = pw(BASE, MOD - 2, MOD); // * base^-1
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            inv[i] = inv[i - 1] * invBase % MOD; // inv[i] = 1/(base^i) = *base^(-i)
        }
        
        // calc prefixSum = sum s[i] * 10^i
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
        res = (res%MOD + MOD) %MOD;
        return res;
    }
};
// s = abcdefg
// substring (l,r) (3,4) = de = ps[4] - ps[3-1=2] = a[3]*base^3 + a[4]*base^4  (1)
// d(0)e(1) = d*base^0 + e*base^1   (2)
//  (a[3]*base^3 + a[4]*base^4 ) /base^l(3)   =>   d*base^0 + e*base^1
// hash(i,j) = substring(i,j) => hash


int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
        
    string s = "ababcdefg";
    s = ' ' + s;
    // cin >> s;
    
    HashString hash1(s, 123425, 1e9 + 7);

    string s2 = "sddabcg";
    s2 = ' ' + s2;
    HashString hash2(s2, 123425, 1e9 + 7);

    for (int i = 1; i < s.size();i++) cout << i << ' ' << s[i] << ' ' << hash1.query(i,i) << endl;;
    for (int i = 1; i < s2.size();i++) cout << i << ' ' << s2[i] << ' ' << hash2.query(i,i) << endl;;
    cout << hash1.query(3,5)  << ' ' << hash2.query(4,6);

    // vector<HashString> hash(n + 1, HashString(""));
    // for (int i = 1; i <= n; i++) {
    //     string s;
    //     cin >> s;
    //     hash[i] = HashString(s);
    // }

    return 0;
}