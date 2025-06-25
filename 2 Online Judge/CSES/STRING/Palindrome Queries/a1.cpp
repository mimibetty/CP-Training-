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

long long a[1005];
long long bcnn(long long a, long long b) {
    long long gcd = __gcd(a, b);
    return (a / gcd) * b;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // cout << a[i] << endl;
    }
//   a1 = 2   a2 = 5 a3 = 7 a4 a5 a6 a7 a8 a9=53 a10 = 2^3 * 5^2 * 7^1
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
        sort(a + 1, a + i + 1);
        for (int j = i-1; j >= 1; j--) {
            long long a_old = a[j];
            long long b_old = a[i]; // bigger 
            long long a_new = __gcd(a[j], a[i]);
            long long b_new = bcnn(a[j], a[i]); 
            if (b_new > b_old) {
                a[j] = a_new;
                a[i] = b_new;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
}

int main() {
    if(fopen("CHANGE.INP", "r")) {
        freopen("CHANGE.INP","r",stdin);
        freopen("CHANGE.OUT","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--)    
    solve();

    return 0;
}


a*3 + b*2 + c = 10
a = 0 
0 + 2b + c = 10 => b = (0,5) => res += 6

a = 1 
3 + 2b + c = 10
b = ->b =  (0,3) =>res += 4  

a = 2 
 res+=2 

a= 3 res += 2
 