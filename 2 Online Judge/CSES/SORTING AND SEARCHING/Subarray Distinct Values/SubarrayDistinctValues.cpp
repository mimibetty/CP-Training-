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
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<int>s;
    map<int,int>d;
    long long res = 0;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        while (s.size() <= k && r <= n) {
            if (k == s.size() && d[a[r]] == 0) break;
            r++;
            d[a[r]]++;
            if (d[a[r]] == 1) {
                s.insert(a[r]);
            }
        }  
   
        res += r-i;
        d[a[i]]--;
        if (d[a[i]] == 0) {
            s.erase(a[i]);
        }
        // cout << i << ' ' << r <<endl;
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
    
    solve();
    
    return 0;
}