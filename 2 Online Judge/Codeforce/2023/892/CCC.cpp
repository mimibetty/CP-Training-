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

ll a[2000];
void solve() {
    int n;
    cin >> n;
    // int z = n/2;
    // if (n % 2 == 0) {
    //     for (int i = 1; i <= n/2; i++) {
    //         a[i] = i;
    //     }
    //     z = n;
    //     for (int i = n/2 + 1 ; i <= n; i++) {
    //         a[i] = z;
    //         z--;
    //     }
    // }
    // else {
    //     for (int i = 1; i <= (n)/2; i++) {
    //         a[i] = i;
    //     }
    //     z = n;
    //     for (int i = (n)/2 + 1 ; i <= n; i++) {
    //         a[i] = z;
    //         z--;
    //     }   
    // }
    ll res = 0;
    for (int i = 0; i <= n; i++) {
        ll sum = 0;
        ll mx = 0;
        for (int j = 1; j <= i; j ++) {
            a[j] = j;
        }
        ll z = n;
        for (int j = i + 1; j <= n; j++) {
            a[j] = z;
            z--;
        }
        for (int j = 1; j <= n; j++) {
            sum += j*a[j];
            mx= max(mx, 1ll*j*a[j]);
        }
        sum -= mx;
        res = max(res, sum);

    }



    cout << res <<endl;
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
    while (t--)     solve();
    
    return 0;
}