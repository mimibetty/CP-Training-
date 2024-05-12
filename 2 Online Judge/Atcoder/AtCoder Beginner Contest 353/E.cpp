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

long long a[200005];
long long modd = 998244353;

long long sufS1[200005];
long long sufS2[200005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long n;
    cin >> n;
    for (int i=1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        long long x  = a[i];
        long long z = 1;
        while (x > 0) {
            z *= 10;
            x /= 10;
        }
        z /= 10;
        sufS2[i] = sufS2[i + 1] + z;
        sufS1[i] = sufS1[i + 1] + a[i];
    }

    long long res = 0;
    for (int i = 1; i < n; i++) {
        res = res + (a[i] *      (sufS2[i + 1] + sufS1[i + 1]) % modd) ;
        res %= modd; 
        cout << i << ' ' << sufS1[i+1] << ' ' << sufS2[i + 1] << endl;
        cout << i << ' ' <<  (a[i] * (sufS2[i + 1] + sufS1[i + 1])) << endl;
    }
    cout << res <<endl;
    return 0;
}