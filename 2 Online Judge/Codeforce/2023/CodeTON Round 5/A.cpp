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
ll a[100];

ll b[100];

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
        ll n,m;
        cin >> n >> m;
        ll sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum1 += a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            sum2 += b[i];
        }
        if (sum1 > sum2) {
            cout << "Tsondu" << endl;
               
        }
        else if (sum1 < sum2) {
            cout << "Tenzing" << endl;
        }
        else cout << "Draw" << endl;
    }
    return 0;
}