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

const long long modd = 1e9 + 7;
int cnt_Div(long long x) {
    ll f = 0;
    for (long long i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) f+=2;
    }

    ll z = sqrt(x);
    if (z * z == x) f--;

    return f;
}
bool snt(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long n,k;
    cin >> n >> k;

    if (k >= n && snt(k) == 1) {
        cout << 0 << endl;
        return 0;
    }
    long long x = 1; 
    for (int i = 1; i <= n; i++) {
        x *= i;
    }   

    ll res = 0;
    for (int i = 1; i <= x; i++) {
        if (cnt_Div(i) == k) {
            res++;
        }
    }
    cout << res <<endl;
    return 0;
}