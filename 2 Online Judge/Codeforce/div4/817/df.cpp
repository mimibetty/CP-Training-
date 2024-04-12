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
long long a[300005];
bitset<10>bs1,bs2;

void solve() {
    int n;
    cin >> n;
    if (n == 3) {
        cout << "2 1 3" << endl;
        return;
    }

    if (n == 4) {
        cout << "2 1 3 0" << endl;
        return;
    }

    if (n == 5) {
        cout << "2 0 4 5 3" << endl;
        return;
    }

    long long limm = 100000000;
    long long tar = 1000000;
    long long x = 0;
    int d = 1;
    int z = n/2 + 1;

    long long f1 = 0,f2 =0;
    for (int i = 1; i <= n - 4; i++) {
        a[i] = i;
        if (i % 2 == 1) {
            f1 ^= a[i];
        }
        else {
            f2 ^= a[i];
        }
    }
    a[n-3] = tar;
    a[n-2] = tar+1;
    
    if (f1 == f2) {
        cout << endl;
        // cout <<"SAASDAS  " << f1 << ' ' << f2 <<endl;
    }
    f1 ^= limm;
    f2 ^= limm;
    a[n] = f1;
    a[n-1] = f2;

    if (n % 2 == 0) {
        swap(a[n],a[n-1]);
    }


    for (int i = 1; i <= n; i++) {
        cout << a[i] <<' ';
    }
    cout <<endl;

    bs1 = 0;
    for (int i = 1; i <= n; i+=2) {
        bs1 ^= a[i];
    }
    bs2 = 0;
    for (int i = 2; i <= n; i+=2) {
        bs2 ^= a[i];
    }
    cout << bs1 << ' ' << bs2 << endl;

    cout <<endl << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        // cout << "TTTT" << t <<endl;
        solve();
    }
    return 0;
}