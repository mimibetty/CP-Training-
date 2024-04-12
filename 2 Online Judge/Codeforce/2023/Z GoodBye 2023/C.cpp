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

int a[100005];
void solve() {
    int n;
    cin >> n;
    ll s = 0;
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
        s += a[i];
        if (a[i] % 2 == 0 ) {
            even++;
        }
        else {
            odd++;
        }
        if (i == 1) {
            cout << s << " ";
            continue;
        }
        long long res = s;
        if (odd % 3 == 1) res--;
        res -= odd/3;
        cout <<res <<" ";
        // if (odd > 2) {
        //     cout << s - odd/3 << endl;
        // }
        // else cout << s << endl;
        // cout <<"Stt:" << i << "  " <<  even << ' ' << odd << ' ' << s << endl;
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
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}