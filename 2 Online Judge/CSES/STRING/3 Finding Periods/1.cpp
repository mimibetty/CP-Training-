#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a

const long long BASE = 742003;
const long long MOD = 1e9 + 7;

long long pw(long long a, long long n) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

struct HashString{
    string str;
    vector<long long>prefixSum, inv;

    HashString(string str = ""):
                str(str){
        
        int n = str.size();
        prefixSum.resize(n+1);
        inv.resize(n+1);
        
        // calc inv
        inv[0] = 1;
        long long invBase = pw(BASE,MOD - 2);
        for (int i = 1; i <= n; i++) {
            inv[i] = inv[i-1] * invBase % MOD; 
        }

        // calc prefixSum
        long long CurPow = 1; // curpow = base^i
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = (prefixSum[i-1] + CurPow * str[i-1] % MOD) % MOD;
            CurPow = CurPow * BASE % MOD;
        }

    } 
    // return hash of str[l...r]
    long long query(int l, int r) {
        long long res = (prefixSum[r] - prefixSum[l-1] + MOD) % MOD;
        res = res * inv[l] % MOD;
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
    int n = s.size();
    vector<int>res;

    HashString hash(s);
    for (int i = 1; i <= n; i++) {
        bool ok = 1;
        for (int j = 1; j < (n/i); j++) {
            if (hash.query(i*j+1, i*j + i) != hash.query(1,i)) {
                ok = 0; 
                break;
            } 
        }

        if (n % i != 0) {
            int x = n%i;
            if (hash.query(n-x+1, n) != hash.query(1,x)) {
                ok = 0;
            } 
        }

        if (ok) res.pb(i);
    }
    // cout << "LIST \n";
    for (auto i : res) cout << i << " ";
    return 0;
}

    