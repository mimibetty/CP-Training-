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
    int n;
    cin >> n;
    if (n == 1) {
        cout <<1 <<endl << 1 << ' ' << 2 << endl;
        return;
    }
    // string r;
    // r += ' ';
    // string s = "BAN";
    // for (int i = 1; i <= n; i++) {
    //     r += s;
    // }
    cout << (n + 1)/2 << endl;
    int vt = 1;
    int x = 3*n;
    for (int i = 1; i <= (n + 1)/2; i++) {
        cout << vt << ' ' << x <<endl; 
        vt+=3;
        x -= 3;
    }
    
    // if (n % 2 == 1) {
    //     cout << n/2 * 3 + 1 << ' '<< n/2 * 3 + 3 << endl;
    // }    
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