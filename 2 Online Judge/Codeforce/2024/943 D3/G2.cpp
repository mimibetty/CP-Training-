/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}


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
    HashString(string str = "", long long BASE = 10042003, long long MOD = 1e9 + 7): 
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
        return res;
    }
};



int n,lr,rr;
string s;
void solve() {
    cin >> n >> lr >> rr;
    cin >>s;

    HashString hash(s, 4599, 1e9 + 9);
    
    // check L 
    bool ok = 0;
    int cnt = 0;
    long long z = hash.query(1, lr);
    for (int i = 1; i <= n - lr + 1; i++) {
        long long tmp = hash.query(i, i + lr - 1);
        // cout <<i << ' ' << i + lr - 1 << ' ' <<  z << ' ' << tmp << endl;
        if (tmp == z) {
            cnt++;
            i = i + lr - 1;   
            // cout << "con " << i << endl;
        }
        // cout << "cnt " << cnt << endl;
    }
    cout << cnt << endl;    

    // vector<int>res;
    // int pos = l; 
    // int l = 0, r = n;
    // while (l < r) {
        
    //     int mid = (l + r + 1) / 2;
    //     // cout << "check " << mid << endl;
    //     bool ok = 0;
    //     int cnt = 0;
    //     long long z = hash.query(1, mid);
    //     for (int i = 1; i <= n - mid + 1; i++) {
    //         long long tmp = hash.query(i, i + mid - 1);
    //         // cout <<i << ' ' << i + mid - 1 << ' ' <<  z << ' ' << tmp << endl;
    //         if (tmp == z) {
    //             cnt++;
    //             i = i + mid - 1;   
    //             // cout << "con " << i << endl;
    //         }
    //         // cout << "cnt " << cnt << endl;
    //     }
    //     if (cnt >= lr) {
    //         l = mid;
    //     }
    //     else {
    //         r = mid - 1;
    //     }
    //     // cout << l << ' ' << r << ' ' << ok << endl;
    // }
    // cout << l << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
  cin >> t;
    while (t--)    
    solve();
    
     return 0;
}