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
int vt[200005];
void solve() {
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vt[a[i]] = i;
    }

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (vt[i] > vt[i+1]) cnt++;
    } 
    for (int z = 1; z <= t; z++) {
        int l,r;
        cin >> l >> r;
        cout <<cnt+1 << endl;
        if (vt[a[l] - 1] > vt[a[l]]) {
            cnt--;
        }
        if (vt[a[l]] > vt[a[l] + 1]) {
            cnt--;
        }
        if (vt[a[r]] > vt[a[r] + 1]) {
            cnt--;
        }
        if (vt[a[r] - 1] > vt[a[r]]) {
            cnt--;
        }
        cout <<cnt+1 << endl;
        vt[a[l]] = r;
        vt[a[r]] = l;
        swap(a[l], a[r]);
        if (vt[a[l]] > vt[a[l] + 1]) {
            cnt++;
        }
        if (vt[a[l] - 1] > vt[a[l]]) {
            cnt++;
        }
        if (vt[a[r]] > vt[a[r] + 1]) {
            cnt++;
        }
        if (vt[a[r] - 1] > vt[a[r]]) {
            cnt++;
        }
        cout <<cnt+1 << endl;
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        EL;EL;
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