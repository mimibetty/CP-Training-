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

ll a[100005], ps[100005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    for (int i = 1; i<= n; i++) 
        ps[i] = ps[i-1] + a[i];

    int t;
    cin >> t;
    for (int z = 1;  z <= t; z++) {
        ll k;
        cin >> k;
        int l = 1, r = n;
        int mid;
        while (l < r) {
            mid = (l + r + 1)/2;
            if (k < a[mid]) {   
                r = mid-1;
            }
            else l = mid;
            // cout << l << ' ' << r << ' ' << a[mid] <<endl;
        }
        while (a[l] < k && l < n) {
            l++;
        } 
        if (a[l] <= k && l == n) {
            cout << 0 << endl;
            continue;
        }
        ll s = ps[n] - ps[l-1];
        s -= k*(n-l+1);
        cout << s << endl;
        // cout << l << ' ' << a[l] << endl << endl;
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
       
    solve();
    
    return 0;
}