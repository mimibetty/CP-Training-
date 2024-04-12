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


ll a[100005];
ll b[100005];
ll c[100005];
ll k[100005];

void solve() {
    int n,m;
    cin >> n >> m;
    // cout << "KKK  ";
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    sort(k+1, k + 1 + n);
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }



    for (int i = 1; i <= m; i++) {
        int left = 1;
        int right = n;
        int mid;
        for (int j = 0; j < 300; j++) {
            mid = (left + right)/2;
            if (k[mid] > b[i]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        bool ok = 0;
        ll res = 0;
        ll tmp = 0;
        for (int q = -4; q <= 4; q++) {
            if (left + q > 0 && left + q <= n) {           
                tmp = (b[i] - k[left + q])*(b[i] - k[left + q]) - 4*a[i]*c[i];
                if (tmp < 0) {
                    ok = 1;
                    res = k[left+q];
                    cout <<"yes" <<endl;

                    // cout <<"yes1  " << tmp << endl;
                    cout <<res <<endl;
                    break;
                }
            }
        }
        
        if (ok == 0) cout << "no" << endl;
    } 

    cout << endl;
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
    while(t--) solve();
    return 0;
}
