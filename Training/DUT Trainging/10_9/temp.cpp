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
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const long double PI = acos(-1);
const long long MOD = 89;
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}


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

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n; 
    cin >> n ;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    base.a[1][1] = 1;
    base.a[2][1] = 0;

    donvi.a[2][2] = donvi.a[1][1] = 1;
    donvi.a[2][1] = donvi.a[1][2] = 0;
  
    A.a[1][1] = 1;
    A.a[1][2] = 1;
    A.a[2][1] = 1;
    A.a[2][2] = 0;
   
    // matrix dd = pw(A,n-1)*base;
    matrix dd = pw(A,44)*base;
    cout << dd.a[1][1] << endl;

    matrix dd1 = pw(A,43)*base;
    cout << dd1.a[1][1] << endl;
    matrix dd2 = pw(A,42)*base;
    cout << dd2.a[1][1] << endl;
    
    // cout << base.a[1][1] << ' ' << base.a[2][1] << endl;
    return 0;
}