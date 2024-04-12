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
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

bool prime(long long n) {
    if (n < 2) return 0;
    long long d = sqrt(n);
    for (int i = 2; i <= d; i++) if (n % i == 0) return 0;
    return 1; 
}


void none(){
    cout << -1 << ' ' << -1 << ' ' << -1 << ' ' << -1 <<endl;
}
void solve(long long n) {
    bool ok = 0;

    if (n < 8) {
        none();
        return;
    }    

    long long a,b,c,d;
    long long sum1 ,sum2;
    for (long long i = n - 1; i >= 1; i--) {
        sum1 = i;
        sum2 = n - sum1;

        for (long long j = sum1 -1; j >= 1; j--) {
            if (prime(j) == 1 && prime(sum1 - j) == 1) {
                a = j;
                b = sum1 - j;
                break;
            }
        }       

        for (long long j = sum2 - 1; j >= 1; j--) {
            if (prime(j) == 1 && prime(sum2 - j) == 1) {
                c = j;
                d = sum2 - j;
                break;
            }

        }       

        if (prime(a) && prime(b) && prime(c) && prime(d) && a + b + c + d == n) {
            cout << a << ' ' << b << ' ' << c << ' ' << d <<endl;
            return;
        }

    }
    none();
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    for (int z = 1; z <= tt; z++) {
        long long n;
        cin >> n;
            // cout << n <<endl;
        // cout << z << ' ';      
         solve(n);
    }
    return 0;
}