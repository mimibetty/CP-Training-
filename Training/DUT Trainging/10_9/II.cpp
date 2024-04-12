/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
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

long long MOD;
struct matrix{
    long long a[3][3];

    matrix() {
        memset(a, 0, sizeof(a));
    } 


    matrix operator *(const matrix& b) {
        matrix x;

        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= 2; j++) {
                for (int k = 1; k <= 2; k++) {
                    x.a[i][j] = (x.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
                }
            }
        }
        return x;
    }
    matrix operator +(const matrix& b) {
        matrix x;
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= 2; j++) {
                x.a[i][j] += b.a[i][j] + a[i][j];
                x.a[i][j] %= MOD;
            }
        }
        return x;
    }

};


matrix donvi;
matrix pw(const matrix& A, long long c) {
    if (c == 0) return donvi;
    if (c == 1) return A;
    
    matrix q = pw(A,c/2);
    // cout << q.a[1][1] << ' ' << q.a[2][1] << endl;
    
    if (c % 2 == 0) return q * q;
    else return q * q * (A);
}

matrix A; 
matrix base;

void solve() {
    long long n;
    cin >> n;
    MOD = n;
    if (n == 2) {
        cout << 3 << endl;
        return;
    }
    if (n == 5) {
        cout << 20 << endl;
        return;
    }
    vector<long long> res;
    if (n % 5 == 1 || n % 5 == 4) {
        long long ff = n-1;
        for (int i = 1; i <= sqrt(ff); i++) {
            if (ff % i == 0) {
                res.pb(i);
                res.pb(ff/i);
            }
        }
    }
    else {
        long long ff = 2*n + 2;
        for (int i = 1; i <= sqrt(ff); i++) {
            if (ff % i == 0) {
                res.pb(i);
                res.pb(ff/i);
            }
        }
    } 
    sort(All(res));
    base.a[1][1] = 1;
    base.a[2][1] = 0;

    donvi.a[2][2] = donvi.a[1][1] = 1;
    donvi.a[2][1] = donvi.a[1][2] = 0;
  
    A.a[1][1] = 1;
    A.a[1][2] = 1;
    A.a[2][1] = 1;
    A.a[2][2] = 0;

    for (auto i : res) {
        matrix dd = pw(A,i)*base;
        matrix dd1 = pw(A,i-1)*base;
        if (dd.a[1][1] == 1 && dd1.a[1][1] == 0) {
            cout << i <<endl;
            return;
        }
    }
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
    // cin >> t;
    while (t--)    
    solve();
    
    return 0;
}