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

long long a[300005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    long long res = 1e10;;
    for (int i = 1; i <= n; i++) {
        ll maxx = 0, minn = 1e10;
        int midd = (n + 1) / 2;
        for (int j = 1; j <= (n+1) / 2; j++) {
            ll sum = 0;
            int l = j, r = n - j + 1;

            if (l >= i || r <= i) {
                if (l >= i) {
                    l++;
                }
                else if (r <= i) { 
                    r--;
                }
            }

            sum = a[l] + a[r];
            maxx = max(maxx, sum);
            minn = min(minn, sum);
            // cout << i << ' ' << j << ' ' << l << ' ' << r << ' ' << sum << endl;
        }   
        res = min(res, maxx - minn);
        // cout <<i << ' ' <<  maxx << ' ' << minn  << endl;
    }
    cout << res << endl;
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
    while (t--)    
    solve();
    
    return 0;
}