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

void solve() {
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "no" << endl;
        return;
    }

    long long num = n*2;
    ll sum = (num+1)*num/2;
    ll sumxy = sum*2 / (n);
    ll x = (sumxy + n) / 2;
    ll y = sumxy - x;
    swap(x,y);
    // cout << x << ' ' << y;
    cout << "YES" << endl;

    int cuoi = y;
    int dau = n/2 + 2;
    int stt1 = dau+1;

    while (dau >= 1) {
        cout << cuoi << ' ' << dau << endl;
        cuoi--;
        dau--;
    }
    int stt2 = cuoi; 
    // cout << "SSD" << stt1 << ' ' << stt2 << endl;
    int sl = (stt2 - stt1)/2;
    for (int i = 0; i < sl; i++) {
        cout << stt1+i << ' ' << stt2 - sl + i + 1 << endl;
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}