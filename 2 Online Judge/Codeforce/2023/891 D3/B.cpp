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

int a[200005];
void solve() {
    
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        a[i+1] = s[i] - 48;
    }
    int vt = n+1;
    for (int i = n; i>= 1; i--) {
        if (a[i] == 10) {
            a[i-1]++;
            a[i] = 0;
            vt = i;
        }
        if (a[i] >= 5) {
            a[i-1]++;
            a[i] = 0;
            vt = i;
        }

    }
    for (int i = vt; i <= n; i++) {
        a[i] = 0;
    }
    if (a[0] > 0) cout << a[0];
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
    for (int i = 0; i <= n;i++) {
        a[i] = 0;
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
    while (t--)   
    solve();
    
    return 0;
}